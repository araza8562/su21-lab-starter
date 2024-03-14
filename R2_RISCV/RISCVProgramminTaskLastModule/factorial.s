# Author: Ahmed Raza
# Description: This RISC-V assembly code calculates the factorial of a number and writes the result to the TOHOST register.

.globl main

.text
main:
    # Load the address of the variable 'num' into a0
    la a0, num
    # Load the value of 'num' into a0
    lw a0, 0(a0)
    # Call the factorial function
    jal factorial
    # Store the result of the factorial in the 'result' variable
    la s0, result
    sw a0, 0(s0)
    # Jump to the write_tohost function to output the result

factorial:
    # Prologue
    addi sp, sp, -8
    sw a0, 4(sp)
    sw ra, 0(sp)

    addi t0, x0, 1  # Load 1 into t0
    bgt a0, t0, else  # Branch to 'else' if a0 > 1
    addi a0, x0, 1   # Set return value to 1 if a0 <= 1
    addi sp, sp, 8   # Epilogue
    jr ra            # Return

else:
    addi a0, a0, -1  # Decrement a0 by 1
    jal factorial    # Recursive call to factorial function
    lw ra, 0(sp)     # Restore ra from the stack
    lw t1, 4(sp)     # Restore original a0 from the stack
    addi sp, sp, 8   # Epilogue
    mul a0, t1, a0   # Multiply original a0 by returned value
    jr ra            # Return

.data
num: .word 5      # Input number
result: .word 0  # Result of the factorial calculation

write_tohost:
    li x1, 1          # Load immediate value 1 into x1
    sw x1, tohost     # Write x1 to TOHOST register

    .align 12
    .section ".tohost","aw",@progbits
    .align 4
    .global tohost
    tohost: .dword 0  # TOHOST register
    .align 4
    .global fromhost
    fromhost: .dword 0  # FROMHOST register

