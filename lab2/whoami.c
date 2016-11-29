#define __LIBRARY__
#include <unistd.h>
#include <string.h>
#include <errno.h>
#include <stdio.h>
_syscall2(int, whoami, char*, name, unsigned int, size)

int main() {
	int cnt;
	char buf[128] = {0};

	cnt = whoami(buf, 128);
	if (cnt < 0) {
		printf("whoami: name too long!\n");
		return -1;
	} else {
		buf[cnt] = 0;
		printf("%s\n", buf);
	}
	return 0;
}
