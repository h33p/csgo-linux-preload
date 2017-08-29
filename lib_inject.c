#define _GNU_SOURCE
#include <stdlib.h>
#include <stdio.h>
#include <dlfcn.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <errno.h>
#include <sys/stat.h>

static int count;

static int (*real_connect)(int sockfd, const struct sockaddr *addrm, socklen_t addrlen) = NULL;
static void Inject(void);

int connect(int sockfd, const struct sockaddr *addr, socklen_t addrlen)
{
	count++;
	if (count == 7)
		Inject();
	real_connect = dlsym(RTLD_NEXT, "connect");
	return real_connect(sockfd, addr, addrlen);
}

static void Inject(void)
{
	struct stat ds;
	int statv = stat("/tmp/dumps", &ds);
	if (statv == ENOENT || ds.st_uid != 0) {
		return;
	}
	void *handle;
	handle = dlopen ("/tmp/libCheeto.so", 1);
	if (!handle) {
		fputs (dlerror(), stderr);
	}
}

void __attribute__((constructor)) Construct()
{
	count = 0;
}

void __attribute__((destructor)) Destruct()
{
}
