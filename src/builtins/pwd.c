#include <unistd.h>
#include <stdio.h>
int main(int argc, char *argv[]) {
    char *path = getcwd(NULL, 0);
    printf("%s\n", path);
    return 0;
}