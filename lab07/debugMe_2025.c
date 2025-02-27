#include <stdio.h>
#include "debugMe_2025.h"


int main(){

     /* testing addOne() */
        // create an array of ints and print it
        int myArr[] = {1, 2, 3, 4, 5};
        printf("Original Array: ");
        printMyArray(myArr, 5);
        // add one to each element and print the new array
        int *myNewArr = addOne(myArr, 5);
        printf("My New Array: ");
        printMyArray(myNewArr, 5);

    /* testing fizzBuzz() */
        printf("n is 3 | expected answer: FIZZ | actual answer: ");
        fizzBuzz(3);       // should print FIZZ
        printf("\n");

        printf("n is 7 | expected answer: BUZZ | actual answer: ");
        fizzBuzz(7);       // should print BUZZ
        printf("\n");

        printf("n is 21 | expected answer: FIZZBUZZ | actual answer: ");
        fizzBuzz(21);       // should print FIZZBUZZ
        printf("\n");

        printf("n is 4 | expected answer: neither | actual answer: ");
        fizzBuzz(4);       // should print 'neither FIZZ or BUZZ'
        printf("\n");

    return 0;
}  // end main()