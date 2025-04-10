.data               # start of data section
# put any global or static variables here
myArr: .quad 1, 2, 3, 4, 5
myArrSize: .quad 5          # size of myArr = 5

.section .rodata    # start of read-only data section
# constants here, such as strings
# modifying these during runtime causes a segmentation fault, so be cautious!
printString: .string "%d\n"


.text               # start of text /code
# everything inside .text is read-only, which includes your code!
.global main        # required, tells gcc where to begin execution

# === functions here ===
printArray:
    # loop through array and print each element
    # void printArray(int *myArr, int size)
    # myArr pointer is in rdi, size is in rsi
    # 1. save callee variables

    # 2. set up our variables
    movq %rdi, %rax     # ptr to myArr in rax
    movq %rsi, %rbx     # size of myArr in rbx

    # for int i = 0; i < size; i++
    movq $0, %rcx       # int i = 0
    _startLoop:
        # prepare to print each element
        # printf("%d\n", *(myArr + i))

        # 1. save any caller saved registers
        pushq %rax          # ptr to myArr on stack
        pushq %rcx          # rcx (i) on stack
        # 2. set up registers
        movq $printString, %rdi # string is in rdi
        # (source, index, width) --> register (rsi)
        movq (%rax, %rcx, 8), %rsi
        # 3. 0 in rax
        xorq %rax, %rax
        # 4. call printf
        call printf

        popq %rcx           # i back in rcx
        popq %rax           # array ptr in rax

        inc %rcx            # i++

        # check if i still need the loop
        cmpq %rbx, %rcx     # rcx - rbx
                            # want rcx < rbx to continue the loop
        jl _startLoop
    
    # once we are out of our loop, restore any callee registers

    # move 0 into rax so our function returns 0 on success
    movq $0, %rax       # return a 0 in rax
    ret

main:               # start of main() function
# preamble
pushq %rbp
movq %rsp, %rbp

# === main() code here ===

# change second value in myArr to 7
# (source, index, width) to access element, these should be registers except width
movq $myArr, %rax           # put myArr ptr in rax
movq $1, %rbx               # index i = 1
movq $7, (%rax, %rbx, 8)    # put 7 at *(myArr + 1)

# call malloc to create an array
# malloc(number of bytes)
# 1. save caller reg
# 2. set up our registers
movq $40, %rdi      # 40 bytes in rdi
# 3. 0 in rax
xorq %rax, %rax
# 4. call malloc
call malloc

movq %rax, %r13     # save malloced array somewhere else


# call printArray(myArr, 5)
# 1. save any caller registers
# 2. set up registers
movq $myArr, %rdi
movq myArrSize, %rsi
# 3. 0 in rax
xorq %rax, %rax
# 4. call function
call printArray



# clean up and return
movq $0, %rax       # place return value in rax
leave               # undo preamble, clean up the stack
ret                 # return
