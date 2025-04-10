.data               # start of data section
# put any global or static variables here
myY: .space 8   # assigning 8 bytes to myY
myY2: .quad 0   # assign 8 bytes, initialize to 0

.section .rodata    # start of read-only data section
# constants here, such as strings
# modifying these during runtime causes a segmentation fault, so be cautious!
printString: .string "The answer is %d\n"
scanString: .string "%d"


.text               # start of text /code
# everything inside .text is read-only, which includes your code!
.global main        # required, tells gcc where to begin execution

# === functions here ===

# pow(x, y) calculate x^y
# takes two ints x (rdi) and y(rsi), raises x to the y power
# return answer in rax
pow:
    # save any callee-saved registers
        # none
    # set up our variables
    # x in rdi
    # y in rsi
    movq $0, %rcx   # i = 0 in rcx
    movq $1, %rax   # 1 in rax for the answer

    # for (int i = 0; i < y, i++)
    _forloop:
        # answer = answer * x
        imulq %rdi  # rdi (x) * rax(answer) --> rax(updated answer)

        inc %rcx    # i++ in rcx

        cmpq %rsi, %rcx     # rcx (i) - rsi (y) setting our eflag
                            # rcx (i) - rsi (y) __ 0
                            #         + rsi (y)    + rsi (y)
                            # rcx (i) < rsi(y)  to continue loop
        jl _forloop
    
    # return out answer (rax)
    ret

main:               # start of main() function
# preamble
pushq %rbp
movq %rsp, %rbp

# === main() code here ===

# call scanf for user input
# scanf("%d", &y)

# 1. save caller registers
# 2. set up registers: rdi, rsi
movq $scanString, %rdi  # ptr to string in rdi
movq $myY2, %rsi        # ptr to the variable myY2 to store input
# 3. 0 in rax
xorq %rax, %rax
# 4. call function
call scanf



# call pow(2, 3) to get 2^3 = 8
# 1. save caller-saved registers
    # none
# 2. setup our registers: rdi, rsi
movq $2, %rdi   # x = 2 in rdi
movq myY2, %rsi # myY2 in rsi. NOTE: no '$' in front of myY2, this dereferences it
movq (myY2), %rsi # also dereferences myY2

# movq $3, %rsi   # y = 3
# 3. 0 in rax
xorq %rax, %rax # 0 in rax
# 4. call our function
call pow        # call pow(2, 3)

# printf("the answer is %d\n", answer)
# 1. save caller registers
# 2. set up our registers: rdi, rsi
movq $printString, %rdi # string in rdi
movq %rax, %rsi         # answer form pow in rsi
# 3. 0 in rax
xorq %rax, %rax
# 4. call our function
call printf


# clean up and return
movq $0, %rax       # place return value in rax
leave               # undo preamble, clean up the stack
ret                 # return
