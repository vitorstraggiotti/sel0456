# Disciplina SEL0456

## Aula 1

### Assuntos da aula 01:

 * Discussão sobre licenças de software
 * Diferenças entre kernel e sistemas operacionais
 * Definindo kernel
 * Sistemas operacionais
 * Linguagens: C, C++ e Python

## Aula 2

### Assuntos da sula 02:

 * Instalação Linux: os alunos precisam instalar Linux, pelo menos em uma máquina virtual para poder acompanhar o curso.
 * Os alunos precisam abrir uma conta no Github
 * Exemplo de arquivo markdown
 
### Configurando chaves para GitHub (Ubuntu)

A seguir veremos como podemos adicionar chaves ao GitHub com o objetivo de podermos
sicronizar nosso repositorio local com o repositório online.

 1) Gerar novo par de chaves assimetricas
 
Comando: `ssh-keygen -t ed25519 -C "seu_email_git@exemplo.com"`

 * `-t ed25519` --> Especifica o tipo de algoritimo criptográfico utilizado na geração das chaves
 * `-C "seu_email_git@exemplo.com"` --> Especifica o e-mail associado ao par de chaves. Substituir este exemplo pelo seu e-mail no GitHub
 
Ao executar o comando de geração de chaves acima mencionado serão solicitadas duas informações sendo ambas de preenchimento opcional: 

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

Selecionamos a chave publica com o mouse, clicamos com o botão direito do mouse em cima do texto selecionado e depois clicamos em "copiar"
[copy public key](vitorstraggiotti.github.com/sel0456/img/terminal_copy_pub.png)





