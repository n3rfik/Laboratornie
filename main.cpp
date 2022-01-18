#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <locale.h>

int i = 0, j = 0, r;
int a[400][400], b[400][400], c[400][400], elem_c;

int main(void)
{
	setlocale(LC_ALL, "Russian");
	setvbuf(stdin, NULL, _IONBF, 0);
	setvbuf(stdout, NULL, _IONBF, 0);

	clock_t start, end; // объявляем переменные для определения времени выполнения


	srand(time(NULL)); // инициализируем параметры генератора случайных чисел
	while (i < 400)
	{
		while (j < 400)
		{
			a[i][j] = rand() % 100 + 1; // заполняем массив случайными числами
			j++;
		}
		i++;
	}
	srand(time(NULL)); // инициализируем параметры генератора случайных чисел
	i = 0; j = 0;
	while (i < 400)
	{
		while (j < 400)
		{
			b[i][j] = rand() % 100 + 1; // заполняем массив случайными числами
			j++;
		}
		i++;
	}
	start = clock();
	for (i = 0;i < 400;i++)
	{
		for (j = 0;j < 400;j++)
		{
			elem_c = 0;
			for (r = 0;r < 400;r++)
			{
				elem_c = elem_c + a[i][r] * b[r][j];
				c[i][j] = elem_c;
			}
		}
	}
	end = clock();
	printf("Время выполнения работы программы: %.4f секунд.\n", ((double)end - start) / ((double)CLOCKS_PER_SEC));

	system("PAUSE");

	return(0);
}
