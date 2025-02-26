#include <stdio.h>
#include "debugMe_2024.h"


int main(){

    int myArr[] = {1, 2, 3, 4, 5};
    int *myNewArr = addOne(myArr, 5);

    printf("n is 3, expected answer is: CS\n");
    introToCS330(3);       // should print CS
    printf("\n");

    printf("n is 70, expected answer is: UAB\n");
    introToCS330(70);       // should print UAB
    printf("\n");

    printf("n is 17, expected answer is Go Blazers:\n");
    introToCS330(17);       // should print Go Blazers
    printf("\n");

    printf("n is 25, expected answer is 15,625:\n");
    introToCS330(25);       // should print 15,625
    printf("\n");

    return 0;
}