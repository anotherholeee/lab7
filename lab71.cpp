#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

void input_line(char** str) {
    size_t length = 128;
    *str = (char*)malloc(length);

    if (*str == NULL) {
        puts("Ошибка выделения памяти");
        exit(0);
    }

    int c;
    size_t len = 0;
    while ((c = getchar()) != '\n' && c != EOF) {
        if (len + 1 >= length) {
            length *= 2;
            *str = (char*)realloc(*str, length);
            if (*str == NULL) {
                puts("Ошибка выделения памяти");
                exit(0);
            }
        }
        (*str)[len++] = c;
    }
    (*str)[len] = '\0';
}

void find_numbers(const char* str, int* sum) {
    int i = 0;

    while (str[i] != '\0') {
        if (str[i] >= '0' && str[i] <= '9') {
            int num = 0;

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

int main() {
    setlocale(LC_ALL, "");
    char* str = NULL;
    int sum = 0;

    puts("Введите строку");
    input_line(&str);

    find_numbers(str, &sum);

    printf("Сумма всех чисел в строке: %d\n", sum);

    free(str);
    return 0;
}
