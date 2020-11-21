#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Registers {
    int ax, bx, cx, dx;
} Registers;

int valueOfItem(char* item, Registers* registers);
void read(char* reg, Registers* registers);
void print(char* toPrint, Registers* registers);
void mov(char* arg1, char* arg2, Registers* registers);
void add(char* arg1, char* arg2, Registers* registers);
void sub(char* arg1, char* arg2, Registers* registers);
void mul(char* arg1, char* arg2, Registers* registers);
void divide(char* arg1, char* arg2, Registers* registers);

int valueOfItem(char* item, Registers* registers) {
    int value = 0;

    if (strcmp(item, "ax") == 0) {
        value = registers->ax;
    }
    else if (strcmp(item, "bx") == 0) {
        value = registers->bx;
    }
    else if (strcmp(item, "cx") == 0) {
        value = registers->cx;
    }
    else if (strcmp(item, "dx") == 0) {
        value = registers->dx;
    }
    else {
        return atoi(item);
    }

    return value;
}

void read(char* reg, Registers* registers) {
    if (strcmp(reg, "ax") == 0) {
        printf("Enter a value to put in ax: ");
        scanf("%d", &(registers->ax));
    }
    else if (strcmp(reg, "bx") == 0) {
        printf("Enter a value to put in bx: ");
        scanf("%d", &(registers->bx));
    }
    else if (strcmp(reg, "cx") == 0) {
        printf("Enter a value to put in cx: ");
        scanf("%d", &(registers->cx));
    }
    else if (strcmp(reg, "dx") == 0) {
        printf("Enter a value to put in dx: ");
        scanf("%d", &(registers->dx));
    }
}

void print(char* toPrint, Registers* registers) {
    printf("%d", valueOfItem(toPrint, registers));
}

void mov(char* arg1, char* arg2, Registers* registers) {
    if (strcmp(arg2, "ax") == 0) {
        registers->ax = valueOfItem(arg1, registers);
    }
    else if (strcmp(arg2, "bx") == 0) {
        registers->bx = valueOfItem(arg1, registers);
    }
    else if (strcmp(arg2, "cx") == 0) {
        registers->cx = valueOfItem(arg1, registers);
    }
    else if (strcmp(arg2, "dx") == 0) {
        registers->dx = valueOfItem(arg1, registers);
    }
}

void add(char* arg1, char* arg2, Registers* registers) {
    if (strcmp(arg2, "ax") == 0) {
        registers->ax += valueOfItem(arg1, registers);
    }
    else if (strcmp(arg2, "bx") == 0) {
        registers->bx += valueOfItem(arg1, registers);
    }
    else if (strcmp(arg2, "cx") == 0) {
        registers->cx += valueOfItem(arg1, registers);
    }
    else if (strcmp(arg2, "dx") == 0) {
        registers->dx += valueOfItem(arg1, registers);
    }
}

void sub(char* arg1, char* arg2, Registers* registers) {
    if (strcmp(arg2, "ax") == 0) {
        registers->ax -= valueOfItem(arg1, registers);
    }
    else if (strcmp(arg2, "bx") == 0) {
        registers->bx -= valueOfItem(arg1, registers);
    }
    else if (strcmp(arg2, "cx") == 0) {
        registers->cx -= valueOfItem(arg1, registers);
    }
    else if (strcmp(arg2, "dx") == 0) {
        registers->dx -= valueOfItem(arg1, registers);
    }
}

void mul(char* arg1, char* arg2, Registers* registers) {
    if (strcmp(arg2, "ax") == 0) {
        registers->ax *= valueOfItem(arg1, registers);
    }
    else if (strcmp(arg2, "bx") == 0) {
        registers->bx *= valueOfItem(arg1, registers);
    }
    else if (strcmp(arg2, "cx") == 0) {
        registers->cx *= valueOfItem(arg1, registers);
    }
    else if (strcmp(arg2, "dx") == 0) {
        registers->dx *= valueOfItem(arg1, registers);
    }
}

void divide(char* arg1, char* arg2, Registers* registers) {
    if (strcmp(arg2, "ax") == 0) {
        registers->ax = valueOfItem(arg1, registers) / registers->ax;
    }
    else if (strcmp(arg2, "bx") == 0) {
        registers->bx = valueOfItem(arg1, registers) / registers->bx;
    }
    else if (strcmp(arg2, "cx") == 0) {
        registers->cx = valueOfItem(arg1, registers) / registers->cx;
    }
    else if (strcmp(arg2, "dx") == 0) {
        registers->dx = valueOfItem(arg1, registers) / registers->dx;
    }
}

