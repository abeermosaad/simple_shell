#include "main.h"

int main(int ac, char** argv, char** env) {
    // char* c = _getenv("PATH");
    // printf("%s\n", c);
    // char *s = getenv("PATH");
    // printf("%s", s);
    
    char *s = _which("ls");
    printf("%s\n", s);
    return (0);
}
