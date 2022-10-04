#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <iostream>
#include <locale>


// Функция сортировки Шелла
void shell(int* items, int count)
{

    int x, a[8];
    int i, j, gap, k;
    a[0] = 3; a[1] = 7; a[2] = 19; a[3] = 35; a[4] = 64; a[5] = 91; a[6] = 128; a[7] = 547;

    for (k = 0; k < 8; k++) {
        gap = a[k];
        for (i = gap; i < count; ++i) {
            x = items[i];
            for (j = i - gap; (x < items[j]) && (j >= 0); j = j - gap)
                items[j + gap] = items[j];
            items[j + gap] = x;
        }
    }
}

int main()
{

    setlocale(LC_ALL, "rus");

    setvbuf(stdin, NULL, _IONBF, 0);
    setvbuf(stdout, NULL, _IONBF, 0);

    time_t start, end;


    int a[8];
    a[0] = 3; a[1] = 7; a[2] = 19; a[3] = 35; a[4] = 64; a[5] = 91; a[6] = 128; a[7] = 547;

    start = time(NULL);
    printf("Исходный массив: ");
    for (int i = 0; i < 8; i++)
    {
        printf("%2d ", a[i]);
    }

    shell(a, 8);

    printf("\nПолученный массив: ");
    for (int i = 0; i < 8; i++)
    {
        printf("%2d ", a[i]);
    }
    end = time(NULL);
    printf("\nВремя работы программы: %lf секунд.\n", clock() / 1000.0);

    return 0;
}
