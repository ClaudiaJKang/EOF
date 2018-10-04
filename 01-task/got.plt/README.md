## PLT / GOT 

### 1. Source code compile

- Source code 

```c
#include <stdio.h>

void main()
{
	getpid();
	getpid();
}
```

- Complile

```sh
$ gcc -o hello hello.c
```

### 2. Start debugging

#### 1) Disassem main function

```sh
$ gdb hello

gef➤  disass main
Dump of assembler code for function main:
   0x00000000004004e6 <+0>:     push   rbp
   0x00000000004004e7 <+1>:     mov    rbp,rsp
   0x00000000004004ea <+4>:     mov    eax,0x0
   0x00000000004004ef <+9>:     call   0x4003f0 <getpid@plt>
   0x00000000004004f4 <+14>:    mov    eax,0x0
   0x00000000004004f9 <+19>:    call   0x4003f0 <getpid@plt>
   0x00000000004004fe <+24>:    nop
   0x00000000004004ff <+25>:    pop    rbp
   0x0000000000400500 <+26>:    ret    
End of assembler dump.
```

#### 2) Added break point

```sh
gef➤  b *main+9
Breakpoint 2 at 0x4004ef
gef➤  b *main+19
Breakpoint 3 at 0x4004f9
```

#### 3) Run. 

```sh
gef➤  r
─────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────[ registers ]────
$rax   : 0x0               
$rbx   : 0x0               
$rcx   : 0x7ffff7dd0718      →  0x00007ffff7dd1d80  →  0x0000000000000000
$rdx   : 0x7fffffffdc08      →  0x00007fffffffdff9  →  "COLORFGBG=15;0"
$rsp   : 0x7fffffffdb10      →  0x0000000000400510  →  <__libc_csu_init+0> push r15
$rbp   : 0x7fffffffdb10      →  0x0000000000400510  →  <__libc_csu_init+0> push r15
$rsi   : 0x7fffffffdbf8      →  0x00007fffffffdfc5  →  "/home/claudia/git/uftrace/EOF/01-task/got.plt/hell[...]"
$rdi   : 0x1               
$rip   : 0x4004ef            →  <main+9> call 0x4003f0 <getpid@plt>
$eflags: [ZERO carry PARITY adjust sign trap INTERRUPT direction overflow resume virtualx86 identification]
$ds: 0x0000  $cs: 0x0033  $fs: 0x0000  $es: 0x0000  $ss: 0x002b  $gs: 0x0000  
─────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────[ stack ]────
0x00007fffffffdb10│+0x00: 0x0000000000400510  →  <__libc_csu_init+0> push r15    ← $rsp, $rbp
0x00007fffffffdb18│+0x08: 0x00007ffff7a3a11b  →  <__libc_start_main+235> mov edi, eax
0x00007fffffffdb20│+0x10: 0x0000000000000000
0x00007fffffffdb28│+0x18: 0x00007fffffffdbf8  →  0x00007fffffffdfc5  →  "/home/claudia/git/uftrace/EOF/01-task/got.plt/hell[...]"
0x00007fffffffdb30│+0x20: 0x0000000100040000
0x00007fffffffdb38│+0x28: 0x00000000004004e6  →  <main+0> push rbp
0x00007fffffffdb40│+0x30: 0x0000000000000000
0x00007fffffffdb48│+0x38: 0x78321b3c21dfd5bc
──────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────[ code:i386:x86-64 ]────
     0x4004e5 <frame_dummy+5>  mov    dl, BYTE PTR [rbp+0x48]
     0x4004e8 <main+2>         mov    ebp, esp
     0x4004ea <main+4>         mov    eax, 0x0
 →   0x4004ef <main+9>         call   0x4003f0 <getpid@plt>
   ↳    0x4003f0 <getpid@plt+0>   jmp    QWORD PTR [rip+0x200c22]        # 0x601018
        0x4003f6 <getpid@plt+6>   push   0x0
        0x4003fb <getpid@plt+11>  jmp    0x4003e0
        0x400400 <_start+0>       xor    ebp, ebp
        0x400402 <_start+2>       mov    r9, rdx
        0x400405 <_start+5>       pop    rsi
───────────────────────────────────────────────────────────────────────────────────────────────────────────────────────[ arguments (guessed) ]────
getpid@plt (
)
──────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────

Breakpoint 1, 0x00000000004004ef in main ()
```