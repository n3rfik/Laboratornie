#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <locale.h>

void shell(int* items, int count)
{
	int i, j, gap, k;
	int x, a[5];
	a[0] = 9; a[1] = 5; a[2] = 3; a[3] = 2; a[4] = 1;
	for (k = 0; k < 5; k++) {
		gap = a[k];
		for (i = gap; i < count; ++i) {
			x = items[i];
			for (j = i - gap; (x < items[j]) && (j >=  0); j = j - gap)
				items[j + gap] = items[j];
			items[j + gap] = x;
		}
	}
}

void qs(int* array1, int left, int right)
{
	int i, j;
	int x, y;

	i = left; j = right;
	/* выбор компаранда */
	x = array1[(left + right) / 2];
	do {
		while ((array1[i] < x) && (i < right)) i++;
		while ((x < array1[j]) && (j > left)) j--;
		if (i <= j) {
			y = array1[i];
			array1[i] = array1[j];
			array1[j] = y;
			i++; j--;
		}
	} while (i <= j);
	if (left < j) qs(array1, left, j);
	if (i < right) qs(array1, i, right);
}

int comp(const void* a, const void* b)
{
	return *(int*)a - *(int*)b;
}


int main(void)

{	
	setlocale(LC_ALL,"Russian");
	clock_t start, end; // объявляем переменные для определения времени выполнения

	start = clock();
	int i = 0;
	int size;
	printf("Введите размер массива:");
	scanf_s("%d", &size);
	int* array1 = (int*)malloc(size * sizeof(int));
	srand(time(NULL));
	printf("Быстрая сортировка:\n");
	printf("\n");
	printf("1.Случайные числа:\n");
	for (int i = 0; i < size; i++)
	{
		array1[i] = rand() % 100;
	}
	start = clock();

	qs(array1, 0, size - 1);

	end = clock();
	printf("Время выполнения = %.4f секунд\n", ((double)end - start) / ((double)CLOCKS_PER_SEC));
	printf("\n");

	printf("2.Возрастание массива:\n");
	for (int i = 0; i < size; i++)
	{
		array1[i] = i;
	}

	start = clock();

	qs(array1, 0, size - 1);

	end = clock();
	printf("Время выполнения = %.4f секунд\n", ((double)end - start) / ((double)CLOCKS_PER_SEC));
	printf("\n");

	printf("3.Убывание массива:\n");
	for (int i = 0; i < size; i++)
	{
		array1[i] = 10-i;
	}

	start = clock();

	qs(array1, 0, size - 1);

	end = clock();
	printf("Время выполнения = %.4f секунд\n", ((double)end - start) / ((double)CLOCKS_PER_SEC));
	printf("\n");

	printf("4.Возрастающе-убывающий массив:\n");
	for (int i = 0; i < size; i++)
	{
		if (i < size / 2)
			array1[i] = i;

		if (i >= size / 2)
			array1[i] = 10 - i;
	}

	start = clock();

	qs(array1, 0, size - 1);

	end = clock();
	printf("Время выполнения = %.4f секунд\n", ((double)end - start) / ((double)CLOCKS_PER_SEC));
	printf("\n");

	printf("Сортировка Шелла:\n");
	printf("\n");
	printf("1.Случайные числа:\n");

	for (int i = 0; i < size; i++)
	{
		array1[i] = rand() % 100;
	}
	start = clock();

	shell(array1, size);

	end = clock();
	printf("Время выполнения = %.4f секунд\n", ((double)end - start) / ((double)CLOCKS_PER_SEC));
	printf("\n");

	printf("2.Возрастание массива:\n");

	for (int i = 0; i < size; i++)
	{
		array1[i] = i;
	}
	start = clock();

	shell(array1, size);

	end = clock();
	printf("Время выполнения = %.4f секунд\n", ((double)end - start) / ((double)CLOCKS_PER_SEC));
	printf("\n");

	printf("3.Убывание массива:\n");

	for (int i = 0; i < size; i++)
	{
		array1[i] = 10 - i;
	}
	start = clock();

	shell(array1, size);

	end = clock();
	printf("Время выполнения = %.4f секунд\n", ((double)end - start) / ((double)CLOCKS_PER_SEC));
	printf("\n");

	printf("4.Возрастающе-убывающий массив:\n");

	for (int i = 0; i < size; i++)
	{
		if (i < size / 2)
			array1[i] = i;

		if (i >= size / 2)
			array1[i] = 10 - i;
	}
	start = clock();

	shell(array1, size);

	end = clock();
	printf("Время выполнения = %.4f секунд\n", ((double)end - start) / ((double)CLOCKS_PER_SEC));
	printf("\n");

	printf("Quick Sort:\n");
	printf("\n");
	printf("1.Случайные числа:\n");
	for (int i = 0; i < size; i++)
	{
		array1[i] = rand() % 100;
	}
	start = clock();

	qsort(array1, size, sizeof(int), comp);

	end = clock();
	printf("Время выполнения = %.4f секунд\n", ((double)end - start) / ((double)CLOCKS_PER_SEC));
	printf("\n");

	printf("2.Возрастание массива:\n");
	for (int i = 0; i < size; i++)
	{
		array1[i] = i;
	}
	start = clock();

	qsort(array1, size, sizeof(int), comp);

	end = clock();
	printf("Время выполнения = %.4f секунд\n", ((double)end - start) / ((double)CLOCKS_PER_SEC));
	printf("\n");

	printf("3.Убывание массива:\n");
	for (int i = 0; i < size; i++)
	{
		array1[i] = 10-i;
	}
	start = clock();

	qsort(array1, size, sizeof(int), comp);

	end = clock();
	printf("Время выполнения = %.4f секунд\n", ((double)end - start) / ((double)CLOCKS_PER_SEC));
	printf("\n");

	printf("4. Возрастающе-убывающий массив:\n");
	for (int i = 0; i < size; i++)
	{
		if (i < size / 2)
			array1[i] = i;

		if (i >= size / 2)
			array1[i] = 10 - i;
	}
	start = clock();

	qsort(array1, size, sizeof(int),comp);

	end = clock();
	printf("Время выполнения = %.4f секунд\n", ((double)end - start) / ((double)CLOCKS_PER_SEC));
	printf("\n");

	system("PAUSE");
	return(0);
}

