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
    ext install ms-vscode.makefile-tools

Ao executar o comando de geração de chaves acima mencionado serão solicitadas duas informações, sendo ambas de preenchimento opcional: 

Informar o Local de salvamento e nome das chaves: `~/.ssh/GitHub`

Informar senha e repeti-la (caso não queira, pressionar enter)

2) Verificar se o programa gerenciador do SSH está funcionando em segundo plano

Comando: `eval "$(ssh-agent -s)"`

Ao executar o comando devemos ver na tela um numero "pid", o que significa que o processo referente ao gerenciador do SSH está funcionando

3) Adicionar a chave gerada anteriormente no gerenciador do SSH
 
Comando: `ssh-add ~/.ssh/GitHub`

 * `~/.ssh/GitHub` --> Especifica o local em que as chaves foram salvas
 
4) Adicionar a chave publica no GitHub
 
Primeiramente devemos copiar a chave publica que acabamos de gerar.

Comando: `cat ~/.ssh/GitHub.pub`

 * Este comando `cat` imprime na tela o conteudo do arquivo `~/.ssh/GitHub.pub` que foi passado como argumento

Selecionamos a chave publica com o mouse, clicamos com o botão direito do mouse em cima do texto selecionado e depois clicamos em "copiar". [Imagem exemplo.](https://github.com/vitorstraggiotti/sel0456/blob/main/img/terminal_copy_pub.png)

Com a chave publica copiada vamos ao GitHub e seguimos o seginte caminho: 

[Settings](https://docs.github.com/assets/images/help/settings/userbar-account-settings.png) -->
[SSH and GPG keys](https://docs.github.com/assets/images/help/settings/settings-sidebar-ssh-keys.png) -->
[New SSH key](https://docs.github.com/assets/images/help/settings/ssh-add-ssh-key.png)

Criar um titulo para sua chave (ex: computador casa, ubuntu, etc) e em seguida colar a chave no campo "key" e clicar em "add SSH key". [Imagem exemplo](https://docs.github.com/assets/images/help/settings/ssh-key-paste.png)

Agora seu computador e o site do GitHub podem se comunicar sem a necessidade de senhas cada vez que quiser sincronizar o seu repositorio local com o online.

DICA: Caso pretenda fazer o upload de alterações no repositorio local para o GitHub (será o caso desta diciplina) você deve clonar o repositorio utilizando o link referente a aba SSH. [Imagem exemplo](https://github.com/vitorstraggiotti/sel0456/blob/main/img/aba_SSH.png) 

