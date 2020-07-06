;功能：显示提示PASSWORD ?，
;      键盘输入字符串与0AB比较
;      相同则输出 Hello world!
;      不同则返回DOs

D       SEGMENT
PASS1   DB '0AB'              ;储存密码
N       EQU $-PASS1           ;密码长度
D1      DB 'PASSWORD ?',0DH,0AH,'$'
PASS2   DB 20
        DB ?
        DB 20 DUP(?)            ;键盘输入缓存
D2      DB 0DH,0AH,'OUTPUT: HELLO WORlD!$'
D       ENDS                            ;数据段
CODE    SEGMENT  ;代码段
        ASSUME CS:CODE,ES:D
BG:     MOV AX,D
        MOV DS,AX       ;D段地址送入DS
        MOV ES,AX
        LEA DX,D1       
        MOV AH,9
        INT 21H         ;显示输入提示
        LEA DX,PASS2
        MOV AH,0AH
        INT 21H         ;输入字符串
        LEA SI,PASS1
        LEA DI,PASS2
 
        MOV CX,N
        LEA DI,PASS2+2
        CLD
        REPZ CMPSB      ;输入字符串与原密码比较
        JZ DISHL
LAST:   MOV AH,4CH      ;返回DOS
        INT 21H
DISHL:  LEA DX,D2       ;屏幕显示helloworld
        MOV AH,9
        INT 21H
        JMP LAST
CODE    ENDS
        END BG;
