#include <stdio.h>

int main() {
    unsigned int x, y;
    x = 42;
    y = 24;
    
    __asm__ volatile("add %1, %0" : "+r" (x) : "r" (y) : "cc");

    printf("X: %d\n", x);
    printf("Y: %d\n", y);

    return 0;
}

