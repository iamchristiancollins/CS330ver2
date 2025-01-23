#include <stdio.h>
#include "asgn2.h"

void myFunction();

int main() {
    printf("hello\n");

    int x;
    x = 7;

    printf("%d\n", x);

    myFunction();

    return 0;
}

void myFunction() {
    printf("hello from inside the function\n");
}