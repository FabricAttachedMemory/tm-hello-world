/* © 2017, Keith Packard. GPL, v3 or later */
#include "hello-world.h"

int me, them;

void *send(void *arg) {
	struct message *m = arg;

	for (;;) {
		while (fam_atomic_32_read(&m[me].state) != IDLE)
			sleep(1);
		if (!fgets(m[me].text, sizeof(m[me].text), stdin))
			exit(0);
		pmem_persist(m[me].text, sizeof(m[me].text));
		fam_atomic_32_write(&m[me].state, READY);
	}
}

void *recv(void *arg) {
	struct message *m = arg;

	for (;;) {
		while (fam_atomic_32_read(&m[them].state) == IDLE)
			sleep(1);
		pmem_invalidate(&m[them].text, sizeof (&m[them].text));
		printf("\t\t\t\t%s", m[them].text);
		fam_atomic_32_write(&m[them].state, IDLE);
	}
}

int main(int argc, char **argv) {
	if (argc != 4) { printf("usage: %s <file> <me> <them>\n", argv[0]); exit(1); }
	me = atoi(argv[2]);
	them = atoi(argv[3]);
	int	fd = open(argv[1], O_CREAT|O_RDWR, 0666);
	ftruncate(fd, SIZE);
	struct message	*m = mmap(0, SIZE, PROT_READ|PROT_WRITE, MAP_SHARED, fd, 0);
	fam_atomic_register_region(m, SIZE, fd, 0);
	pthread_t	recv_thread;
	pthread_create(&recv_thread, NULL, recv, m);
	send(m);
}
