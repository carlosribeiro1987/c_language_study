# Plano de Estudos Avançado em C com Foco em Sistemas Operacionais

## Objetivo

Atingir nível avançado em C aplicado a programação de sistemas, arquitetura de computadores, concorrência, sistemas operacionais, leitura de kernels didáticos como xv6 e entrada prática em OSDev.

---

## 1. Ambiente de Desenvolvimento

### Tópicos

- Linux como ambiente principal
- Terminal, shell, processos e permissões
- GCC e Clang
- Makefiles
- GDB
- Valgrind
- Sanitizers
- `strace`, `ltrace`, `perf`
- Git
- QEMU
- WSL, máquina virtual ou Linux nativo

### Materiais

- [GNU Make Manual](https://www.gnu.org/software/make/manual/)
- [GDB Documentation](https://sourceware.org/gdb/current/onlinedocs/gdb.html)
- [Valgrind Quick Start](https://valgrind.org/docs/manual/quick-start.html)
- [Clang AddressSanitizer](https://clang.llvm.org/docs/AddressSanitizer.html)
- [Linux man-pages - man7](https://man7.org/linux/man-pages/index.html)
- [QEMU Documentation](https://www.qemu.org/docs/master/)
- [Microsoft WSL Documentation](https://learn.microsoft.com/en-us/windows/wsl/)

### Por que estudar isso

C para sistemas operacionais não é apenas escrever código. Você precisa compilar, depurar, inspecionar chamadas de sistema, entender comportamento em tempo de execução e reproduzir bugs de memória. Ferramentas como GDB, Valgrind, sanitizers e `strace` tornam visível o que normalmente fica escondido.

### Exercícios práticos

- Configure um projeto C com esta estrutura:

```text
projeto/
  src/
  include/
  tests/
  Makefile
  README.md
```

- Compile programas usando flags rigorosas:

```sh
cc -std=c17 -Wall -Wextra -Wpedantic -Werror -g \
  -fsanitize=address,undefined \
  -o app src/main.c
```

- Rode o mesmo programa com:

```sh
gdb --args ./app entrada.txt
valgrind --leak-check=full ./app
strace -f ./app
```

- Escreva um `Makefile` com alvos `build`, `test`, `debug`, `clean` e `sanitize`.

---

## 2. C Intermediário

### Tópicos

- Ponteiros e aritmética de ponteiros
- Arrays e strings em C
- `struct`, `union`, `enum`
- Alocação dinâmica com `malloc`, `calloc`, `realloc`, `free`
- Organização em `.h` e `.c`
- Escopo, linkage, `static`, `extern`
- Entrada e saída com `stdio`
- Manipulação de arquivos
- `errno` e tratamento de erros
- Pré-processador
- Compilação separada

### Materiais

- [Beej's Guide to C Programming](https://beej.us/guide/bgc/)
- [cppreference - C](https://en.cppreference.com/w/c)
- [C FAQ](https://c-faq.com/)
- [SEI CERT C Coding Standard](https://wiki.sei.cmu.edu/confluence/display/c)

### Por que estudar isso

Sistemas operacionais exigem controle explícito de memória, layouts de dados previsíveis e compreensão exata do que o compilador faz. Nesta fase, o objetivo é sair do "C que parece Python com ponto e vírgula" e passar a pensar em bytes, endereços, tempo de vida de objetos e contratos de API.

### Exercícios práticos

- Implemente uma biblioteca de string dinâmica.
- Escreva um parser simples de CSV sem usar bibliotecas externas.
- Implemente um vetor dinâmico genérico usando `void *`.
- Crie uma biblioteca pequena com `.h`, `.c`, testes e `Makefile`.
- Faça um programa que leia um arquivo grande linha por linha sem carregar tudo na memória.

---

## 3. C Avançado

### Tópicos

- Undefined behavior
- Alignment
- Strict aliasing
- Object representation
- Endianness
- Layout de structs e padding
- Ponteiros para função
- Macros seguras
- APIs genéricas em C
- `volatile`
- `_Atomic`
- Compilação, linkedição e símbolos
- ABI e convenções de chamada
- Otimização e inspeção de assembly

### Materiais

- [cppreference - Undefined behavior](https://en.cppreference.com/w/c/language/behavior)
- [Compiler Explorer](https://godbolt.org/)
- [GCC Online Documentation](https://gcc.gnu.org/onlinedocs/)
- [Clang UndefinedBehaviorSanitizer](https://clang.llvm.org/docs/UndefinedBehaviorSanitizer.html)
- [System V AMD64 ABI](https://gitlab.com/x86-psABIs/x86-64-ABI)
- [SEI CERT C Coding Standard](https://wiki.sei.cmu.edu/confluence/display/c)

### Por que estudar isso

Código de baixo nível frequentemente depende de detalhes que não aparecem em tutoriais básicos. Um erro de aliasing, alinhamento ou overflow assinado pode gerar código aparentemente correto em `-O0` e quebrado em `-O2`. Para escrever C avançado, você precisa saber o que a linguagem garante, o que o compilador assume e o que a arquitetura realmente executa.

### Exercícios práticos

- Escreva exemplos pequenos de undefined behavior e observe diferenças entre `-O0`, `-O2` e `-O3`.
- Use [Compiler Explorer](https://godbolt.org/) para comparar o assembly gerado por diferentes versões da mesma função.
- Implemente macros de lista ligada intrusiva no estilo kernel.
- Escreva uma arena allocator.
- Implemente um sistema simples de dispatch com ponteiros para função.
- Crie testes que rodem com AddressSanitizer e UndefinedBehaviorSanitizer.

---

## 4. Estruturas de Dados em C

### Tópicos

- Vetor dinâmico
- Lista ligada simples e dupla
- Pilha
- Fila
- Deque
- Hash table
- Árvore binária
- Heap binário
- Ring buffer
- Arena allocator
- Pool allocator
- Estruturas intrusivas
- Iteradores manuais
- Estratégias de ownership

### Materiais

- [Ben Hoyt - How to implement a hash table in C](https://benhoyt.com/writings/hash-table-in-c/)
- [CS:APP Labs](https://csapp.cs.cmu.edu/3e/labs.html)
- [Open Data Structures](https://opendatastructures.org/)
- [Beej's Guide to C Programming](https://beej.us/guide/bgc/)

### Por que estudar isso

O kernel e a programação de sistemas usam estruturas de dados com restrições fortes: pouca alocação dinâmica, previsibilidade, baixo overhead e controle de cache. Implementar essas estruturas em C força você a lidar com ownership, desalocação, ponteiros inválidos e invariantes.

### Exercícios práticos

- Implemente uma hash table com open addressing.
- Implemente uma lista ligada intrusiva parecida com a do Linux.
- Crie um ring buffer para logs.
- Implemente uma fila bloqueante depois de estudar threads.
- Escreva um allocator de arena e use-o em um parser.
- Compare performance de lista ligada, vetor e hash table usando dados reais.

---

## 5. Programação de Sistemas em Linux/Unix

### Tópicos

- Chamadas de sistema
- Descritores de arquivo
- `open`, `read`, `write`, `close`
- `stat`, permissões e diretórios
- Pipes
- Redirecionamento
- `fork`, `exec`, `wait`
- Sinais
- `mmap`
- Terminais
- Sockets
- `select`, `poll`, `epoll`
- Daemons
- IPC

### Materiais

- [The Linux Programming Interface - man7](https://www.man7.org/tlpi/index.html)
- [TLPI online code](https://man7.org/tlpi/code/online/index.html)
- [Linux man-pages - man7](https://man7.org/linux/man-pages/index.html)
- [Brennan - Write a Shell in C](https://brennan.io/2015/01/16/write-a-shell-in-c/)
- [Beej's Guide to Network Programming](https://beej.us/guide/bgnet/)
- [man7 - intro(2)](https://man7.org/linux/man-pages/man2/intro.2.html)

### Por que estudar isso

Sistemas operacionais são acessados por programas de usuário através de chamadas de sistema. Antes de escrever ou modificar um kernel, você precisa entender bem a interface que ele oferece: arquivos, processos, memória virtual, sinais, comunicação e rede.

### Exercícios práticos

- Implemente `cat`, `cp`, `wc` e `grep` simplificados usando apenas syscalls.
- Escreva um mini shell com `fork`, `execvp`, `waitpid`, pipes e redirecionamento.
- Implemente um servidor TCP echo.
- Implemente um servidor concorrente usando `fork`.
- Refaça o servidor usando threads.
- Refaça o servidor usando `epoll`.
- Use `strace` para comparar seu programa com utilitários reais do Linux.

---

## 6. Arquitetura de Computadores

### Tópicos

- Representação binária
- Inteiros com sinal
- Complemento de dois
- Ponto flutuante
- Endianness
- Stack e heap
- Registradores
- Assembly básico
- Calling convention
- Cache
- Localidade de referência
- Pipeline
- Memória virtual
- TLB
- Interrupções e exceções
- User mode e kernel mode

### Materiais

- [CS:APP Official Site](https://csapp.cs.cmu.edu/3e/home.html)
- [CS:APP Labs](https://csapp.cs.cmu.edu/3e/labs.html)
- [Computer Systems: A Programmer's Perspective Resources](https://csapp.cs.cmu.edu/3e/students.html)
- [RISC-V Reader](https://www.riscvbook.com/)
- [Compiler Explorer](https://godbolt.org/)

### Por que estudar isso

Um sistema operacional é a camada que coordena hardware e software. Sem entender registradores, traps, page tables, caches e ABI, muitos conceitos de kernel ficam abstratos demais. Arquitetura também explica por que C é tão usado em sistemas: ele permite expressar operações próximas ao hardware sem abandonar completamente abstrações de alto nível.

### Exercícios práticos

- Escreva funções simples em C e analise o assembly gerado.
- Meça o impacto de cache percorrendo matrizes por linha e por coluna.
- Implemente uma calculadora de endianness.
- Escreva uma função em assembly chamada a partir de C.
- Simule uma TLB pequena em C.
- Faça os labs selecionados de CS:APP: Data Lab, Bomb Lab, Attack Lab e Malloc Lab.

---

## 7. Concorrência e Paralelismo

### Tópicos

- Threads POSIX
- Corridas de dados
- Mutex
- Condition variables
- Semáforos
- Barriers
- Deadlock
- Starvation
- Atomics em C
- Modelo de memória
- False sharing
- Thread pools
- Produtor-consumidor
- Estruturas thread-safe
- Debugging com ThreadSanitizer

### Materiais

- [OSTEP - Operating Systems: Three Easy Pieces](https://pages.cs.wisc.edu/~remzi/OSTEP/)
- [man7 - pthreads(7)](https://man7.org/linux/man-pages/man7/pthreads.7.html)
- [man7 - pthread_mutex_lock(3)](https://man7.org/linux/man-pages/man3/pthread_mutex_lock.3p.html)
- [cppreference - Atomic operations](https://en.cppreference.com/w/c/atomic)
- [Clang ThreadSanitizer](https://clang.llvm.org/docs/ThreadSanitizer.html)

### Por que estudar isso

Concorrência é central em sistemas operacionais: escalonadores, locks de kernel, drivers, filas de I/O, interrupções e sistemas de arquivos precisam coordenar múltiplos fluxos de execução. Em C, erros de concorrência costumam ser silenciosos e difíceis de reproduzir.

### Exercícios práticos

- Implemente produtor-consumidor com mutex e condition variable.
- Implemente uma thread pool.
- Crie uma fila bloqueante.
- Escreva um contador concorrente e compare mutex, atomic e sharding por thread.
- Produza intencionalmente uma race condition e detecte com ThreadSanitizer.
- Implemente uma barreira reutilizável.
- Simule deadlock e depois corrija com ordenação global de locks.

---

## 8. Sistemas Operacionais

### Tópicos

- Processos
- Threads
- Escalonamento
- Context switch
- Syscalls
- Traps
- Interrupções
- Memória virtual
- Page tables
- Demand paging
- Copy-on-write
- Allocator de kernel
- Sistemas de arquivos
- Journaling
- Cache de blocos
- Drivers
- IPC
- Segurança e isolamento

### Materiais

- [OSTEP - Operating Systems: Three Easy Pieces](https://pages.cs.wisc.edu/~remzi/OSTEP/)
- [MIT 6.1810 Operating System Engineering](https://pdos.csail.mit.edu/6.1810/)
- [MIT OpenCourseWare - 6.1810 Operating System Engineering](https://ocw.mit.edu/courses/6-1810-operating-system-engineering-fall-2023/)
- [Linux man-pages - man7](https://man7.org/linux/man-pages/index.html)
- [TLPI - man7](https://www.man7.org/tlpi/index.html)

### Por que estudar isso

Aqui você começa a ligar a API de usuário ao funcionamento interno do kernel. `fork`, por exemplo, deixa de ser apenas uma função e passa a envolver page tables, descritores de arquivo, escalonamento e copy-on-write. O objetivo é entender os mecanismos, não apenas decorar nomes.

### Exercícios práticos

- Simule algoritmos de escalonamento: FCFS, SJF, round-robin e MLFQ.
- Implemente um simulador de page replacement: FIFO, LRU e Clock.
- Crie um sistema de arquivos simples dentro de um arquivo binário.
- Implemente um cache de blocos com política LRU.
- Escreva um interpretador de syscalls fictícias para entender fronteira usuário/kernel.
- Leia capítulos de OSTEP e implemente versões pequenas dos conceitos em C.

---

## 9. xv6

### Tópicos

- Build e execução com QEMU
- Organização do código do xv6
- Boot
- Traps
- Syscalls
- Processos
- Page tables
- Allocator físico
- Scheduler
- File system
- Buffer cache
- Locks
- Drivers simples
- Labs do MIT 6.S081/6.1810

### Materiais

- [xv6 book - MIT 6.1810 2025](https://pdos.csail.mit.edu/6.1810/2025/xv6/book-riscv-rev5.pdf)
- [MIT 6.1810 Course Site](https://pdos.csail.mit.edu/6.1810/)
- [MIT 6.S081 xv6 page](https://pdos.csail.mit.edu/6.S081/2021/xv6.html)
- [xv6-riscv source](https://github.com/mit-pdos/xv6-riscv)
- [xv6-riscv book source](https://github.com/mit-pdos/xv6-riscv-book)

### Por que estudar isso

xv6 é pequeno o suficiente para ser lido por uma pessoa, mas real o suficiente para ensinar syscalls, traps, memória virtual, escalonamento e sistema de arquivos. Ele é o ponto ideal entre teoria de SO e OSDev do zero.

### Exercícios práticos

- Compile e rode xv6 no QEMU.
- Adicione uma syscall `trace`.
- Adicione uma syscall que retorna estatísticas do processo atual.
- Modifique o scheduler para registrar decisões de escalonamento.
- Implemente lazy allocation.
- Implemente copy-on-write fork.
- Adicione uma chamada de sistema para listar processos.
- Modifique o file system para armazenar metadados extras.
- Leia um arquivo do código do xv6 por dia e escreva notas sobre as funções principais.

---

## 10. OSDev

### Tópicos

- Freestanding C
- Cross compiler
- Linker scripts
- Bootloaders
- Multiboot
- Limine ou GRUB
- Serial output
- VGA text mode ou framebuffer
- GDT
- IDT
- Interrupções
- Paging
- Physical memory manager
- Virtual memory manager
- Kernel heap
- Drivers básicos
- Timer
- Teclado
- Syscalls
- ELF loading
- User mode
- Filesystem simples

### Materiais

- [OSDev Wiki](https://wiki.osdev.org/Main_Page)
- [OSDev - Getting Started](https://wiki.osdev.org/Getting_Started)
- [OSDev - Bare Bones](https://wiki.osdev.org/Bare_Bones)
- [OSDev - GCC Cross Compiler](https://wiki.osdev.org/GCC_Cross-Compiler)
- [OSDev - Linker Scripts](https://wiki.osdev.org/Linker_Scripts)
- [OSDev - Expanded Main Page](https://wiki.osdev.org/Expanded_Main_Page)
- [QEMU Documentation](https://www.qemu.org/docs/master/)

### Por que estudar isso

OSDev é onde você deixa de apenas estudar sistemas operacionais e começa a construir um. É uma área difícil porque quase nada está disponível por padrão: biblioteca padrão, alocador, syscalls, arquivos, processos e drivers precisam ser criados ou trazidos explicitamente. Por isso, OSDev deve vir depois de uma boa base em C, arquitetura, sistemas e xv6.

### Exercícios práticos

- Configure um cross compiler.
- Crie um kernel mínimo que imprime texto pela serial.
- Escreva um linker script próprio.
- Rode o kernel no QEMU.
- Configure uma IDT e trate uma interrupção.
- Implemente um physical frame allocator.
- Ative paging.
- Crie um kernel heap simples.
- Implemente um timer interrupt.
- Implemente um scheduler cooperativo simples.
- Carregue um programa ELF em modo usuário.

---

## 11. Projetos Progressivos

### Projeto 1: Biblioteca Base em C

Crie uma biblioteca com:

- String dinâmica
- Vetor dinâmico
- Hash table
- Arena allocator
- Testes
- Makefile
- Sanitizers

Objetivo: dominar memória, ownership e APIs reutilizáveis.

### Projeto 2: Utilitários Unix

Implemente versões pequenas de:

- `cat`
- `cp`
- `ls`
- `wc`
- `grep`
- `tee`

Objetivo: dominar arquivos, diretórios, erros e syscalls.

### Projeto 3: Mini Shell

Implemente:

- Execução de comandos
- Argumentos
- Pipes
- Redirecionamento
- Variáveis de ambiente
- Builtins como `cd`, `exit`, `pwd`
- Sinais básicos

Base: [Brennan - Write a Shell in C](https://brennan.io/2015/01/16/write-a-shell-in-c/)

### Projeto 4: Servidor Concorrente

Implemente:

- Servidor TCP echo
- Servidor HTTP mínimo
- Versão com `fork`
- Versão com threads
- Versão com `epoll`

Base: [Beej's Guide to Network Programming](https://beej.us/guide/bgnet/)

### Projeto 5: Simulador de SO

Implemente:

- Scheduler
- Page replacement
- Sistema de arquivos em arquivo binário
- Cache de blocos
- Métricas de desempenho

Base: [OSTEP](https://pages.cs.wisc.edu/~remzi/OSTEP/)

### Projeto 6: xv6 Modificado

Implemente mudanças reais no xv6:

- Syscalls novas
- Scheduler alterado
- Lazy allocation
- Copy-on-write
- Estatísticas de processos
- Melhorias pequenas no file system

Base: [MIT 6.1810](https://pdos.csail.mit.edu/6.1810/)

### Projeto 7: Kernel Próprio

Implemente um kernel mínimo:

- Boot
- Serial logging
- Interrupções
- Paging
- Allocator físico
- Heap de kernel
- Timer
- Scheduler inicial

Base: [OSDev Wiki](https://wiki.osdev.org/Main_Page)

---

## 12. Ordem Recomendada de Estudo

| Fase | Foco | Resultado esperado |
|---|---|---|
| 1 | Ambiente Linux, GCC, Make, GDB, Valgrind | Você compila, depura e inspeciona programas C com autonomia |
| 2 | C intermediário | Você escreve programas C organizados em múltiplos arquivos |
| 3 | Estruturas de dados | Você controla memória, ownership e invariantes |
| 4 | C avançado | Você entende UB, ABI, otimização, alinhamento e assembly |
| 5 | Programação de sistemas | Você usa syscalls diretamente e entende processos/arquivos |
| 6 | Arquitetura | Você entende stack, heap, cache, page tables e traps |
| 7 | Concorrência | Você escreve código multithread correto e depura races |
| 8 | Sistemas operacionais com OSTEP | Você entende os conceitos centrais de um kernel |
| 9 | xv6 | Você lê e modifica um kernel didático real |
| 10 | OSDev | Você começa um kernel próprio com base sólida |

Ordem prática sugerida:

1. Beej's Guide to C Programming
2. Projetos pequenos em C com Make, GDB e sanitizers
3. Estruturas de dados em C
4. Ben Hoyt hash table
5. CS:APP, principalmente arquitetura, memória e malloc lab
6. TLPI/man7 para programação Linux
7. Brennan shell tutorial
8. Beej's Guide to Network Programming
9. OSTEP
10. xv6 book e labs do MIT 6.S081/6.1810
11. OSDev Wiki

---

## 13. Dicas Práticas

- Estude sempre em ciclos: leia, implemente, modifique, quebre, depure e documente.
- Não avance em OSDev antes de conseguir escrever um shell simples em C.
- Use Linux como ambiente principal. C para sistemas depende muito de POSIX, syscalls e ferramentas Unix.
- Compile sempre com warnings fortes.
- Use sanitizers desde o começo.
- Leia man pages diretamente. Tutoriais ajudam, mas a especificação real da API está nas páginas `man`.
- Escreva testes pequenos para cada estrutura de dados.
- Evite copiar código de kernel sem entender o contrato de cada função.
- Faça commits pequenos e escreva mensagens claras.
- Meça antes de otimizar.
- Ao estudar xv6, leia primeiro o fluxo completo de uma syscall simples.
- Ao estudar memória virtual, desenhe page tables no papel.
- Ao estudar concorrência, tente reproduzir bugs de corrida de propósito.
- Ao entrar em OSDev, mantenha logs pela serial desde o início.

---

## 14. Erros Comuns

- Tratar C como uma linguagem de alto nível comum e ignorar tempo de vida da memória.
- Achar que ponteiro é apenas "variável que guarda endereço" sem entender ownership.
- Usar `malloc` em todo lugar sem estratégia de desalocação.
- Ignorar undefined behavior porque "funcionou na minha máquina".
- Depurar apenas com `printf`.
- Não usar `gdb`, `valgrind`, sanitizers e `strace`.
- Estudar sistemas operacionais só por vídeos, sem implementar simuladores ou modificar código.
- Começar OSDev antes de entender processos, page tables, interrupções e linkedição.
- Usar threads sem modelo claro de locks.
- Confundir concorrência com paralelismo.
- Ler xv6 de forma linear sem seguir fluxos concretos como syscall, page fault ou context switch.
- Otimizar estruturas de dados antes de validar corretude.
- Não escrever documentação própria do que foi aprendido.

---

## 15. Critério de Nível Avançado

Você estará em nível avançado em C com foco em sistemas operacionais quando conseguir:

- Escrever bibliotecas C seguras e testáveis.
- Depurar corrupção de memória com ferramentas apropriadas.
- Explicar o assembly gerado por funções C relevantes.
- Implementar estruturas de dados com ownership claro.
- Usar syscalls POSIX diretamente.
- Implementar um shell funcional.
- Escrever programas concorrentes com pthreads.
- Explicar processos, threads, page tables, traps, syscalls e escalonamento.
- Modificar xv6 com segurança.
- Inicializar um kernel próprio no QEMU.
- Implementar interrupções, paging e alocação básica de memória em ambiente freestanding.
