#include <stdio.h>
#include <time.h>
#include <math.h>  // don't forget to compile with -lm
#include <stdlib.h>
#include <string.h> // for memset
/* clock information from here: https://www.geeksforgeeks.org/measure-execution-time-with-high-precision-in-c-c/#:~:text=1%20Using%20time%20%28%29%20function%20in%20C%20%26,C%2B%2B.%20...%205%20Using%20chrono%3A%3Ahigh_resolution_clock%20in%20C%2B%2B.%20
*/
//int k = (int)sqrt(x) + 1;


/* checks if x is prime, if so, returns 1, otherwise returns 0 */
int isItPrime(int x){
    int j;
    int isPrime = 1;
        
        for(j=2; j<x; j++){
            if(x%j == 0){
                /* it's not prime */
                isPrime = 0;
                break;
            }
        }
        if(isPrime){            /* could just be 'return isPrime;'   */
            return 1;
        } else {
            return 0;
        }
} // end isItPrime

void print_primes(int n){
    int i;
    int count = 0;
    printf("The primes under %d are: ", n);
    for(i = 2; i <= n; i++){
        if(isItPrime(i)) {
            printf("%d ", i);
            count++;
        }
    }
    printf("\nThe total number of primes found is: %d", count);
    return;
}  // end print_primes



void print_primesb(int n){
    int i;
    int j;
    int isPrime = 1;
    int count = 0;
    printf("The primes under %d are: ", n);
    for(i = 3; i <=n; i = i + 2){
        int k = (int)sqrt(i) + 1; // need to round up?
        for(j=2; j<k; j++){
            if(i%j == 0){
                /* it's not prime */
                isPrime = 0;
                break;
            }
        }
        if(isPrime){
            printf("%d ", i);
            count++;
        } else {
            isPrime = 1;  // reset
        }
    }
    printf("\nThe total number of primes found is: %d", count);
    return;
}  // end print_primesb


void print_primes_sieveE(int n){
    // Sieve of Erasthosthenes
    //bool allPrimes[n + 1]; // an array of bits to hold the answers
    int *allPrimes = malloc(sizeof(int)*(n+1));
    //memset(allPrimes, 1, sizeof(n+1)); // set all bits to 1 (true)
    int count = 0;

    int p;
    allPrimes[0] = 0;
    allPrimes[1] = 0;
    // set all bits to 1
    for(p=2; p < n; p++){
        allPrimes[p] = 1;
    }


    for(p=2; p*p <=n; p++){
        // if p is a prime, mark all multiples of p as non-primes
        //printf("%d, %d\n", p, allPrimes[p]);
        if(allPrimes[p] == 1){
            int i;
            for(i = p*p; i<=n; i+=p){
                allPrimes[i] = 0;
            }
        }

    }

    // print them all
    printf("The primes under %d are: ", n);
    printf("2 ");
    for(p=2; p<=n; p++){
        if(allPrimes[p] == 1){
            printf("%d ", p);
            count++;
        }
    }
    printf("\n");
    printf("\nThe total number of primes found is: %d\n", count);

    return;
}


int main(int argc, char *argv[]){
    // variables for timing
    time_t start;
    time_t end;

    // for the clock
    clock_t c_start = clock();  // start clock
    clock_t c_stop;
    clock_t diff;

    // start the clock timer
    time(&start); /* can also use start = time(NULL) */

    // ==============================
    // ====== set these =======
    int n = 10000000;    // find all the primes from 1 to n

    // call the function
    // print_primes(n);  // don't try this for n = 1,000,000
    //print_primesb(n);
    print_primes_sieveE(n);
    // =============================

    // stop the clock
    time(&end);
    c_stop = clock();
    diff = c_stop - c_start;
    int msec = diff * 1000 / CLOCKS_PER_SEC;

    // calc the total time and print
    double time_taken = (end - start);
    printf("\nReal time taken is approx: %.5f sec\n", time_taken);
    printf("CPU time taken is: %d sec %d msec\n", msec/1000, msec%1000);

    return 0;
}