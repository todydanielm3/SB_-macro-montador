# Trabalho Prático 1 - Macro-montador em C/C++

## Disciplina
Software Básico - Prof. Bruno Macchiavello

## Introdução
O trabalho prático consiste em implementar um macro-montador em linguagem C/C++. O objetivo é criar um programa que traduza um código assembly fornecido em sala de aula. O programa deve ser capaz de ler um arquivo de entrada com extensão ".ASM" e gerar um arquivo de saída com extensão ".EXC". Recomenda-se realizar o trabalho em grupo de dois alunos.

## Integrantes do Grupo
- Daniel Moraes
- Rafael dos Santos Silva


## Sistema Operacional (SO) e Compilador
O trabalho pode ser desenvolvido em qualquer sistema operacional, mas é obrigatório utilizar o compilador GCC no Linux, ou o Code::Blocks no Windows (que utiliza o GCC do MinGW). O macOS deve ser tratado como o sistema operacional Linux. Recomenda-se testar o programa em dois computadores diferentes antes de enviar o trabalho. Caso esteja utilizando o Visual Studio Code, é importante modificar a configuração de tabulação, pois ele normalmente modifica a tabulação por espaços ao abrir o arquivo, o que pode causar problemas nos testes.

## Compilação e Execução
Para compilar o programa, siga os seguintes passos:

1. Instale o compilador GCC (se já não estiver instalado).
2. Abra um terminal e navegue até a pasta onde o código-fonte do programa está localizado.
3. Execute o seguinte comando para compilar o código:

   ```
   gcc -o montador montador.c
   ```
Para o compilador MinGW no Windows:
```
   gcc -o montador.exe montador.c
```

4. Após a compilação ser concluída sem erros, execute o programa com o seguinte comando:

   ```
   ./montador <arquivo.asm>
   ```

   Substitua "<arquivo.asm>" pelo nome do arquivo assembly que deseja montar.


5. O programa irá gerar um arquivo de saída com o nome do arquivo de entrada, mas com a extensão ".EXC"



## Montador
O montador desenvolvido deve traduzir um código assembly conforme especificado em sala de aula. O arquivo de entrada deve ser um arquivo de texto com a extensão ".ASM". O arquivo de saída será outro arquivo de texto contendo o código objeto ou uma única linha no caso de não precisar de ligação. Recomenda-se a criação de um arquivo pre-processado adicional.

O programa montador deve aceitar a seguinte chamada por linha de comando:

```
./montador <arquivo.asm>
```

O arquivo de entrada deve ser fornecido sem a extensão e o arquivo de saída deve manter o mesmo nome, mas com a extensão modificada para ".EXC".

É importante ressaltar que o programa montador não precisa ser capaz de processar as seguintes diretivas:

- EQU e IF
- ORG
- MACROS

O montador deve possuir as seguintes características:

- Aceitar maiúsculas e minúsculas, ou seja, não ser sensível ao caso (dica: transforme tudo em maiúsculas em um arquivo pre-processado e, em seguida, utilize-o).
- Utilizar apenas uma passagem (inclusive para ar

quivos que precisam ser ligados).
- A diretiva CONST deve aceitar valores positivos, negativos e em hexadecimal no formato "0x" (ex: 0x12). No arquivo de saída ".EXC", todos os valores devem estar em decimal (ou seja, se for fornecido CONST 0x30, deve ser exibido o número 48 no arquivo de saída).
- O comando COPY deve separar os argumentos por vírgula (",") com espaços antes e depois da vírgula (ex: COPY A1, A2).
- Desconsiderar espaços, tabulações ou quebras de linha desnecessários em qualquer parte do código (dica: remova-os na etapa de pré-processamento, pois isso é importante para verificar se o scanner está funcionando corretamente).
- Sempre haverá pelo menos um espaço entre os tokens, com exceção de ":" (ex. R1: INPUT N1).
- É possível definir rótulos seguidos de dois pontos e uma quebra de linha. O rótulo é considerado como sendo da linha seguinte (dica: coloque-os na mesma linha no arquivo pre-processado).
- A diretiva SPACE pode aceitar argumentos, permitindo rótulos como "X + 2" (com espaços).
- Aceitar comentários em qualquer parte do código iniciados por ";".

O montador deve verificar os seguintes erros (mesmo que haja erros, recomenda-se criar o arquivo ".EXC"):

- Dois rótulos na mesma linha.
- Rótulo não definido na seção TEXT.
- Dado não definido na seção DATA.
- Seção TEXT faltante.
- EXTERN e PUBLIC em um arquivo que NÃO possui BEGIN e END.
- Erros léxicos (caracteres especiais fora do "_" (underscore) ou número inicial nos rótulos).

O programa deve indicar a linha do erro e se é léxico, sintático ou semântico. Se você gerar um arquivo pre-processado, pode ser a linha desse arquivo. Indique isso no arquivo README. O código estará separado em seções TEXT e DATA, utilizando a diretiva SECTION (conforme exemplo fornecido no Teams). A seção DATA pode estar antes ou depois da seção TEXT no código assembly, mas no arquivo objeto os dados sempre devem estar no final, ou seja, o código deve começar com o OPCODE da primeira instrução.

## Ligador
O montador deve ser capaz de realizar a ligação de até 4 arquivos assembly. O programa de montador deve aceitar até 4 arquivos como argumentos na linha de comando (por exemplo: "./montador teste1 teste2 teste3 teste4").

Os arquivos agora devem conter as diretivas BEGIN, END, EXTERN e PUBLIC. As diretivas EXTERN e PUBLIC devem estar sempre no início, antes de qualquer uma das seções DATA ou TEXT (consulte o exemplo no Teams).

O arquivo de saída do montador para cada um dos arquivos assembly deve manter o nome e trocar a extensão para ".OBJ" (observe que é diferente do caso sem ligação). Consulte o exemplo do formato no Teams (observe que o arquivo neste caso não representa um código real, é apenas para visualizar o formato).

Na parte USO, devem ser colocados os endereços da tabela de uso; na DEF, a tabela de definições; na REF, os endereços de todos os valores relativos; e na CODE, o código

 traduzido antes de ligar.

O ligador deve ser chamado de LINKER e deve receber todos os arquivos objeto como argumentos na linha de comando. O programa deve gerar um arquivo EXC com o nome do primeiro arquivo OBJ. O formato do arquivo EXC deve ser igual ao já indicado.

## Teste e Exemplos
No Teams, na aba de arquivos, há uma pasta "Trabalho 1" que contém exemplos e um simulador. Para executar o simulador, basta fornecer o arquivo de entrada (com extensão) por linha de comando. Por exemplo: "./simulador entrada.exc". O arquivo de entrada deve ser um arquivo de texto com extensão ".EXC". O simulador espera que o usuário saiba como executar o programa, ou seja, qualquer entrada de INPUT fará com que o cursor aguarde o usuário digitar o número, sem exibir nenhuma mensagem. O simulador ajuda a verificar se o arquivo objeto está correto. O simulador não funciona com arquivos que ainda não foram ligados.
