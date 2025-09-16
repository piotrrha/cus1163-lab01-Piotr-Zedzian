#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>
#include "file_operations.h"

int create_and_write_file(const char *filename, const char *content) {
    // TODO: Declare an integer 'fd' for the file descriptor.
    int fd;
    
    // TODO: Declare a variable 'bytes_written' of type ssize_t to store how many bytes are written.
    ssize_t bytes_written;

    // TODO: Print a message showing which file is being created.
    printf("Create file: ", filename);
    printf("Content: " , content
    // TODO: Print a message showing what content will be written.

    // TODO: Open or create the file for writing using the open() system call.
        fd = open(filename, O_CREAT | O_WRONLY | O_TRUNC, 0644
    // TODO: Use flags O_CREAT | O_WRONLY | O_TRUNC and permissions 0644.
    // TODO: Check if open() failed (fd == -1). If so, print an error using perror and return -1.
        if (fd == -1){
        perror("Error accessing file");
        return -1;
}
    // TODO: Print the file descriptor value.
    printf("File descriptor: " , fd);

    // TODO: Write the content to the file using the write() system call.
    bytes_written = write(fd, content, strlen(content));
    // TODO: Use the length of 'content' as the size to write.
    // TODO: Check if write() failed (bytes_written == -1). If so, print an error using perror, close the file, and return -1.
        if (bytes_written ==-1){
            perror("Error writing to file");
            close(fd);
            return -1;
        }
    // TODO: Print a success message with the number of bytes written and the filename.
        printf("Writting bytes was Successful: " , bytes_written, filename);

    // TODO: Close the file using close(fd).
    // TODO: Check if close() failed. If so, print an error using perror and return -1.
    if (close(fd) == -1) {
        perror("Error closing file");
        return -1;
    }
    // TODO: Print a message that the file was closed successfully.
    printf("File closed successfully: ", filename);
    return 0;
}

int read_file_contents(const char *filename) {
    // TODO: Declare an integer 'fd' for the file descriptor.
    // TODO: Create a buffer array of size 1024 to store the file data.
    // TODO: Declare a variable 'bytes_read' of type ssize_t to store how many bytes are read.
    int fd;
    char buffer[1024];
    ssize_t bytes_read;
    // TODO: Print a message showing which file is being read.

    // TODO: Open the file for reading using the open() system call.
    fd = open(filename, O_RDONLY);
    // TODO: Use the O_RDONLY flag.
    // TODO: Check if open() failed (fd == -1). If so, print an error using perror and return -1.
    if (fd ==-1){
        perror("Error opening file");
        return -1;
    }
    // TODO: Print the file descriptor value.
    // TODO: Print a header for the file contents.
    printf("File discriptor value: " , fd);
    printf("**File Start**\n");
    // TODO: Read the file contents using the read() system call in a loop.
    // TODO: Use sizeof(buffer) - 1 for the buffer size.
    // TODO: Null-terminate the buffer after each read.
    // TODO: Print the contents of the buffer.
    // TODO: Continue reading until read() returns 0.
    while((bytes_read = read(fd, buffer, sizeof(buffer) - 1)) > 0){
        buffer[bytes_read] = '\0';
        printf("%s",buffer);
    }

    if (bytes_read == -1) {
        perror("Error reading file");
        close(fd);
        return -1;
    }
    // TODO: Check if read() failed (bytes_read == -1). If so, print an error using perror, close the file, and return -1.

    // TODO: Print a footer for the end of the file.

    // TODO: Close the file using close(fd).
    // TODO: Check if close() failed. If so, print an error using perror and return -1.
    if (close(fd) == -1) {
        perror("Error when closing file");
        return -1;
    }
    // TODO: Print a message that the file was closed successfully.
    printf("File has closed successfully: " filename);
    return 0;
}
