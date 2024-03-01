#include <stdio.h>
#include <stdint.h>

// Function to calculate the two's complement of a 16-bit signed number
int16_t twos_complement(int16_t num) {
     if (num < 0) {
    // Invert all bits and add 1 to get the two's complement
    return ~num + 1;
     }
    else {
        return num;

    } 
}

// Function to print a 16-bit integer in binary
void binary_form(int16_t num) {
    // Iterate through each bit from left to right
    for (int i = 15; i >= 0; i--) {
        // Print the bit at position i
        printf("%d", (num >> i) & 1);
    }
    printf("\n");
}

int main() {
    int16_t num;
    printf("Enter a 16-bit signed integer: ");
    scanf("%hd", &num);

    // Print the original number and its binary representation
    printf("Original number: %d (binary): ", num);
    binary_form(num);

    // Calculate the two's complement
    int16_t complement = twos_complement(num);

    // Print the complement and its binary representation
    printf("Two's complement: %d (binary): ", complement);
    binary_form(complement);

    return 0;
}
