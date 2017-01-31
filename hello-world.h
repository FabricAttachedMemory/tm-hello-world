/* © 2017, Keith Packard. GPL, v3 or later */
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/mman.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <fcntl.h>
#include <signal.h>
#include <pthread.h>
#include <libpmem.h>
#include <fam_atomic.h>

#define NMESSAGE	32
#define SIZE		(NMESSAGE * sizeof (struct message))

#define IDLE	0
#define READY	1

struct message {
	int32_t	state __attribute__ ((aligned(64)));
	char text[1024] __attribute__ ((aligned(64)));
};

