/*
 *
 * Multiple Copies Program
 * By: Ivan E Garcia
 *
 */

#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>

int main(int argc, char *argv[]) {
  if (argc != 4) {
    perror("Error: Please provide 1 source file & 2 destinations files");
    exit(1);
  }
  // File Names
  char *source_path = argv[1];  char *destination1_path = argv[2];  char *destination2_path = argv[3];


  // Opens source path
  int sourced_fd = open(source_path, O_RDONLY);
  if (sourced_fd == -1) {
    printf("Error when Opening: %s\n", source_path);
    close(sourced_fd);
    exit(1);
  }
  int destination1_fd =
      open(destination1_path, O_WRONLY | O_CREAT | O_TRUNC, S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH);
  if (destination1_fd == -1) {
    perror("Error while trying to open Destination 1 File");
    close(sourced_fd);
    exit(1);
  }


  // Opens the second file
  int destination2_fd =
      open(destination2_path, O_WRONLY | O_CREAT | O_TRUNC, S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH);
  if (destination2_fd == -1) {
    perror("Error while trying to open Destination 2 File");
    close(sourced_fd);  close(destination1_fd);
    exit(1);
  }


  // Buffer to help make sure everything is copied correctly
  char buffer[100];


  ssize_t bytes_read;
  // loop for reading until EOF
  while ((bytes_read = read(sourced_fd, buffer, sizeof(buffer))) > 0) {
    // Write to first file
    if (write(destination1_fd, buffer, bytes_read) == -1) {
      perror("Error when using write");
      close(sourced_fd);  close(destination1_fd);   close(destination2_fd);
      exit(1);  }
    // Write to second file
    if (write(destination2_fd, buffer, bytes_read) == -1) {
      perror("Error when using write");
      close(sourced_fd);  close(destination1_fd);   close(destination2_fd);
      exit(1);  }
  }
  // Check to see if there was an error while reading the source file
  if (bytes_read == -1) {
    perror("Error while trying to read source file");
    exit(1);  }
  // Closing each fd
  close(sourced_fd);  close(destination1_fd);   close(destination2_fd);

  return 0;
}
