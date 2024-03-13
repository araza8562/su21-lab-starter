// RISC-V Assembly code by Ahmed Raza
// This code replicates the functionality of the provided C code


.data
i:
    .word   0
a:
    .word   7
b:
    .word   0
    .word   0
    .word   0
   
.text
main:
    la t1, i # loading address of i, a and b respectively.
    la t2, a 
    la s2, b
    
    lw s0, 0(t1)
    lw s1, 0(t2)
    addi s0, s0, 0
    xor t1, t1, t1 # clearign the register for storing the answer a+(i*n)
    xor t2, t2, t2 # clearing the register for calculing the index.
    xor t3, t3, t3 # for not using left shit logic operator
    xor a0, a0, a0
    li  t4, 3
    
    jal loop    # for looping 
    
    la t1, i # Reinitizting the values for the display.
    la t2, a 
    la s2, b
    lw s0, 0(t1)
    lw s1, 0(t2)
    addi s0, s0, 0
    xor t1, t1, t1      # clearign the register for storing the answer a+(i*n)
    xor t2, t2, t2      # clearing the register for calculing the index.
    xor t3, t3, t3      # for not using left shit logic operator
    xor a0, a0, a0
    li  t4, 3
    add t2, s2, t3
    jal display         # For displaying teh values
    
    jal exit # for displayng values
    
loop:
    
    mul t1, s0, s1      # for calculating the a+(i*a)
    add t1, s1, t1
    
    # for calculatign the index
    add t2, s2, t3
    sw  t1, 0(t2)

    addi t3, t3, 4      # for indexing of array
    addi s0, s0, 1
    blt s0, t4, loop    # loop condtion.
    add a0, a0, x0
    jr ra

exit:
    addi a0, x0, 10
    ecall # Exit
    
display:
    lw  t1, 0(t2)       # Loading the values back from array

    xor a0, a0, a0      # clearing the registers for displaying
    add a0, x0, t1
    
    addi a1, a0, 0      # Printing the value
    addi a0, x0, 1
    ecall # Print Result
    
    addi a1, x0, '\n'   # Printing the on new line
    addi a0, x0, 11
    ecall # Print newline
    
    addi t3, t3, 4      # looping back to display all the vlaues in array.
    add t2, s2, t3
    addi s0, s0, 1
    blt s0, t4, display
    add a0, a0, x0
    jr ra
