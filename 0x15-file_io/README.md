# Read Text File Function

This function reads a text file and prints its contents to the POSIX standard output. It takes two parameters: `filename`, which is the name of the text file, and `letters`, which specifies the number of letters to read and print.

## Prototype

```c
ssize_t read_textfile(const char *filename, size_t letters);
```

# Create File Function

This function creates a file with the specified name and writes the provided text content to it. It takes two parameters: `filename`, which is the name of the file to create, and `text_content`, a NULL-terminated string to write to the file.

## Prototype

```c
int create_file(const char *filename, char *text_content);i
```

# Append Text to File Function

This function appends text to the end of an existing file. It takes two parameters: `filename`, which is the name of the file, and `text_content`, a NULL-terminated string to add at the end of the file.

## Prototype

```c
int append_text_to_file(const char *filename, char *text_content);i
```
