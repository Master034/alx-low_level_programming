#include "shell.h"

/**
 * _getline - Gets the line
 * Return: Line Passed in.
 */

char* _getline() {
    static char buffer[BUFFER_SIZE];
    static size_t buffer_pos = 0; // Current position in the buffer
    static ssize_t chars_in_buffer = 0; // Number of characters in the buffer

    char* line = NULL;
    size_t line_len = 0;
    ssize_t chars_read;

    while (1) {
        // If the buffer is empty, read new data from the input stream
        if (buffer_pos >= chars_in_buffer) {
            chars_read = read(STDIN_FILENO, buffer, BUFFER_SIZE);
            if (chars_read <= 0) {
                if (line != NULL) {
                    line[line_len] = '\0'; // Null-terminate the line
                }
                return line; // Return NULL on error or end of file
            }
            buffer_pos = 0;
            chars_in_buffer = chars_read;
        }

        char c = buffer[buffer_pos];
        buffer_pos++;

        if (c == '\n') {
            if (line == NULL) {
                line = (char*)malloc((line_len + 1) * sizeof(char));
            } else {
                line = (char*)realloc(line, (line_len + 1) * sizeof(char));
            }

            if (line == NULL) {
                perror("Memory allocation failed");
                exit(EXIT_FAILURE);
            }

            line[line_len] = '\0'; // Null-terminate the line
            return line;
        } else {
            if (line == NULL) {
                line = (char*)malloc((line_len + 1) * sizeof(char));
            } else {
                line = (char*)realloc(line, (line_len + 1) * sizeof(char));
            }

            if (line == NULL) {
                perror("Memory allocation failed");
                exit(EXIT_FAILURE);
            }

            line[line_len] = c;
            line_len++;
        }
    }
}
