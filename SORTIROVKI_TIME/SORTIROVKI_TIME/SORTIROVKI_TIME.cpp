#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <iostream>
#include <locale>

// ФУНКЦИЯ СОРТИРОВКИ ШЕЛЛА
void shell(int* items1, int count1)
{
    int x1;
    int i1, j1, gap, k;
    int a[8];
    a[0] = 3; a[1] = 7; a[2] = 19; a[3] = 35; a[4] = 64; a[5] = 91; a[6] = 128; a[7] = 547;
    int a1[8];
    a1[0] = 547; a1[1] = 128; a1[2] = 91; a1[3] = 64; a1[4] = 35; a1[5] = 19; a1[6] = 7; a1[7] = 3;
    int a2[8];
    a2[0] = 7; a2[1] = 35; a2[2] = 91; a2[3] = 547; a2[4] = 128; a2[5] = 64; a2[6] = 19; a2[7] = 3;

    for (k = 0; k < 8; k++) {
        gap = a[k];
        for (i1 = gap; i1 < count1; ++i1) {
            x1 = items1[i1];
            for (j1 = i1 - gap; (x1 < items1[j1]) && (j1 >= 0); j1 = j1 - gap)
                items1[j1 + gap] = items1[j1];
            items1[j1 + gap] = x1;
        }
    }
}

// ФУНКЦИЯ БЫСТРОЙ СОРТИРОВКИ
void qs(int* items2, int left, int right) //вызов функции: qs(items, 0, count-1);
{
    int a[8];
    a[0] = 3; a[1] = 7; a[2] = 19; a[3] = 35; a[4] = 64; a[5] = 91; a[6] = 128; a[7] = 547;
    int a1[8];
    a1[0] = 547; a1[1] = 128; a1[2] = 91; a1[3] = 64; a1[4] = 35; a1[5] = 19; a1[6] = 7; a1[7] = 3;
    int a2[8];
    a2[0] = 7; a2[1] = 35; a2[2] = 91; a2[3] = 547; a2[4] = 128; a2[5] = 64; a2[6] = 19; a2[7] = 3;

    int i2, j2;
    int x2, y2;

    i2 = left; j2 = right;

    /* выбор компаранда */
    x2 = items2[(left + right) / 2];

    do {
        while ((items2[i2] < x2) && (i2 < right)) i2++;
        while ((x2 < items2[j2]) && (j2 > left)) j2--;

        if (i2 <= j2) {
            y2 = items2[i2];
            items2[i2] = items2[j2];
            items2[j2] = y2;
            i2++; j2--;
        }
    } while (i2 <= j2);

    if (left < j2) qs(items2, left, j2);
    if (i2 < right) qs(items2, i2, right);
}

// ФУНКЦИЯ QSORT
int aq[] = { 3,7,19,35,64,91,128,547 };
int a1q[] = { 547,128,91,64,35,19,7,3 };
int a2q[] = { 7,35,91,547,128,64,19,3 };
int compare(const void* x3_1, const void* x3_2) // функция сравнения элементов массива
{
    return (*(int*)x3_1 - *(int*)x3_2);
}

