#include <stdio.h>

// Inline function declaration
static inline int add(int a, int b);

// Static inline function definition
static inline int add(int a, int b) {
    return a + b;
}

int main() {
    int num1 = 10, num2 = 20;
    int sum = add(num1, num2); // Function call

    printf("Sum: %d\n", sum);

    return 0;
}

