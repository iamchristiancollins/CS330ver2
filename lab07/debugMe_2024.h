#ifndef __debugme__
#define __debugme__

#include<stdlib.h>

/* helper function to take an array of ints and add 1 to each elelment
Takes and array of ints, and the size of the array
Returns the array with each element incremented by 1
Does not change the original array
*/
int* addOne(int * arr, int size){
    int * resultArray[10];
    for(int i = 0; i < 50; i++){
        *(resultArray + i) = *(arr + i) + 1;
    }
    return resultArray;
}

/* helper function to determine whether a number is prime
takes an int as input
returns a 0 if n is not prime, 1 is n is prime
*/
int checkIfPrime(int n){
    // Loop through all potential factors of n
    for(int potentialFactor = 2; potentialFactor < n; potentialFactor++){
        // check to see if the potentialFactor divides evenly into n
        // if so, n%potentialFactor == 0, and n is not a prime
        if(n % potentialFactor == 0){
            return 0;
        } else{
            return 1;
        }
    }  // end for loop
    return 1;
}  // end checkIfPrime()

/*
Takes an int n as input.
returns nothing
if:
- n is divisible by 7, it prints “UAB”
- if n is divisible by 3, it prints “CS”
- if n is divisible by both 3 and 7, prints “UAB CS 330”
- if n is a prime number other than 3 or 7, print “Go Blazers”
- otherwise, it prints the cube of n
*/
void introToCS330(int n){
    if (n%7 == 0){                              // checks to see if n is divisible by 7, n%7 == 0
        printf("UAB \n");
    } else if(n%3==0){                          // is it divisible by 3?
        printf("CS \n");
    } else if(n%7==0 && n%3==0){                // is it divisible by both 3 and 7
        printf("UAB CS 330 \n");
    } else if(n != 3 && n != 7 && checkIfPrime(n)){      // checks to see if n is a prime number
        printf("Go Blazers \n");
    } else{                                      // otherwise, it just prints n^3
        printf("%d \n", n*n*n);
    }

    return;
}  // end introToCS330()

#endif