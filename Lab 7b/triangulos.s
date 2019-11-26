@ as -g -o cuadratica.o cuadratica.s
@ ld -o cuadratica cuadratica.o
@ gdb cuadratica

@ r (run)
@ b 7 (line brak at line 7)
@ i r (info registers)
@ q (quit)

.text
.global _start

_start:
            MOV     R0, #38
            BL      sqrt

            MOV     R7, #1
            SVC     0
            

sqrt:
            CMP     R0, #0              @Verificar si es una raiz negativa
            BLT     sqneg
            B       sqpos      

sqneg:      MOV     R0, #-1             @Si es negativa, dar como resultado -1 y salir
            B       sqexit

sqpos:      BEQ     sqexit              @Verificar si x = 0 y si es asi retornar

sqop:       CMP     R3, R0              
            BGT     sqendwh
            ADD     R2, R2, #1
            MUL     R3, R2, R2
            B       sqop

sqendwh:    SUB     R3, R2, #1          @Restarle 1 al valor final
            MOV     R0, R3

sqexit:     bx      lr
