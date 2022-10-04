#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <iostream>
#include <locale>

using namespace std;

int a[] = { 3,7,19,35,64,91,128,547 };
int compare(const void* x1, const void* x2) // функция сравнения элементов массива
{
    return (*(int*)x1 - *(int*)x2);
}
int main()
{
    setlocale(LC_ALL, "rus");
    srand(time(NULL)); // инициализируем параметры генератора случайных чисел

    int count = 8;

    printf("Исходный массив: ");
    for (int i = 0; i < count; i++)
    {
        printf("%2d ", a[i]);
    }

    printf("\n\nРезультат: ");
    int first = 0, last = count - 1;
    qsort(a, count, sizeof(int), compare);
    for (int i = 0; i < count; i++)
    {
        printf("%2d ", a[i]);
    }
    printf("\n\nВремя работы программы: %lf секунд.\n", clock() / 1000.0);

    return 0;
}
