#include <stdio.h>

extern char **environ;

int main(int ac, char **av, char **env) {
    char **environment = environ;

	printf("%p\n", &(*environment));//*env = aray of strings
	printf("%p\n", &(*env));//*env = aray of strings

    return 0;
}
