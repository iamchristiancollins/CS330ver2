#include<stdio.h>
#include<string.h>

int main(){

   /* worst user log in ever */
   char psswd[10];
   char answer[10] = "1234";
    printf("Please enter your pwd\n");
    scanf("%s", &psswd);

    /* print them out */
    printf("User entered psswd at (%p): %s\n", &psswd, psswd);
    printf("Real password answer at (%p): %s\n", &answer, answer);

    if(strcmp(psswd, answer) == 0){
        printf("congrats!, open!\n\n");
    } else {
        printf("Denied!!\n\n");
    }


    // print the stack
    /*
    int i;
    for(i=20; i>=0; i--){
        printf("%p: %c\n", (psswd + i), *(psswd +i));
    }
    */



    return 0;
}








/*
note: if this is compiled as hacks:
gcc scan_security.c -o hacks

then run as:
./hacks < <(python -c "print('1234')")




or to smash, run as:
./hacks < <(python -c "print('AAAAAAAAA' + '\x00' + 'AAAAAAAAA' + '\x00')")


can fix by adjusting the scanf conversion specifier:
scanf("%10s", &psswd);
restricts inputs to 10 characters
Also a good practice to check all user input for special characters, or anything unexpected
*/


/* similar vulnarability with printf */
    /* printf vuln and %n conversion specifier */
    /* printf("printf vuln:  %p %d %d %d"); */