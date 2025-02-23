#include <stdio.h>
#include <fcntl.h>

#define BSIZE 1024
//same as mv but without deleting the source
int main(int argc, char *argv[]) {

    if(argc != 3) {
        printf("Usage: %s <source> <destination>\n", argv[0]);
        return -1;
    }
    int source = open(argv[1], O_RDONLY);
    if(source == -1) {
        printf("Error opening source file\n");
        return -1;
    }
    int destination = open(argv[2], O_WRONLY | O_CREAT | O_TRUNC, 0644);
    if(destination == -1) {
        printf("Error opening destination file\n");
        return -2;
    }

    char buffer[BSIZE];
    int bytes_read;
    
    //use fread to read from source and fwrite to write to destination
    while((bytes_read = read(source, buffer, BSIZE)) > 0) {
        write(destination, buffer, bytes_read);
    }

    if(bytes_read != 0) {
        printf("Error reading from source file\n");
        return -3;
    }

    return 0;
}