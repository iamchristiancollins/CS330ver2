.data               # start of data section
# put any global or static variables here

.section .rodata    # start of read-only data section
# constants here, such as strings
# modifying these during runtime causes a segmentation fault, so be cautious!
myDivString: .string "The answer is %d\n"


.text               # start of text /code
# everything inside .text is read-only, which includes your code!
.global main        # required, tells gcc where to begin execution

# === functions here ===
divByTwo:
# 1. save any callee registers
    # a. save all the registers
    # b. save if we use
    # c. avoid using callee registers
    # d. ignore the rules

# 2. set up our variables
# we want to divide by 2, and the numerator should be in %rdi
# put 2 somewhere
movq $2, %rcx       # 2 in rcx
# If we want to divide, our numerator should be in %rax
movq %rdi, %rax     # numberator in %rax

# 3. divide
cqto                # convert quad in rax to oct in rdx:rax
idivq %rcx          # rdx:rax (input) / rcx (2) --> rax with remainder in rdx

ret                 # returns what is in %rax


main:               # start of main() function
# preamble
pushq %rbp
movq %rsp, %rbp

# === main() code here ===

# multiply 2 and 3
movq $2, %rax   # a = 2 in %rax
movq %rax, %r12 # a = 2 also in %r12
movq $3, %rbx   # b = 3 in %rbx

# multiply
imulq %rbx      # rax (a) * rbx (b) --> rdx:rax (c)

# call divByTwo
# 1. save caller registers
# 2. setup rdi, rsi
movq $8, %rdi       # 8 in rdi for first parameter
# 3. put 0 in rax
xorq %rax, %rax     # 0 in rax
# 4. call function
call divByTwo       # divByTwo(8) return in rax

# call printf("The answer is %d\n", answer);
# 1. save caller registers
# 2. setup rdi, rsi
movq $myDivString, %rdi     # string in rdi for first parameter
movq %rax, %rsi             # rax (answer) in rsi
# 3. put 0 in rax
xorq %rax, %rax
# 4. call function
call printf



# clean up and return
movq $0, %rax       # place return value in rax
leave               # undo preamble, clean up the stack
ret                 # return
