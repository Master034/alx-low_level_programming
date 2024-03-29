#include "./shell.h"

/**
 * main - entry point
 * Return: 0 on success, 1 on error
 */
int main() {
  char *prompt = "$ ", *new_l = "\n";
  int ret = 0, retn;
  int *execution_return = &retn;

  if (!isatty(STDIN_FILENO)) {
    while (ret != END_FILE && ret != EXIT)
      ret = process_args(execution_return);
    return (*execution_return);
  }
  while (1) {
    write(STDOUT_FILENO, prompt, 2);
    ret = process_args(execution_return);
    if (ret == END_FILE || ret == EXIT) {
      if (ret == END_FILE) {
        write(STDOUT_FILENO, new_l, 1);
      }
      exit(*execution_return);
    }
  }
  return (*execution_return);
}
