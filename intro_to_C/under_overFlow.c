#include <stdio.h>

#define INT_MAX_VALUE 2147483647  // Largest representable positive 32-bit integer
#define INT_MIN_VALUE -2147483648  // Smallest representable negative 32-bit integer

int main() {
    long long num1, num2, sum, diff; // Use long long to handle large integers

    printf("Please enter two integers: ");
    scanf("%lld %lld", &num1, &num2); // Use %lld for long long

    sum = num1 + num2;
    diff = num1 - num2;

    if (sum > INT_MAX_VALUE) {
        printf("Overflow occurred\n");
    } else if (diff < INT_MIN_VALUE) {
        printf("Underflow occurred\n");
    } else {
        printf("No overflow or underflow occurred\n");
    }

    return 0;
}

