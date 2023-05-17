#include "main.h"

int main() {

    char **s = {NULL};
	char *argv[] = {"ls", "-l", NULL};
	execve("/bin/ls", argv, s);

    return (0);
}
