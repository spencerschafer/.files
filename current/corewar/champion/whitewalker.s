.name "whitewalker"

.comment "winter is coming"

mai99n:
ld %0, r2		#loads 0 into r2, modifies carry	r2 = 0			carry = 1
st r1, r3		#copies player number into r3		r3 = pn
st r3, 6		#load player number into live
live %42		#live call with placeholder
ld -2, r4		#load player number into r4			r4 = pn
st r4, 200		#loads player num into pc + 200 
add r3, r4, r5	#add player number * 2 into r5		r5 = pn * 2
sub r5, r4, r6	#subtracts pn from r5 into r6		r6 = pn
and r4, r6, r7	#ands r4 & r6 (pn's) into r7		r7 = pn			carry = 0
and r2, r7, r8	#r2(0) & r7(pn) into r8				r8 = 0			carry = 1
or r7, r8, r9	#r7(pn) | r8(0) = r9				r9 = pn			carry = 0
xor	r1, r1, r10	#1 ^ 1 = r10						r10 = 0			carry = 1
#zjmp %-61			#jumps to begining of program
#ldi -62, %0,r11	#reads 0 + 1 into r11				r11
#st r11, 100
	#tests
#	test:
#	st r1, r2
#	st r1, r3
#	st r1, r4
#	st r1, r5
#	st r1, r6
#	st r1, r7
#	st r1, r8
#	st r1, r9
#	st r1, r13
#	sti r1, 220, %1
#	sti r2, -280, %2
#	sti r3, -200, %3
#	sti r4, -280, %2
#	sti r5, -280, %2
#	sti r6, -1280, %2
#	sti r7, -2980, %2
#	sti r8, -2800, %2
#	sti r9, 2800, %2
#	sti r13, 4800, %2

math:
	and r1, %0, r15
	add r5, r5, r15
	st	r15, r16
l2:
	sti r1,%:live,%1
	zjmp %:live

live:	live %42
		zjmp %:live
ldi:
	
	ldi %:live, %2000, r11
	ldi %:live, %2001, r12

fork:
	st r11, 55
	st r12, 51
	fork %165
	fork %:math
	ldi %:fork, %0, r3
	ldi %:fork, %4, r4
	ldi %:fork, %8, r5
	ldi %:fork, %16, r6
	st r3, 55
	st r4, 54
	st r5, 53
	st r6, 52
	fork %:math
	sub r1,r15,r15
	zjmp %:live
#	and	r1, %0, r15
#	zjmp %:fork
	#part of the test
#part:
#	fork %:test
#	and r15, %0, r15
#	zjmp %:part
#	st 	r16, r15

