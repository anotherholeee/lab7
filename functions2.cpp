#include <stdio.h>
#include <stdlib.h>

void input_line(char** str) {
    size_t length = 0;
    int read;

    read = getline(str, &length, stdin);

    if (read == -1) {
        puts("Ошибка ввода");
        exit(EXIT_FAILURE);
    }
}

void find_numbers(const char* str, int* sum) {
    int i = 0;

    while (str[i] != '\0' && str[i] != '\n') {
        if (str[i] >= '0' && str[i] <= '9') {
            int num = 0;
            // Выделение числа
            while (str[i] >= '0' && str[i] <= '9') {
                num = num * 10 + (str[i] - '0');
                i++;
            }
            *sum += num;
        }
        else {
            i++;
        }
    }
}