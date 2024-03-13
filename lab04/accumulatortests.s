# Author: Ahmed Raza
# Description: This RISC-V assembly code tests five versions of the accumulator function using different input arrays. Each version of the accumulator function should return the sum of the elements of the input array. If a test passes, it prints "Test Passed!", otherwise, it prints "Test Failed!".

.import lotsofaccumulators.s

.data
input_array: .word 1,2,3,4,5,6,7,0
empty_input_array: .space 4
small_input_array: .word 1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0
large_input_array: .space 4096
TestPassed: .asciiz "Test Passed!"
TestFailed: .asciiz "Test Failed!"

.text
main:
    # Test accumulatorone with small_input_array
    la a0, small_input_array
    jal accumulatorone
    li t0, 16
    beq a0 t0 Pass1
Fail1:
    la a0, TestFailed
    jal print_string
    j End
Pass1:
    la a0, TestPassed
    jal print_string

    # Test accumulatortwo with input_array
    la a0, input_array
    jal accumulatortwo
    li t0, 28
    beq a0 t0 Pass2
Fail2:
    la a0, TestFailed
    jal print_string
    j End
Pass2:
    la a0, TestPassed
    jal print_string

    # Test accumulatorthree with empty_input_array
    la a0, empty_input_array
    jal accumulatorthree
    li t0, 0
    beq a0 t0 Pass3
Fail3:
    la a0, TestFailed
    jal print_string
    j End
Pass3:
    la a0, TestPassed
    jal print_string

    # Test accumulatorfour with input_array
    la a0, input_array
    jal accumulatorfour
    li t0, 28
    beq a0 t0 Pass4
Fail4:
    la a0, TestFailed
    jal print_string
    j End
Pass4:
    la a0, TestPassed
    jal print_string

    # Test accumulatorfive with empty_input_array
    la a0, empty_input_array
    jal accumulatorfive
    li t0, 0
    beq a0 t0 Pass5
Fail5:
    la a0, TestFailed
    jal print_string
    j End
Pass5:
    la a0, TestPassed
    jal print_string

End:
    jal exit

print_int:
    mv a1 a0
    li a0, 1
    ecall
    jr ra

print_string:
    mv a1 a0
    li a0, 4
    ecall
    jr ra

exit:
    li a0, 10
    ecall