int main(int argc, char *argv[])
{
    FILE *fp;
    fp = fopen(argv[1], "r");
    if (fp == NULL) {
        printf("file error\n");
        return 0;
    }

    int lineLength = 25;
    char instructions[100][lineLength]; // array to hold 100 lines of 20 characters

    // Get lines
    int lineCount = 0;
    char line[lineLength];
    while (fgets(line, lineLength, fp)) {
        strcpy(instructions[lineCount], line);
        lineCount++;
    }

    Registers registers;
    // Zero out registers
    registers.ax = 0;
    registers.bx = 0;
    registers.cx = 0;
    registers.dx = 0;

    // Execute instructions
    int i = 0;
    while (i < lineCount) {
        // Store individual pieces of instruction in an array
        char pieces[4][6]; // 4 pieces, 5 max characters each

        char* instCopy[20];
        strcpy(instCopy, instructions[i]);

        char* piece = strtok(instCopy, " "); // get first piece

        // Loop to get all pieces and store in pieces
        int pieceCount = 0;
        while (piece != NULL) {
            // get rid of "\n"
            if (strstr(piece, "\n") != NULL) {
                piece[strlen(piece)-1] = '\0';
            }
            strcpy(pieces[pieceCount], piece);
            piece = strtok(NULL, " ");
            pieceCount++;
        }

        // Continue based on operation
        if (strcmp(pieces[0], "read") == 0) {
            read(pieces[1], &registers);
        }
        else if (strcmp(pieces[0], "print") == 0) {
            print(pieces[1], &registers);
        }
        else if (strcmp(pieces[0], "mov") == 0) {
            mov(pieces[1], pieces[2], &registers);
        }
        else if (strcmp(pieces[0], "add") == 0) {
            add(pieces[1], pieces[2], &registers);
        }
        else if (strcmp(pieces[0], "sub") == 0) {
            sub(pieces[1], pieces[2], &registers);
        }
        else if (strcmp(pieces[0], "mul") == 0) {
            mul(pieces[1], pieces[2], &registers);
        }
        else if (strcmp(pieces[0], "div") == 0) {
            divide(pieces[1], pieces[2], &registers);
        }
        else if (strcmp(pieces[0], "jmp") == 0) {
            i = atoi(pieces[1]);
            continue;
        }
        else if (strcmp(pieces[0], "je") == 0) {
            int v1 = valueOfItem(pieces[2], &registers);
            int v2 = valueOfItem(pieces[3], &registers);
            if (v1 == v2) {
                i = atoi(pieces[1]);
                continue;
            }
        }
        else if (strcmp(pieces[0], "jne") == 0) {
            int v1 = valueOfItem(pieces[2], &registers);
            int v2 = valueOfItem(pieces[3], &registers);
            if (v1 != v2) {
                i = atoi(pieces[1]);
                continue;
            }
        }
        else if (strcmp(pieces[0], "jg") == 0) {
            int v1 = valueOfItem(pieces[2], &registers);
            int v2 = valueOfItem(pieces[3], &registers);
            if (v1 > v2) {
                i = atoi(pieces[1]);
                continue;
            }
        }
        else if (strcmp(pieces[0], "jge") == 0) {
            int v1 = valueOfItem(pieces[2], &registers);
            int v2 = valueOfItem(pieces[3], &registers);
            if (v1 >= v2) {
                i = atoi(pieces[1]);
                continue;
            }
        }
        else if (strcmp(pieces[0], "jl") == 0) {
            int v1 = valueOfItem(pieces[2], &registers);
            int v2 = valueOfItem(pieces[3], &registers);
            if (v1 < v2) {
                i = atoi(pieces[1]);
                continue;
            }
        }
        else if (strcmp(pieces[0], "jle") == 0) {
            int v1 = valueOfItem(pieces[2], &registers);
            int v2 = valueOfItem(pieces[3], &registers);
            if (v1 <= v2) {
                i = atoi(pieces[1]);
                continue;
            }
        }

        i++;
    }

    return 0;
}