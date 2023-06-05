#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 100
#define MAX_SYMBOL_LENGTH 50
#define MAX_OPCODE_LENGTH 10
#define MAX_OPERAND_LENGTH 10

typedef struct Symbol {
    char name[MAX_SYMBOL_LENGTH];
    int address;
} Symbol;

typedef struct Instruction {
    char opcode[MAX_OPCODE_LENGTH];
    char operand[MAX_OPERAND_LENGTH];
} Instruction;

void preprocessCode(const char* inputFilename, const char* preprocessedFilename) {
    FILE* inputFile = fopen(inputFilename, "r");
    FILE* preprocessedFile = fopen(preprocessedFilename, "w");

    if (inputFile != NULL && preprocessedFile != NULL) {
        char line[MAX_LINE_LENGTH];

        while (fgets(line, sizeof(line), inputFile)) {
            // Remove trailing newline character
            line[strcspn(line, "\n")] = '\0';

            // Ignore empty lines and comments
            if (strlen(line) == 0 || line[0] == ';') continue;

            // Write the line to the preprocessed file
            fprintf(preprocessedFile, "%s\n", line);
        }

        fclose(inputFile);
        fclose(preprocessedFile);
        printf("Preprocessing completed. Preprocessed file generated: %s\n", preprocessedFilename);
    } else {
        fprintf(stderr, "Error opening input file or preprocessed file.\n");
    }
}

void assembleCode(const char* preprocessedFilename, const char* outputFilename) {
    FILE* preprocessedFile = fopen(preprocessedFilename, "r");
    FILE* outputFile = fopen(outputFilename, "w");

    if (preprocessedFile != NULL && outputFile != NULL) {
        char line[MAX_LINE_LENGTH];
        Symbol symbolTable[MAX_LINE_LENGTH];
        int symbolCount = 0;
        Instruction instructions[MAX_LINE_LENGTH];
        int instructionCount = 0;
        int locationCounter = 0;

        while (fgets(line, sizeof(line), preprocessedFile)) {
            // Remove trailing newline character
            line[strcspn(line, "\n")] = '\0';

            // Ignore empty lines and comments
            if (strlen(line) == 0 || line[0] == ';') continue;

            // Check the current section
            if (strcmp(line, "SECTION TEXT") == 0) {
                // Process instructions
                while (fgets(line, sizeof(line), preprocessedFile)) {
                    // Remove trailing newline character
                    line[strcspn(line, "\n")] = '\0';

                    // Ignore empty lines and comments
                    if (strlen(line) == 0 || line[0] == ';') continue;

                    // Check if the line is a label
                    if (strchr(line, ':') != NULL) {
                        // Store the label in the symbol table
                        char* label = strtok(line, ":");
                        strcpy(symbolTable[symbolCount].name, label);
                        symbolTable[symbolCount].address = locationCounter;
                        symbolCount++;
                    }

                    // Split the line into opcode and operand
                    char* opcode = strtok(line, " ");
                    char* operand = strtok(NULL, " ");

                    // Store the instruction in the instruction table
                    strcpy(instructions[instructionCount].opcode, opcode);
                    if (operand != NULL) {
                        strcpy(instructions[instructionCount].operand, operand);
                    } else {
                        instructions[instructionCount].operand[0] = '\0';
                    }
                    instructionCount++;

                    // Increment the location counter
                    locationCounter++;
                }
            } else if (strcmp(line, "SECTION DATA") == 0) {
                // Process data
                while (fgets(line, sizeof(line), preprocessedFile)) {
                    // Remove trailing newline character
                    line[strcspn(line, "\n")] = '\0';

                    // Ignore empty lines and comments
                    if (strlen(line) == 0 || line[0] == ';') continue;

                    // Check if the line is a label
                    if (strchr(line, ':') != NULL) {
                        // Store the label in the symbol table
                        char* label = strtok(line, ":");
                        strcpy(symbolTable[symbolCount].name, label);
                        symbolTable[symbolCount].address = locationCounter;
                        symbolCount++;
                    }

                    // Split the line into label and value
                    char* label = strtok(line, " ");
                    char* value = strtok(NULL, " ");

                    // Store the value in the symbol table
                    strcpy(symbolTable[symbolCount].name, label);
                    symbolTable[symbolCount].address = atoi(value);
                    symbolCount++;

                    // Increment the location counter
                    locationCounter++;
                }
            } else {
                fprintf(stderr, "Invalid section: %s\n", line);
                return;
            }





