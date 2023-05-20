#include "main.h"

int main(int ac, char** argv, char** env) {

    char *s = _getenv1("PATH");

    printf("%s\n", s);
    return (0);
}
