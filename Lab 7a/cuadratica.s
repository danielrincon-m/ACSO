@ as -g -o cuadratica.o cuadratica.s
@ ld -o cuadratica cuadratica.o
@ gdb cuadratica

@ r (run)
@ b 7 (line brak at line 7)
@ i r (info registers)
@ q (quit)
.data
@ main
bneg:       .word   0
sqroot:     .word   0
twoa:       .word   0

.text
.global _start

_start:
            LDR     R0, aa
            CMP     R0, #0
            MOVEQ   R0, #-1  
            BEQ     exit

            LDR     R0, bb              @-b
            MOV     R1, #0
            SUB     R2, R1, R0
            LDR     R1, =bneg
            STR     R2, [R1]

            LDR     R0, bb              @sqrt(b**2 - 4*a*c)
            MUL     R1, R0, R0
            MOV     R2, #4
            LDR     R3, aa
            LDR     R4, cc
            MUL     R5, R2, R3
            MUL     R6, R5, R4
            SUB     R0, R1, R6
            BL      sqrt
            LDR     R1, =sqroot
            STR     R0, [R1]

            MOV     R0, #2              @2*a
            LDR     R1, aa
            MUL     R2, R0, R1
            LDR     R3, =twoa
            STR     R2, [R3]

            LDR     R2, =bneg           @load data
            LDR     R2, [R2]
            LDR     R3, =sqroot
            LDR     R3, [R3]
            LDR     R4, =twoa
            LDR     R4, [R4]

            CMP     R3, #0              @Si el resulado de la raiz fue -1 exitt
            MOVLT   R0, #-1
            BLT     exit

            MOVEQ   R1, #-1             @Si el resultado de la raiz es 0, solo se hace un caso
            BEQ     posop  

            MOV     R5, R2              @Hacerlo con la parte negativa y el resultado va en el R1
            SUB     R5, R5, R3
            LDR     R6, mcons
            MUL     R7, R5, R6
            SDIV    R8, R7, R4
            MOV     R1, R8

posop:      MOV     R5, R2              @Hacerlo con la parte positiva y el resultado va en el R0
            ADD     R5, R5, R3
            LDR     R6, mcons
            MUL     R7, R5, R6
            SDIV    R8, R7, R4
            MOV     R0, R8

exit:       MOV     R7, #1
            SVC     0

aa:         .word   -2
bb:         .word   -3
cc:         .word   -1
mcons:      .word   100000


sqrt:
            CMP     R0, #0              @Verificar si es una raiz negativa
            BLT     sqneg
            B       sqpos      

sqneg:      MOV     R0, #-1             @Si es negativa, dar como resultado -1 y salir
            B       sqexit

sqpos:      MOV     R2, #1              @i
            MOV     R3, #1              @result
            LDR     R4, sqfmult         @Multiplicador
            MUL     R1, R0, R4          @x * 1000

            CMP     R0, #0              @Verificar si x = 0
            BEQ     sqexit

sqop:       CMP     R3, R1              
            BGT     sqendwh
            ADD     R2, R2, #1
            MUL     R3, R2, R2
            B       sqop

sqendwh:    SUB     R3, R2, #1          @Multiplicar el valor final por 10 para cumplir la precision
            LDR     R2, sqlmult
            MUL     R0, R3, R2
sqexit:     bx      lr

sqfmult:    .word   1
sqlmult:    .word   1

.end
