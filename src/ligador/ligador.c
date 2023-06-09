#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define MAX_LINE_LENGTH 1000
#define MAX_NUM_FILES 4
#define OUTPUT_FILE_EXTENSION ".obj"

int main(int argc, char *argv[]) {
    if (argc < 2 || argc > MAX_NUM_FILES + 1) {
        printf("Uso: %s <arquivo1.asm> <arquivo2.asm> ... <arquivo%d.asm>\n", argv[0], MAX_NUM_FILES);
        return 1;
    }

    FILE *inputFiles[MAX_NUM_FILES];
    FILE *outputFiles[MAX_NUM_FILES];

    // Abrir arquivos de entrada e saída
    for (int i = 0; i < argc - 1; i++) {
        inputFiles[i] = fopen(argv[i + 1], "r");
        if (inputFiles[i] == NULL) {
            printf("Erro ao abrir o arquivo de entrada %s.\n", argv[i + 1]);

            // Fechar arquivos já abertos
            for (int j = 0; j < i; j++) {
                fclose(inputFiles[j]);
                fclose(outputFiles[j]);
            }

            return 1;
        }

        char outputFileName[MAX_LINE_LENGTH];
        snprintf(outputFileName, sizeof(outputFileName), "saida%d%s", i + 1, OUTPUT_FILE_EXTENSION);
        outputFiles[i] = fopen(outputFileName, "w");
        if (outputFiles[i] == NULL) {
            printf("Erro ao criar o arquivo de saída %s.\n", outputFileName);

            // Fechar arquivos já abertos
            for (int j = 0; j <= i; j++) {
                fclose(inputFiles[j]);
                fclose(outputFiles[j]);
            }

            return 1;
        }
    }

    char line[MAX_LINE_LENGTH];
    int currentFileIndex = 0;

    // Ler e escrever linhas de cada arquivo de entrada
    while (fgets(line, sizeof(line), inputFiles[currentFileIndex])) {
        fputs(line, outputFiles[currentFileIndex]);

        // Avançar para o próximo arquivo de entrada
        currentFileIndex = (currentFileIndex + 1) % (argc - 1);
    }

    // Fechar arquivos
    for (int i = 0; i < argc - 1; i++) {
        fclose(inputFiles[i]);
        fclose(outputFiles[i]);
    }

    printf("Ligação concluída. Arquivos de saída foram criados.\n");

    return 0;
}

