/* © 2017, Keith Packard. GPL, v3 or later */
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/mman.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <signal.h>
#include <pthread.h>

#define NMESSAGE	32
#define SIZE		(NMESSAGE * sizeof (struct message))

struct message {
	enum { IDLE, READY } state;
	char text[1024];
};

