#include <stdio.h>
#include "conio.h"
#include "stdlib.h"
#include "time.h"
#include "locale.h"



int** matrix;
int size;
int* num;

void dfs(int v)
{
	num[v] = 1;
	printf("%d ", v);
	for (int i = 1; i < size; i++)
	{
		if ((matrix[v][i] == 1) && (num[i] == 0))
			dfs(i);
	}
}

int main()
{
	int s;
	setlocale(LC_ALL, "Russian");
	printf("Введите размер матрицы: ");
	scanf_s("%d", &size);
	num = (int*)malloc(size * sizeof(int));
	for (int i = 0; i < size; i++)
	{
		num[i] = 0;
	}
	printf("\n");
	matrix = (int**)malloc(size * sizeof(int*));
	srand(time(NULL));
	for (int i = 0; i < size; i++)
	{
		matrix[i] = (int*)malloc(size * sizeof(int));

	}
	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size; j++)
		{
			matrix[i][j] = rand() % 2;


			if (matrix[i] == matrix[j])
				matrix[i][j] = 0;

			

		}
	}
	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size; j++)
		{
			if (matrix[i][j] != matrix[j][i])
				matrix[i][j] = matrix[j][i];
		}
	}
	printf("Матрица:\n");
	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size; j++)
		{
			printf("%3d", matrix[i][j]);
		}
		printf("\n");

	}
	printf("Введите стартовую вершину: ");
	scanf_s("%d", &s);
	printf("\n");
	printf("Обход закончен с результатом: ");
	dfs(s);
	system("PAUSE");
	return 0;
}
