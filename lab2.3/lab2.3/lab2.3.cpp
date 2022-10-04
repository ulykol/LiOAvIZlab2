#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <iostream>
#include <locale>

using namespace std;

void qs(int* items, int left, int right) //вызов функции: qs(items, 0, count-1);
{
	int i, j;
	int x, y;

	i = left; j = right;

	/* выбор компаранда */
	x = items[(left + right) / 2];

	do {
		while ((items[i] < x) && (i < right)) i++;
		while ((x < items[j]) && (j > left)) j--;

		if (i <= j) {
			y = items[i];
			items[i] = items[j];
			items[j] = y;
			i++; j--;
		}
	} while (i <= j);

	if (left < j) qs(items, left, j);
	if (i < right) qs(items, i, right);
}


int main()
{
	setlocale(LC_ALL, "rus");
	srand(time(NULL));

	int count = 8;
	int a[] = { 7, 35, 91, 547, 128, 64, 19, 3 };

	printf("Исходный массив:\n");
	for (int i = 0; i < count; i++)
	{
		printf("%2d ", a[i]);
	}

	int first = 0, last = count - 1;
	qs(a, first, last);

	printf("\n\nРезультат:\n");
	for (int i = 0; i < count; i++)
	{
		printf("%2d ", a[i]);
	}
	printf("\n\nВремя работы программы: %lf секунд.\n", clock() / 1000.0);

	return 0;
}
