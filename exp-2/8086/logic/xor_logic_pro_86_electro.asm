
MOV AX, 0AB00H 
MOV BX, 0CDEFH
XOR AX, BX
MOV DI, 3000H
MOV [DI], AX

END