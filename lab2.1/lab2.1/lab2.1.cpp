#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <iostream>
#include <locale>

using namespace std;

const unsigned int n = 10;
int a[n][n], b[n][n], c[n][n];

int main() {

	setlocale(LC_ALL, "rus");

	setvbuf(stdin, NULL, _IONBF, 0);
	setvbuf(stdout, NULL, _IONBF, 0);

	time_t start, end; // объявляем переменные для определения времени выполнения

	int i = 0, j = 0, r;

	start = time(NULL);
	srand(time(NULL)); // инициализируем параметры генератора случайных чисел

	printf("Матрица A:\n\n");

	for (i = 0; i < n; i++)
	{
		for (j = 0; j < n; j++)
		{
			a[i][j] = rand() % 10 + 1; // заполняем массив случайными числами
			printf("%5d", a[i][j]);
		}
		printf("\n");
		printf("\n");
	}

	start = time(NULL);
	srand(time(NULL)); // инициализируем параметры генератора случайных чисел

	printf("Матрица B:\n\n");

	for (i = 0; i < n; i++)
	{
		for (j = 0; j < n; j++)
		{
			b[i][j] = rand() % 10 + 5; // заполняем массив случайными числами
			printf("%5d", b[i][j]);
		}
		printf("\n");
		printf("\n");
	}



	printf("Матрица C = A * B:\n\n");

	for (i = 0; i < n; i++)
	{
		for (j = 0; j < n; j++)
		{
			c[i][j] = 0;
			for (r = 0; r < n; r++)
			{
				c[i][j] += a[i][r] * b[r][j];
			}
			printf("%5d", c[i][j]); // Вывод значения элемента на экран:
		}
		printf("\n");
		printf("\n");
	}

	end = time(NULL);
	printf("Время работы программы: %lf секунд.\n", clock() / 1000.0);

	return 0;

}
