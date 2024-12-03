#include <stdio.h>
#include <stdlib.h>

void input_line(char** str, int* size) {
    size_t length = 0;

    *size = getline(str, &length, stdin);

    if (*size == -1) {
        puts("Ошибка ввода");
        exit(EXIT_FAILURE);
    }
}

int p_1(char* input) {
    if (input[0] == '-') {
        for (int i = 1; input[i] != '\n'; i++)
        {
            if (input[i] < '0' || input[i] > '9')
            {
                return 0;
            }
        }
    }
    else {
        for (int i = 0; input[i] != '\n'; i++)
        {
            if (input[i] < '0' || input[i] > '9')
            {
                return 0;
            }
        }
    }
    return 1;
}

int p_2(char* input, int* integer)
{
    int temp;
    if (p_1(input) && sscanf(input, "%d", &temp) == 1)
    {
        *integer = temp;
        return 1;
    }
    else
    {
        return 0;
    }
}

int check() {
    char in[256];
    int Int = 0;
    while (1) {

        fgets(in, sizeof(in), stdin);

        if (p_2(in, &Int) == 1) {

            break;
        }
        else
        {
            printf("Ошибка, введите еще раз!\n");
        }

    }
    return Int;
}

void input_all(char* str, char* str0, int k, int m) {
    int size = 0, size0 = 0;

    puts("Введите первую строку");
    input_line(&str, &size);

    puts("Введите вторую строку");
    input_line(&str0, &size0);

    while (1) {
        puts("Введите число k ");
        k = check();
        if (k < size)
            break;
        else
            puts("Неккоректное значение");
    }

    while (1) {
        puts("Введите число m ");
        m = check();
        if (m < size0)
            break;
        else
            puts("Неккоректное значение");
    }
}