int main()
{

    setlocale(LC_ALL, "rus");

    setvbuf(stdin, NULL, _IONBF, 0);
    setvbuf(stdout, NULL, _IONBF, 0);

    char inputFile[255];
    FILE* input;

    int a[8];
    a[0] = 3; a[1] = 7; a[2] = 19; a[3] = 35; a[4] = 64; a[5] = 91; a[6] = 128; a[7] = 547;
    int a1[8];
    a1[0] = 547; a1[1] = 128; a1[2] = 91; a1[3] = 64; a1[4] = 35; a1[5] = 19; a1[6] = 7; a1[7] = 3;
    int a2[8];
    a2[0] = 7; a2[1] = 35; a2[2] = 91; a2[3] = 547; a2[4] = 128; a2[5] = 64; a2[6] = 19; a2[7] = 3;

    /*-----------------------------------------------------------------*/
    do {
        printf("Введите имя файла, в который необходимо записать результаты сравнения времени работы всех сортировок: ");
        scanf("%s", inputFile);

        input = fopen(inputFile, "w");

        if (input != NULL)
            break;

        printf("Ошибка! Не удалось открыть файл! Повторите ввод\n\n");
    } while (true);
    /*-----------------------------------------------------------------*/

    //----------------------------------------------------------------------
    printf("\n\n1.1 Сортировка Шелла:\n");
    clock_t start11, end11;
    start11 = clock();
    printf("Исходный массив при возрастающей последовательности: ");
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
    end11 = clock();
    double extime11 = (double)(end11 - start11) / clock();
    printf("\n\tВремя работы программы: %lf секунд.\n\n", extime11);
    //----------------------------------------------------------------------

    //----------------------------------------------------------------------
    printf("\n\n1.2 Сортировка Шелла:\n");
    clock_t start12, end12;
    start12 = clock();
    printf("Исходный массив при убывающей последовательности: ");
    for (int i = 0; i < 8; i++)
    {
        printf("%2d ", a1[i]);
    }
    shell(a1, 8);
    printf("\nПолученный массив: ");
    for (int i = 0; i < 8; i++)
    {
        printf("%2d ", a[i]);
    }
    end12 = clock();
    double extime12 = (double)(end12 - start12) / clock();
    printf("\n\tВремя работы программы: %lf секунд.\n\n", extime12);
    //----------------------------------------------------------------------

    //----------------------------------------------------------------------
    printf("\n\n1.3 Сортировка Шелла:\n");
    clock_t start13, end13;
    start13 = clock();
    printf("Исходный массив при треугольной последовательности: ");
    for (int i = 0; i < 8; i++)
    {
        printf("%2d ", a2[i]);
    }
    shell(a2, 8);
    printf("\nПолученный массив: ");
    for (int i = 0; i < 8; i++)
    {
        printf("%2d ", a[i]);
    }
    end13 = clock();
    double extime13 = (double)(end13 - start13) / clock();
    printf("\n\tВремя работы программы: %lf секунд.\n\n", extime13);
    //----------------------------------------------------------------------


    int first1 = 0, last1 = 8 - 1;
    //----------------------------------------------------------------------
    printf("\n\n2.1 Быстрая сортировка:\n");
    clock_t start21, end21;
    start21 = clock();
    printf("Исходный массив при возрастающей последовательности: : ");
    for (int i = 0; i < 8; i++)
    {
        printf("%2d ", a[i]);
    }
    qs(a, first1, last1);
    printf("\nПолученный массив: ");
    for (int i = 0; i < 8; i++)
    {
        printf("%2d ", a[i]);
    }
    end21 = clock();
    double extime21 = (double)(end21 - start21) / clock();
    printf("\n\tВремя работы программы: %lf секунд.\n\n", extime21);
    //----------------------------------------------------------------------


    //----------------------------------------------------------------------
    printf("\n\n2.2 Быстрая сортировка:\n");
    clock_t start22, end22;
    start22 = clock();
    printf("Исходный массив при убывающей последовательности: ");
    for (int i = 0; i < 8; i++)
    {
        printf("%2d ", a1[i]);
    }
    qs(a1, first1, last1);
    printf("\nПолученный массив: ");
    for (int i = 0; i < 8; i++)
    {
        printf("%2d ", a1[i]);
    }
    end22 = clock();
    double extime22 = (double)(end22 - start22) / clock();
    printf("\n\tВремя работы программы: %lf секунд.\n\n", extime22);
    //----------------------------------------------------------------------


    //----------------------------------------------------------------------
    printf("\n\n2.3 Быстрая сортировка: \n");
    clock_t start23, end23;
    start23 = clock();
    printf("Исходный массив при треугольной последовательности: ");
    for (int i = 0; i < 8; i++)
    {
        printf("%2d ", a2[i]);
    }
    qs(a2, first1, last1);
    printf("\nПолученный массив: ");
    for (int i = 0; i < 8; i++)
    {
        printf("%2d ", a2[i]);
    }
    end23 = clock();
    double extime23 = (double)(end23 - start23) / clock();
    printf("\n\tВремя работы программы: %lf секунд.\n\n", extime23);
    //----------------------------------------------------------------------

    int count2 = 8;
    int first2 = 0, last2 = count2 - 1;
    //----------------------------------------------------------------------
    printf("\n\n3.1 Сортировка с использованием функции qsort:\n");
    clock_t start31, end31;
    start31 = clock();
    printf("Исходный массив при возрастающей последовательности: ");
    for (int i = 0; i < 8; i++)
    {
        printf("%2d ", aq[i]);
    }
    qsort(aq, count2, sizeof(int), compare);
    printf("\nПолученный массив: ");
    for (int i = 0; i < 8; i++)
    {
        printf("%2d ", aq[i]);
    }
    end31 = clock();
    double extime31 = (double)(end31 - start31) / clock();
    printf("\n\tВремя работы программы: %lf секунд.\n\n", extime31);
    //----------------------------------------------------------------------

    //----------------------------------------------------------------------
    printf("\n\n3.2 Сортировка с использованием функции qsort:\n");
    clock_t start32, end32;
    start32 = clock();
    printf("Исходный массив при убывающей последовательности: ");
    for (int i = 0; i < 8; i++)
    {
        printf("%2d ", a1q[i]);
    }
    qsort(a1q, count2, sizeof(int), compare);
    printf("\nПолученный массив: ");
    for (int i = 0; i < 8; i++)
    {
        printf("%2d ", a1q[i]);
    }
    end32 = clock();
    double extime32 = (double)(end32 - start32) / clock();
    printf("\n\tВремя работы программы: %lf секунд.\n\n", extime32);
    //----------------------------------------------------------------------

    //----------------------------------------------------------------------
    printf("\n\n3.3 Сортировка с использованием функции qsort:\n");
    clock_t start33, end33;
    start33 = clock();
    printf("Исходный массив при треугольной последовательности: ");
    for (int i = 0; i < 8; i++)
    {
        printf("%2d ", a2q[i]);
    }
    qsort(a2q, count2, sizeof(int), compare);
    printf("\nПолученный массив: ");
    for (int i = 0; i < 8; i++)
    {
        printf("%2d ", a2q[i]);
    }
    end33 = clock();
    double extime33 = (double)(end33 - start33) / clock();
    printf("\n\tВремя работы программы: %lf секунд.\n\n", extime33);
    //----------------------------------------------------------------------

    fprintf(input, "Результат:\n\n");

    fprintf(input, " ----------------------------------------------------------------------------------\n");
    fprintf(input, " |                  |  Сортировка Шелла  |  Быстрая Сортировка  |  Функция qsort  |\n");
    fprintf(input, " |------------------|--------------------|----------------------|-----------------|\n");
    fprintf(input, " | Возраст. послед. |      %lf с    |       %lf с     |    %lf с   |\n", extime11, extime21, extime31);
    fprintf(input, " |------------------|--------------------|----------------------|-----------------|\n");
    fprintf(input, " | Убывающ. послед. |      %lf c    |       %lf c     |    %lf c   |\n", extime12, extime22, extime32);
    fprintf(input, " |------------------|--------------------|----------------------|-----------------|\n");
    fprintf(input, " | Треугол. послед. |      %lf c    |       %lf c     |    %lf c   |\n", extime13, extime23, extime33);
    fprintf(input, " ----------------------------------------------------------------------------------\n");

    fclose(input);

    return 0;
}
