#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>

struct database_header_t {
    unsigned short version;
    unsigned short employees;
    unsigned int file_size;
};

int main(int argc, char *argv[]) {
    struct database_header_t head = {1, 0, sizeof(struct database_header_t)};

    if (argc != 2) {
        fprintf(stderr, "Usage: %s <filename>\n", argv[0]);
        return 1;
    }

    int fd = open(argv[1], O_RDWR | O_CREAT, 0644);
    if (fd == -1) {
        perror("open");
        return -1;
    }

    ssize_t read_bytes = read(fd, &head, sizeof(head));
    if (read_bytes == 0) {
        // File is empty, initialize header
        printf("Initializing new database file...\n");
        if (write(fd, &head, sizeof(head)) != sizeof(head)) {
            perror("write");
            close(fd);
            return -1;
        }
    } else if (read_bytes != sizeof(head)) {
        fprintf(stderr, "Incomplete read. Expected %lu bytes, got %ld\n",
                sizeof(head), read_bytes);
        close(fd);
        return -1;
    }

    printf("DB Version: %u\n", head.version);
    printf("DB Number of Employees: %u\n", head.employees);
    printf("DB Size: %u\n", head.file_size);

    close(fd);
    return 0;
}
