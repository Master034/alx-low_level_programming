#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    int num1, num2, sum;
    if (argc != 3) {
        printf("Usage: %s <num1> <num2>\n", argv[0]);
        return 1;
    }

    num1 = atoi(argv[1]);
    num2 = atoi(argv[2]);

    sum = num1 + num2;
    printf("The sum of %d and %d is: %d\n", num1, num2, sum);

    return 0;
}
