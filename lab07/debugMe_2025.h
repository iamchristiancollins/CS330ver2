#ifndef __debugme__
#define __debugme__

#include<stdlib.h>

/* helper function to take an array of ints and add 1 to each element
Takes and array of ints, and the size of the array
Returns the array with each element incremented by 1
Does not change the original array
*/
int* addOne(int * arr, int size){
    int *resultArray = malloc(sizeof(arr[0] * size));
    for(int i = 0; i < size; i++){
        *(resultArray + i) = *(arr + i) + 1;
    }
    return resultArray;
}

/* helper function to print an array
Takes an int array, and the size of the array
Returns nothing
prints each element of the array
*/
void printMyArray(int * arr, int size){
    printf("[ ");
    for(int i = 0; i < size; i++){
        if (i == size - 1){
            /* last element*/
            printf("%d ] \n", *(arr + i));
        } else {
            printf("%d , ", *(arr + i));
        }
    }
    return;
}  // end printMyArray


/*
Function prints a response based on the input.
Takes an int, n, as input
Returns nothing
But prints:
    FIZZ if n is evenly divisible by 3
    BUZZ if n is evenly divisible by 7
    FIZZBUZZ if n is divisible by both 3 and 7
    'neither FIZZ or BUZZ' otherwise 
*/
void fizzBuzz(int n){
    if (n % 3 == 0){
        printf("FIZZ \n");
    } else if (n % 7 == 0){
        printf("BUZZ \n");
    } else if (n % 3 == 0 && n % 7 == 0){
        printf("FIZZBUZZ \n");
    } else {
        printf("neither FIZZ nor BUZZ \n");
    }
    return;
}  // end fizzBuzz

#endif