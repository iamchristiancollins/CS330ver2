.data               # start of data section
# put any global or static variables here

.section .rodata    # start of read-only data section
# constants here, such as strings
# modifying these during runtime causes a segmentation fault, so be cautious!
myString: .string "The answer is %d\n"


.text               # start of text /code
# everything inside .text is read-only, which includes your code!
.global main        # required, tells gcc where to begin execution

# === functions here ===

main:               # start of main() function
# preamble
pushq %rbp
movq %rsp, %rbp

# === main() code here ===

# a = 2
movq $2, %rax   # a == 2 in %rax
# b = 3
movq $3, %rbx   # b == 3 in %rbx

# c = a + b
addq %rbx, %rax # c == a(2) + b(3) in %rax

# printf("The answer is %d\n", c);
# 1. save any caller saved registers
movq %rax, %r12 # c in r12 to preserve it
pushq %rax      # rax (c) on the stack
pushq %rax
# 2. set up our registers for function call
movq $myString, %rdi    # myString in rdi as first parameter
movq %rax, %rsi         # c in rsi as second parameter

# 3. put 0 in rax
movq $0, %rax   # 0 in rax
xorq %rax, %rax # 0 in rax

# 4. call function
call printf

popq %rax   # pop c off stack and put back in rax
popq %rax



# clean up and return
movq $0, %rax       # place return value in rax
leave               # undo preamble, clean up the stack
ret                 # return
