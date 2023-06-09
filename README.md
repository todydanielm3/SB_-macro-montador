# Projeto Software Bâsico - Prof. Bruno Macchiavello.  
Daniel Moraes da Silva.  
Rafael dos Santos Silva. 

# MONTADOR 
Este é um projeto de macro-montado, implementado em linguagem C. O programa é capaz de traduzir códigos assembly em um arquivo de entrada e gerar um arquivo objeto com o código traduzido.


## Funcionalidades

O montador possui as seguintes funcionalidades:

- Aceita um arquivo de entrada .asm contendo o código assembly a ser traduzido.
- Realiza a tradução do código assembly, gerando um arquivo objeto com o código traduzido.
- Mantém a formatação adequada do arquivo de entrada e do arquivo objeto, respeitando os requisitos do projeto.
- Aceita as instruções e modos de endereçamento especificados para o assembly fictício utilizado.

## Pré-requisitos

- Compilador C (por exemplo, GCC) para compilar o programa.
- Arquivo de entrada .asm contendo o código assembly a ser traduzido.


## N diretorio Montador - Compilação

Para compilar o programa montador.c, execute o seguinte comando no terminal:

```
gcc montador.c -o montador
```

## Execução

Para executar o programa montador, utilize o seguinte comando no terminal:

```
./montador arquivo.asm
```

Certifique-se de substituir "arquivo.asm" pelo nome real do arquivo de entrada que você deseja traduzir.

## Exemplo de Uso

Aqui está um exemplo de uso do programa montador com um arquivo de entrada:

```
./montador teste.asm
```

O programa irá realizar a tradução do arquivo teste.asm e gerar o arquivo texto de objeto correspondente de sáida.

## Instruções do Montador

O montador aceita as seguintes instruções para o assembly fictício utilizado:

- MOV OP1 OP2: Move o valor de OP2 para OP1.
- ADD OP1 OP2: Soma OP1 e OP2, armazenando o resultado em OP1.
- SUB OP1 OP2: Subtrai OP2 de OP1, armazenando o resultado em OP1.
- MUL OP1: Realiza a multiplicação considerando o sinal e armazena o resultado no acumulador.
- DIV OP1: Realiza a divisão considerando o sinal, armazenando o cociente em um registrador específico.
- INC OP1: Incrementa o valor de OP1.
- DEC OP1: Decrementa o valor de OP1.
- CMP OP1 OP2: Compara os valores de OP1 e OP2 e atualiza os FLAGS.
- JMP Label: Realiza um salto incondicional para a instrução com o rótulo Label.
- CALL Label: Realiza uma chamada de sub-rotina para a instrução com o rótulo Label.
- RET: Retorna de uma sub-rotina.
- ...

Consulte o arquivo de instruções anexado nesse projeto.


---

# LIGADOR 
Este é um projeto de ligador de macro montador, implementado

 em linguagem C. O programa é capaz de receber até 4 arquivos objeto gerados pelo montador e realizar a ligação entre eles, gerando um único arquivo executável.

## Funcionalidades

O ligador possui as seguintes funcionalidades:

- Aceita até 4 arquivos objeto gerados pelo montador como entrada.
- Realiza a ligação entre os arquivos objeto, gerando um único arquivo executável.
- Mantém a formatação adequada do arquivo de saída, respeitando os requisitos do projeto.
- Verifica a correta sequência das diretivas EXTERN e PUBLIC nos arquivos objeto.
- Gera as seções de USO, DEF, REF e CODE no arquivo executável, conforme especificado.

## Compilação

Para compilar o programa ligador.c, execute o seguinte comando no terminal:

```
gcc ligador.c -o ligador
```

## Execução

Para executar o programa ligador, utilize o seguinte comando no terminal:

```
./ligador test1.asm test2.asm test3.asm test4.asm

```



## Exemplo de Uso

Aqui está um exemplo de uso do programa ligador com 4 arquivos objeto de entrada:

```
./ligador arquivo1.obj arquivo2.obj arquivo3.obj arquivo4.obj
```

O programa irá realizar a ligação entre os arquivos objeto e gerar o arquivo executável correspondente.

## Limitações

O ligador possui as seguintes limitações:

- Aceita apenas até 4 arquivos objeto como entrada.
- Não realiza validação completa das diretivas EXTERN e PUBLIC nos arquivos objeto.
- Mantém a formatação adequada do arquivo de saída, mas não verifica a correção lógica do código ligado.

