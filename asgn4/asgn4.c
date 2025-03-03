#include <stdio.h>
#include <stdlib.h>
#include "asgn4.h"

/* Helper function to print a binary array */
void printBinaryArray(int *binArray)
{
    printf("[");
    for (int i = 0; i < NUMBER_OF_BITS; i++)
    {
        printf("%d", *(binArray + i));
        if (i != NUMBER_OF_BITS - 1)
            printf(", ");
    }
    printf("]");
}

/* Helper function to print a hexadecimal array */
void printHexArray(int *hexArray)
{
    printf("[");
    for (int i = 0; i < NUMBER_OF_HEX_DIGITS; i++)
    {
        // Print each digit in hexadecimal format (using uppercase)
        printf("0x%X", *(hexArray + i));
        if (i != NUMBER_OF_HEX_DIGITS - 1)
            printf(", ");
    }
    printf("]");
}

int main()
{
    // Test cases for convertDecToBin and convertBinToDec
    int decVal1 = 0;
    int decVal2 = 255;
    int decVal3 = 65535;

    int *bin1 = convertDecToBin(decVal1);
    int *bin2 = convertDecToBin(decVal2);
    int *bin3 = convertDecToBin(decVal3);

    printf("convertDecToBin(%d): ", decVal1);
    printBinaryArray(bin1);
    printf("\n");

    printf("convertDecToBin(%d): ", decVal2);
    printBinaryArray(bin2);
    printf("\n");

    printf("convertDecToBin(%d): ", decVal3);
    printBinaryArray(bin3);
    printf("\n");

    printf("convertBinToDec(");
    printBinaryArray(bin1);
    printf("): %d\n", convertBinToDec(bin1));

    printf("convertBinToDec(");
    printBinaryArray(bin2);
    printf("): %d\n", convertBinToDec(bin2));

    printf("convertBinToDec(");
    printBinaryArray(bin3);
    printf("): %d\n", convertBinToDec(bin3));

    // Free allocated memory for binary arrays
    free(bin1);
    free(bin2);
    free(bin3);

    // Test cases for convertDecToHex and convertHexToDec
    int *hex1 = convertDecToHex(decVal1);
    int *hex2 = convertDecToHex(decVal2);
    int *hex3 = convertDecToHex(decVal3);
    int testDec = 65292;
    int *hex4 = convertDecToHex(testDec);

    printf("convertDecToHex(%d): ", decVal1);
    printHexArray(hex1);
    printf("\n");

    printf("convertDecToHex(%d): ", decVal2);
    printHexArray(hex2);
    printf("\n");

    printf("convertDecToHex(%d): ", decVal3);
    printHexArray(hex3);
    printf("\n");

    printf("convertDecToHex(%d): ", testDec);
    printHexArray(hex4);
    printf("\n");

    printf("convertHexToDec(");
    printHexArray(hex1);
    printf("): %d\n", convertHexToDec(hex1));

    printf("convertHexToDec(");
    printHexArray(hex2);
    printf("): %d\n", convertHexToDec(hex2));

    printf("convertHexToDec(");
    printHexArray(hex3);
    printf("): %d\n", convertHexToDec(hex3));

    printf("convertHexToDec(");
    printHexArray(hex4);
    printf("): %d\n", convertHexToDec(hex4));

    // Free allocated memory for hex arrays
    free(hex1);
    free(hex2);
    free(hex3);
    free(hex4);

    return 0;
}
