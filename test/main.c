#include "main.h"

int main(int ac, char** argv, char** env) {

    char *s = _which("/bin/ls -l");

    printf("%s\n", s);
    return (0);
}
