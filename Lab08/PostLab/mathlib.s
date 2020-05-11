; mathlib.s
;
;Pyung K Lee
;PKL4FR
;4/3/2020
;
; Parameter 1 (in rdi) is the first integer
; Parameter 2 (in rsi) is the second integer
; Return value is a long that is the prodict of the integers in the sequence
;

	global mathlib.s
	section .text
	global product  ;make function global 
	global power

product:
	; Standard prologue: we do not have to create any local
	; variables (those values will be kept in registers)
	push rbp		 ;save callee-save register
	push rbx		 ;save callee-save register

	; Subroutine body:
	xor	rax, rax	 ; zero out the return register
	xor	r10, r10	 ; zero out the counter i
	mov 	rbp, rdi	 ; param 1 to rbp
	mov 	rbx, rsi	 ; param 2 to rbx
start:	
	cmp	r10, rbx	 ; does i (0) == rbx?
	je	done		 ; if so, we are done with the loop
	add	rax, rbp 	 ; add rbp to local variable
	dec	rbx		 ; decrement our counter rbx
	jmp	start		 ; we are done with this loop iteration
done:	
	; Standard epilogue: the return value is already in rax, we	
	pop rbx			 ;pop back callee registers
	pop rbp
	ret


power:
	; Subroutine body:
	xor	rax, rax	 ; zero out the return register
	xor	r10, r10	 ; zero out the counter power

	push 	rsi		 ;save caller-save register
	push 	rdi		 ;save caller-save register
	mov 	r10, rsi	 ; param 2 to r10 (power)
start2:	
	cmp	r10, 0		 ; does power == 0?
	je	loopBase	 ; if so, jump to base case	
loop:
	dec 	r10		 ;decrement counter
	mov	rsi, r10	 ;move counter into rsi
	call 	power		 ; call power(base, power-1)
	mov	rsi, rax	 
	call 	product		 ;call product(base, rsi)		
	je	done2
	
loopBase:
	mov 	rax, 1		;make value of rax = 1;
	je 	done2	

done2:	
	; Standard epilogue: the return value is already in rax, we

	pop	rdi			 ;pop back caller registers
	pop 	rsi
	ret
