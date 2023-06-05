#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 100

int main() {
    FILE *input_file, *output_file;
    char inputFileName[] = "bin.asm";
    char outputFileName[MAX_LINE_LENGTH];
    char line[MAX_LINE_LENGTH];
    char currentDirectory[MAX_LINE_LENGTH];
    
    // Obter o caminho absoluto do programa em execução
    char *programPath = realpath("./", NULL);
    if (programPath == NULL) {
        printf("Erro ao obter o caminho absoluto do programa.\n");
        return 1;
    }
    
    // Extrair o diretório pai do caminho absoluto
    strncpy(currentDirectory, programPath, sizeof(currentDirectory));
    
    // Concatenar o diretório atual com o nome do arquivo de entrada
    snprintf(inputFileName, sizeof(inputFileName), "%s/%s", currentDirectory, inputFileName);
    
    // Abrir o arquivo de entrada para leitura
    input_file = fopen(inputFileName, "r");
    if (input_file == NULL) {
        printf("Erro ao abrir o arquivo de entrada.\n");
        free(programPath);
        return 1;
    }
    
    // Criar o nome do arquivo de saída
    strncpy(outputFileName, inputFileName, strlen(inputFileName) - 4);  // Remover a extensão do arquivo
    outputFileName[strlen(inputFileName) - 4] = '\0';  // Adicionar o terminador de string
    strcat(outputFileName, "_saida.txt");  // Adicionar a nova extensão _saida.txt
    
    // Abrir o arquivo de saída para escrita
    output_file = fopen(outputFileName, "w");
    if (output_file == NULL) {
        printf("Erro ao abrir o arquivo de saída.\n");
        fclose(input_file);
        free(programPath);
        return 1;
    }
    
    // Ler cada linha do arquivo de entrada e escrever no arquivo de saída
    while (fgets(line, MAX_LINE_LENGTH, input_file) != NULL) {
        // Verificar se a linha começa com um rótulo (L1:, L2:, etc.)
        if (line[0] >= 'A' && line[0] <= 'Z') {
            // Escrever o rótulo no arquivo de saída
            fprintf(output_file, "%s", line);
        } else {
            // Escrever a instrução no arquivo de saída
            fprintf(output_file, "Instrução: %s", line);
        }
    }
    
    // Fechar os arquivos
    fclose(input_file);
    fclose(output_file);
    
    // Liberar memória alocada
    free(programPath);
    
    printf("Tradução do código assembly concluída. O arquivo de saída está disponível como: %s\n", outputFileName);
    
    return 0;
}
