#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

int main() {
    int fd;
    char buffer[100];

    fd = open("test.txt", O_CREAT | O_RDWR, 0644);

    write(fd, "Hello Operating System", 22);
    close(fd);

    fd = open("test.txt", O_RDONLY);
    read(fd, buffer, 22);
    buffer[22] = '\0';

    printf("Data in file: %s\n", buffer);

    close(fd);
    return 0;
}