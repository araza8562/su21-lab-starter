#include <stdio.h>
#include <stdlib.h>

// Function to convert an integer to a binary string
void intToBinary(int n, char *binary) {
    // Iterate through each bit of the integer
    for (int i = 31; i >= 0; i--) {
        // Extract the bit at position i
        int bit = (n >> i) & 1;
        // Append the bit to the binary string
        binary[31 - i] = bit + '0';
    }
    // Null-terminate the binary string
    binary[32] = '\0';
}

// Function to perform division of a binary number by 1010 (divisor)
void binaryDivision(int *dividend, int *iterations, int *remainder) {
    int divisor = 10; // Divisor is 1010 in binary
    int quotient = 0;

    // Convert binary string to an integer
    int dividendInt = *dividend;

    // Iterate through each bit of the dividend
    for (int i = 31; i >= 0; i--) {
        // Left shift the remainder by 1 to make room for the next bit
        *remainder = (*remainder << 1) | ((dividendInt >> i) & 1);

        // If the remainder is greater than or equal to the divisor, subtract the divisor
        if (*remainder >= divisor) {
            *remainder -= divisor;
            quotient = (quotient << 1) | 1; // Set the corresponding bit in the quotient
        } else {
            quotient = (quotient << 1); // Shift left and keep the bit as 0
        }
    }

    // Update the dividend with the new quotient
    *dividend = quotient;

    // Increment the number of iterations if the remainder becomes zero
    if (*remainder == 0) {
        (*iterations)++;
    }
}

int main() {
    char dividendStr[32];
    int iterations = 0;
    int remainder = 0;

    // Input the dividend as a decimal number
    printf("Enter the Number to find trailing zeros (decimal): ");
    scanf("%s", dividendStr);

    // Handle the case when the input is '0'
    if (dividendStr[0] == '0' && dividendStr[1] == '\0') {
        printf("Zero has no trailing zeros.\n");
        return 0;
    }

    // Convert the decimal string to an integer using strtol
    int dividendInt = (int) strtol(dividendStr, NULL, 10);

    // Perform binary division iteratively until the remainder becomes zero
    while (remainder == 0) {
        binaryDivision(&dividendInt, &iterations, &remainder);
    }

    printf("\nTotal Number of Trailing zeros in this number are: %d\n", iterations);

    return 0;
}

