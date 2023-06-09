#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define MAX_LINE_LENGTH 1000

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Uso: %s <arquivo.asm>\n", argv[0]);
        return 1;
    }

    FILE *inputFile = fopen(argv[1], "r");
    if (inputFile == NULL) {
        printf("Erro ao abrir o arquivo de entrada.\n");
        return 1;
    }

    FILE *outputFile = fopen("saida.txt", "w");
    if (outputFile == NULL) {
        printf("Erro ao criar o arquivo de saída.\n");
        fclose(inputFile);
        return 1;
    }

    char line[MAX_LINE_LENGTH];
    while (fgets(line, sizeof(line), inputFile)) {
        // Substituir espaços por 0
        for (int i = 0; line[i] != '\0'; i++) {
            if (isspace(line[i])) {
                line[i] = '0';
            }
        }

        fputs(line, outputFile);
    }

    fclose(inputFile);
    fclose(outputFile);

    printf("Conversão concluída. O arquivo de saída foi criado.\n");

    return 0;
}


