#include <stdio.h>
#include <stdlib.h>

void printMe(float *myArr, int arrLen) {
    for (int i = 0; i < arrLen; i++) {
        printf("myArr[%d] = %.2f\n", i, myArr[i]);
    }
}

float* returnMe() {
    int size = 3;
    float *arr = malloc(size * sizeof(float));
    printf("float: %ld bytes\n", sizeof(float));

    *(arr + 1) = 1.0;

    return arr;
}

int main() {
    // float arr[5] = {.2, 5.3, 2.75, 3.333333333333, 7.0};

    printMe(returnMe(), 3);

    return 0;
}