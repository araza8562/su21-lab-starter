.globl factorial

.data
n: .word 8

.text
main:
    la t0, n
    lw a0, 0(t0)
    jal ra, factorial

    addi a1, a0, 0
    addi a0, x0, 1
    ecall # Print Result

    addi a1, x0, '\n'
    addi a0, x0, 11
    ecall # Print newline

    addi a0, x0, 10
    ecall # Exit

factorial:
    # Initialize variables
    li t2, 1         # Initialize factorial to 1

    # Loop for factorial calculation
    loop:
    beqz a0, exit    # If a0 (n) is 0, exit loop
    mul t2, t2, a0   # Multiply factorial by a0
    addi a0, a0, -1  # Decrement n
    j loop           # Jump back to loop

    # Exit loop
    exit:
    mv a0, t2        # Move the factorial value to a0 for returning
    jr ra            # Return to the calling function

