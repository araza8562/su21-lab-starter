
.text
.dataArray:
    addi sp, sp, -56     # Allocate stack space for the array and the loop counter
    li a0, 8             # Load the value of num, which is 2
 
    sw a0, 56(sp)        # Save the argument num (num = a0)
    addi s0, zero, 0     # Initialize loop counter i to 0
    add t2, sp, x0       # Initialize t2 to point to the start of the array on the stack
    li t3, 10             # For termination of loop
    
loop:
    lw a0, 56(sp)       # Load num
    lw a1, 52(sp)       # Load i
    
    jal ra, compare      # Call compare(num, i)
    
    # Store the result in the source array
    sw a0, 0(t2)
    
    addi t2, t2, 4       # Update the stack pointer for the next array element
    addi s0, s0, 1       # Increment i
    
    sw s0, 52(sp)        # For storing the i
    
    blt s0, t3, loop     # If i < 10, go back to the start of the loop
    j display

compare:
    addi sp, sp, -4
    sw ra, 0(sp)         # Save the return address for .sub
    jal .sub
    lw ra, 0(sp)         # Restore the return address
    
    bge a0, x0, if     # go to if subrountie if the result is greater then or equal to zero
    li a0, 0
    
    addi sp, sp, 4       # Restore the stack pointer
    jr ra

if:
    li a0, 1
    addi sp, sp, 4 
    jr ra

.sub:
    sub a0, a0, a1
    jr ra

display_loop:
     lw a1, 0(t2)        # loading to display
     addi a0, x0, 1      # Prepare for print integer ecall
     ecall
     addi a1, x0, ' '    # a0 gets address of string containing space
     addi a0, x0, 11     # Prepare for print char syscall
     ecall
     addi s0, s0, 1       # Increment i
     addi t2, t2, 4               # Update the stack pointer for the next array element
     blt s0, t3, display_loop     # If i < 10, go back to the start of the loop
     jr ra

display:
    addi t2, sp, 0       # Initialize t2 to point to the start of the array on the stack
    xor s0, s0, s0
    jal display_loop
    j exit
    
exit:
    addi sp, sp, 56     # Allocate stack space for the array and the loop counter
    addi a0, x0, 10
    ecall               # Exit
