#include <stdio.h>

int main() {

    int myArr[] = {1, 2, 3, 4};
    int myArr2[9] = {24, 8, 12};

    myArr2[7] = 7;

    for (int i = 0; i < 4; i++) {
        printf("myArr[%d] is %d\n", i, myArr[i]);
        printf("myArr2[%d] is %d\n", i, myArr2[i]);
    }

    return 0;
}