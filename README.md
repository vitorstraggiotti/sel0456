# Disciplina SEL0456

## Aula 1

### Assuntos da aula:

- Discussão sobre licenças de software
- Diferenças entre kernel e sistemas operacionais
- Sistemas operacionais
- Kernel - funções:
    1. gerenciamento de tarefas
    2. comunicação entre processos
    3. gerenciamento de memória

## Aula 2

### Assuntos da aula:

- Instalação Linux: os alunos precisam instalar Linux, pelo menos em uma máquina virtual para poder acompanhar o curso.
- Os alunos precisam abrir uma conta no Github
- Exemplo de arquivo [markdown](https://guides.github.com/pdfs/markdown-cheatsheet-online.pdf)
- [Criação da chave ssh para GitHub](./texto/tutorial_chaves_github.md)
- Commit para o github
- Utilizaremos as linguagens: C, C++ e Python

## Aula 3

### Assuntos da aula:

- Estrutura de programas em C
	1. Arquivos de código fonte (.c)
	2. Arquivos objeto (.o)
	3. Arquivos de cabeçalho (.h)
- Compilador GCC e suas flags
- Makefile:
    Para criação e utilização do makefile no VS Code é necessário instalar uma extensão chamada Makefile Tools.
    Para instalar abra o Quick Open (Ctrl + P) e cole o seguinte comando:
    `ext install ms-vscode.makefile-tools`

## Aula 4

### Assuntos da aula:

- Aplicação do qualificador `static`, `volatile`
- Criação de arquivo `.gitignore`
- Realizando 'merge' no repositorio do GitHub
- Utilizando threads
	1. `pthread_create()`
	2. `pthread_join()`
	3. `pthread_exit()`

## Aula 5 (02/09)

### Assuntos da aula:

- Processos: criando processos com `fork` e `exec`
- Usando `man <fcn>` para obter documentação sobre função `<fcn>`
- Uso de semaforo (semaphore.h)
	1. `sem_init()`
	2. `sem_wait()`
	3. `sem_post()`

# Aula 6 (09/09)

Assuntos da aula:

- cmake
- argp
- popen
- pipe
- malloc

# Aula 7

Assuntos da aula 7:

- gdb
- lib electric-fence (-lefence)
- aasert
- esp32: esp-idf:

```
$ cd ~
$ mkdir esp
$ cd esp
$ git clone -b v4.3 --recursive https://github.com/espressif/esp-idf.git
$ cd esp-idf
$ ./install.sh
```

O processo de instalação está finalizado nesse ponto.

Pode-se copiar um exemplo, dos vários disponíveis e rodar:

```
$ cd ~
$ mkdir Code
$ cd Code
$ cp -a ~/esp/esp-idf/examples/peripherals/ledc .
$ cd ledc
$ . ~/esp/esp-idf/export.sh
```

Para editar o exemplo:
```
$ emacs main/ledc_example_main.c
```

```
$ idf.py menuconfig
$ idf.py build
$ idf.py -p /dev/ttyUSB0 flash monitor
```
