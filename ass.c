#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h> // Добавлен заголовочный файл для функции atoi

void task1(const char *inputFileName, const char *outputFileName) {
    FILE *inputFile = fopen(inputFileName, "r");
    FILE *outputFile = fopen(outputFileName, "w");

    if (inputFile == NULL || outputFile == NULL) {
        printf("Error opening files.\n");
        return;
    }

    char word1[101], word2[101];
    fscanf(inputFile, "%s %s", word1, word2);

    int count[26] = {0};

    // Count characters occurrences in the first word
    for (int i = 0; word1[i] != '\0'; i++) {
        count[word1[i] - 'a']++;
    }

    // Count characters occurrences in the second word and find unique characters
    for (int i = 0; word2[i] != '\0'; i++) {
        if (count[word2[i] - 'a'] == 1) {
            fprintf(outputFile, "%c ", word2[i]);
            count[word2[i] - 'a'] = -1; // Mark as visited
        }
    }

    fclose(inputFile);
    fclose(outputFile);
}

void task2(const char *inputFileName, const char *outputFileName) {
    FILE *inputFile = fopen(inputFileName, "r");
    FILE *outputFile = fopen(outputFileName, "w");

    if (inputFile == NULL || outputFile == NULL) {
        printf("Error opening files.\n");
        return;
    }

    char c;
    while ((c = fgetc(inputFile)) != EOF) {
        if (c == 'a')
            c = 'b';
        else if (c == 'b')
            c = 'a';
        else if (c == 'A')
            c = 'B';
        else if (c == 'B')
            c = 'A';
        fputc(c, outputFile);
    }

    fclose(inputFile);
    fclose(outputFile);
}


void task3(const char *inputFileName, const char *outputFileName) {
    FILE *inputFile = fopen(inputFileName, "r");
    FILE *outputFile = fopen(outputFileName, "w");

    if (inputFile == NULL || outputFile == NULL) {
        printf("Error opening files.\n");
        return;
    }

    char str[1001];
    fgets(str, 1001, inputFile);

    int numbers[100];
    int count = 0;

    char *token = strtok(str, " ");
    while (token != NULL) {
        int num = atoi(token);
        if (num != 0) {
            numbers[count++] = num;
        }
        token = strtok(NULL, " ");
    }

    // Sort the numbers
    for (int i = 0; i < count - 1; i++) {
        for (int j = 0; j < count - i - 1; j++) {
            if (numbers[j] > numbers[j + 1]) {
                int temp = numbers[j];
                numbers[j] = numbers[j + 1];
                numbers[j + 1] = temp;
            }
        }
    }

    // Write sorted numbers to output file
    for (int i = 0; i < count; i++) {
        fprintf(outputFile, "%d ", numbers[i]);
    }

    fclose(inputFile);
    fclose(outputFile);
}

void task4(const char *inputFileName, const char *outputFileName) {
    FILE *inputFile = fopen(inputFileName, "r");
    FILE *outputFile = fopen(outputFileName, "w");

    if (inputFile == NULL || outputFile == NULL) {
        printf("Error opening files.\n");
        return;
    }

    int chars[256] = {0};
    int c; // Изменен тип переменной на целочисленный
    while ((c = fgetc(inputFile)) != EOF) {
        if (!isspace(c)) {
            if (chars[c] == 0) {
                fputc(c, outputFile);
                chars[c] = 1;
            }
        }
    }

    fclose(inputFile);
    fclose(outputFile);
}
void task5(const char *inputFileName, const char *outputFileName) {
    FILE *inputFile = fopen(inputFileName, "r");
    FILE *outputFile = fopen(outputFileName, "w");

    if (inputFile == NULL || outputFile == NULL) {
        printf("Error opening files.\n");
        return;
    }

    char longestWord[1001];
    fscanf(inputFile, "%s", longestWord);

    char word[1001];
    while (fscanf(inputFile, "%s", word) == 1) {
        if (strlen(word) > strlen(longestWord)) {
            strcpy(longestWord, word);
        }
    }

    fprintf(outputFile, "%s", longestWord);

    fclose(inputFile);
    fclose(outputFile);
}

void task6(const char *inputFileName, const char *outputFileName) {
    FILE *inputFile = fopen(inputFileName, "r");
    FILE *outputFile = fopen(outputFileName, "w");

    if (inputFile == NULL || outputFile == NULL) {
        printf("Error opening files.\n");
        return;
    }

    int count = 0;
    char word[1001];
    while (fscanf(inputFile, "%s", word) == 1) {
        int len = strlen(word);
        if (tolower(word[len - 1]) == 'a') {
            count++;
        }
    }

    fprintf(outputFile, "%d", count);

    fclose(inputFile);
    fclose(outputFile);
}

int main() {
    task1("input1.txt", "output1.txt");
    task2("input2.txt", "output2.txt");
    task3("input3.txt", "output3.txt");
    task4("input4.txt", "output4.txt");
    task5("input5.txt", "output5.txt");
    task6("input6.txt", "output6.txt");
    return 0;
}
