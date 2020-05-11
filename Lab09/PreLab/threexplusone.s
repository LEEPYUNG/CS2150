; threexplusone.s
;
;Pyung K Lee
;PKL4FR
;4/7/2020
;
; Parameter 1 (in rdi) is the first integer
;
;OPTIMIZATIONS
;1) used r8,r9,r10 as counters/varibles holders -> Now only using r9.
;2) used to use product from the last lab to multiple by 3 -> Now using only add
;3) used a combination of registers and methods to check if odd or even -> Now using AND 


	global threexplusone
	section .text
	global threeplusone


threexplusone:
	; Subroutine body:
	push 	rdi		 ;save caller-save register
	push 	r9

	xor 	r9,  r9
	xor 	rax, rax

	cmp	rdi, 2		 ; does number == 2?
	je	done		 ; if so, jump to base case

	cmp	rdi, 1		 ; does number == 1?
	je	done2		 ; if so, jump to base case2

	mov 	r9, rdi	 ;move paramenter to r10
	and 	r9, 1		 ;Check if even or odd	
	cmp 	r9, 0		 ;does r10 = 0? (even?)
	je 	even		 ;jump to even loop

odd:	
	push 	rax
	mov 	r9, rdi		;same as multiply by 3
	add	r9, rdi
	add	r9, rdi
	inc 	r9	
	mov 	rdi, r9		;move that value back into rdi
	xor 	r9,  r9
	call 	threexplusone
	mov	r9, rax		;r9 now holds what ever that last recusive call holds
	pop 	rax
	jmp 	done

even:
	push 	rax
	sar 	rdi,1		 ;divide parameter by 2
	xor 	r9,  r9
	call	threexplusone
	mov	r9,rax		 ;r9 now holds what ever that last recusive call holds
	pop 	rax
	jmp	done

done:				;jump here when input is 2, so r9 is incremented
	inc 	r9
done2:				;jump here when input is 1, so r9 is not incremeneted
	mov 	rax, r9 	;move r9 back into rax.
	pop 	r9
	pop	rdi		
	ret











