section .rodata
    const1 dq 2.0
    coef2 dq -2.0
    const2 dq 8.0
    coef3 dq -5.0

global f1
global f2
global f3
global df1
global df2
global df3

f1: ;= exp(x) + 2
    push ebp
    mov ebp, esp    
    finit 
    fldl2e
    fmul qword[ebp + 8]
    fld1
    fld st1
    fprem
    f2xm1
    faddp
    fscale
    fstp st1
    fadd qword[const1]
    leave
    ret
    
f2: ;= -2x + 8
    push ebp
    mov ebp, esp    
    finit
    fld qword[ebp + 8]
    fmul qword[coef2]
    fadd qword[const2]
    leave
    ret
    
f3: ;= -5 / x
    push ebp
    mov ebp, esp
    finit
    fld qword[coef3]
    fdiv qword[ebp + 8]
    leave
    ret

df1: ;= exp(x)
    push ebp
    mov ebp, esp    
    finit 
    fldl2e
    fmul qword[ebp + 8]
    fld1
    fld st1
    fprem
    f2xm1
    faddp
    fscale
    fstp st1
    leave
    ret    
            
df2: ;= -2
    push ebp
    mov ebp, esp
    finit
    fld qword[coef2]
    leave
    ret
    
df3: ;= 5 / (x^2)
    push ebp
    mov ebp, esp
    finit
    fld qword[coef3]
    fchs
    fdiv qword[ebp + 8]
    fdiv qword[ebp + 8]
    leave
    ret
