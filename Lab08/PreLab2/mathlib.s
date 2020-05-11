; mathlib.s
;
;Pyung K Lee
;PKL4FR
;3/31/2020
;
; Parameter 1 (in rdi) is the first integer
; Parameter 2 (in rsi) is the second integer
; Return value is a long that is the prodict of the integers in the sequence
;

	global mathlib.s
	
	section .text
	global product  ;make function global 
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
