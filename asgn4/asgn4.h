#ifndef ASGN4_H
#define ASGN4_H

#include <stdio.h>
#include <stdlib.h>

#define NUMBER_OF_BITS 16
#define NUMBER_OF_HEX_DIGITS 4

/**
 * Function: convertDecToBin
 * -------------------------
 * Converts a decimal number to its binary representation as an array of integers.
 * The binary number is represented in big-endian format (most significant bit first).
 *
 * dec: the decimal number (0 <= dec <= 65535)
 *
 * Returns: Pointer to an integer array of size NUMBER_OF_BITS allocated on the heap.
 *          The caller is responsible for freeing the allocated memory.
 */
int *convertDecToBin(int dec)
{
    int *binArray = (int *)malloc(NUMBER_OF_BITS * sizeof(int));
    if (binArray == NULL)
    {
        fprintf(stderr, "Memory allocation failed in convertDecToBin\n");
        exit(EXIT_FAILURE);
    }
    // Fill the array from right (least significant bit) to left.
    // This ensures the array is in big-endian order.
    for (int i = NUMBER_OF_BITS - 1; i >= 0; i--)
    {
        *(binArray + i) = dec % 2;
        dec /= 2;
    }
    return binArray;
}

/**
 * Function: convertBinToDec
 * -------------------------
 * Converts a binary number (represented as an array of integers) to its decimal equivalent.
 * The binary number is assumed to be in big-endian format.
 *
 * binArray: pointer to an integer array of size NUMBER_OF_BITS.
 *
 * Returns: the decimal integer equivalent.
 */
int convertBinToDec(int *binArray)
{
    int dec = 0;
    // Process each bit from most significant to least significant.
    for (int i = 0; i < NUMBER_OF_BITS; i++)
    {
        dec = dec * 2 + (*(binArray + i));
    }
    return dec;
}

/**
 * Function: convertDecToHex
 * -------------------------
 * Converts a decimal number to its hexadecimal representation as an array of integers.
 * The hexadecimal representation is in big-endian format (most significant digit first).
 *
 * dec: the decimal number (0 <= dec <= 65535)
 *
 * Returns: Pointer to an integer array of size NUMBER_OF_HEX_DIGITS allocated on the heap.
 *          The caller is responsible for freeing the allocated memory.
 */
int *convertDecToHex(int dec)
{
    int *hexArray = (int *)malloc(NUMBER_OF_HEX_DIGITS * sizeof(int));
    if (hexArray == NULL)
    {
        fprintf(stderr, "Memory allocation failed in convertDecToHex\n");
        exit(EXIT_FAILURE);
    }
    // Fill the array from right to left so that the final array is big-endian.
    for (int i = NUMBER_OF_HEX_DIGITS - 1; i >= 0; i--)
    {
        *(hexArray + i) = dec % 16;
        dec /= 16;
    }
    return hexArray;
}

/**
 * Function: convertHexToDec
 * -------------------------
 * Converts a hexadecimal number (represented as an array of integers) to its decimal equivalent.
 * The hexadecimal number is assumed to be in big-endian format.
 *
 * hexArray: pointer to an integer array of size NUMBER_OF_HEX_DIGITS.
 *
 * Returns: the decimal integer equivalent.
 */
int convertHexToDec(int *hexArray)
{
    int dec = 0;
    // Process each hex digit from most significant to least significant.
    for (int i = 0; i < NUMBER_OF_HEX_DIGITS; i++)
    {
        dec = dec * 16 + (*(hexArray + i));
    }
    return dec;
}

#endif // ASGN4_H
