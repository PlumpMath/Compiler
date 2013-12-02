
shit.o:     file format elf32-i386


Disassembly of section .text:

00000000 <f>:
   0:	55                   	push   %ebp
   1:	89 e5                	mov    %esp,%ebp
   3:	8b 45 0c             	mov    0xc(%ebp),%eax
   6:	8b 55 08             	mov    0x8(%ebp),%edx
   9:	01 d0                	add    %edx,%eax
   b:	5d                   	pop    %ebp
   c:	c3                   	ret    

0000000d <main>:
   d:	55                   	push   %ebp
   e:	89 e5                	mov    %esp,%ebp
  10:	83 ec 18             	sub    $0x18,%esp
  13:	c7 44 24 04 02 00 00 	movl   $0x2,0x4(%esp)
  1a:	00 
  1b:	c7 04 24 01 00 00 00 	movl   $0x1,(%esp)
  22:	e8 fc ff ff ff       	call   23 <main+0x16>
  27:	89 45 fc             	mov    %eax,-0x4(%ebp)
  2a:	c7 44 24 04 02 00 00 	movl   $0x2,0x4(%esp)
  31:	00 
  32:	c7 04 24 01 00 00 00 	movl   $0x1,(%esp)
  39:	e8 fc ff ff ff       	call   3a <main+0x2d>
  3e:	89 45 fc             	mov    %eax,-0x4(%ebp)
  41:	c7 44 24 04 02 00 00 	movl   $0x2,0x4(%esp)
  48:	00 
  49:	c7 04 24 01 00 00 00 	movl   $0x1,(%esp)
  50:	e8 fc ff ff ff       	call   51 <main+0x44>
  55:	89 45 fc             	mov    %eax,-0x4(%ebp)
  58:	b8 01 00 00 00       	mov    $0x1,%eax
  5d:	c9                   	leave  
  5e:	c3                   	ret    
