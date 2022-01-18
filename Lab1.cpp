//*Задание 1-3*//

#include "conio.h"
#include "stdlib.h"
#include <stdio.h>
#include "time.h"

int main()
{
	int size;
	scanf_s("%d", & size);
	int* array = (int*) malloc(size * sizeof(int));
	srand(time(NULL));
	for (int i = 0; i < size; i++)
	{
		array[i] = rand() % 100;
		printf("%d ", array[i]);

	}
	int min = array[0];
	int max = array[0];
	for (int i = 0; i < size; i++)
	{
		if (min>array[i]) min = array[i];
		if (max<array[i]) max = array[i];
	}
	printf("\n");
	printf("%d-%d=%d\t", max, min, max - min);
	system("PAUSE");
	return 0;
}

//*Задание 4*//

#include <stdio.h>
#include "conio.h"
#include "stdlib.h"
#include "time.h"
#include "locale.h"

int main()
{
	setlocale(LC_ALL, "RU");
	int size;
	printf("Введите размер матрицы: ");
	scanf_s("%d",& size);

	int** matrix = (int**)malloc(size * sizeof(int*));
	srand(time(NULL));
	for (int i=0; i < size; i++)
	{
		matrix[i] = (int*)malloc(size * sizeof(int));

	}
	for (int i=0; i < size; i++)
	{
		for (int j=0; j < size; j++)
		{
			matrix[i][j] = rand() % 100;
		}
		
	}
	for (int i=0 ; i < size; i++)
	{
		int k=0;
		for (int j=0; j < size; j++)
		{
			printf("%3d", matrix[i][j]);
			k += matrix[i][j];
		}
		printf(" = %4d\n", k);

	}
}

//*Задание 5*//

#include <stdio.h>
#include "stdlib.h"
#include "conio.h"
#include "time.h"
#include "locale.h"

int   main(void)
{
	setlocale(LC_ALL, "Ru");
	setvbuf(stdin, NULL, _IONBF, 0);
	setvbuf(stdout, NULL, _IONBF, 0);
	int i;
	struct student
	{
		char famil[20];
		char name[20], facult[20];
		int Nomzach;
	} stud[3];

	for(i=0;i<3;i++)
	{
		printf("Введите фамилию студента\n"); scanf_s("%20s", stud[i].famil, 20);
	}
	for(i=0;i<3;i++)
	{
		printf("Введите имя студента\n",stud[i].famil); scanf_s ("%20s",stud[i].name, 20);
	}
	for(i=0;i<3;i++)
	{
		printf("Введите название факультета студента %s %s\n",stud[i].famil,stud[i].name); scanf_s ("%20s",stud[i].facult, 20);
	}
	for(i=0;i<3;i++)
	{
		printf("Введите номер зачётной книжки студента %s %s\n",stud[i].famil,stud[i].name); scanf_s ("%d",&stud[i].Nomzach);
	}

	for(i=0;i<3;i++)
		{
			printf("Cтудент %s %s обучается на факультете %s, номер зачётной книжки %d \n",stud[i].famil,stud[i].name,
					stud[i].facult,stud[i].Nomzach);
		}

	printf("Введите параметр: (1.Фамилия, 2.Имя, 3.Факультет, 4.Номер зачетной книжки) ");
	int param;

	scanf_s("%d", &param);
	switch (param) {
	case 1:           
		printf("Введите фаимилию\n");
		char famil[20];
		scanf_s("%s", famil, 20);
		for (int i = 0; i < 3; i++)
		{
			if (*stud[i].famil == *famil)
			{
				printf("Cтудент %s %s обучается на факультете %s, номер зачётной книжки %d \n", stud[i].famil, stud[i].name,
					stud[i].facult, stud[i].Nomzach);
			}
		}
		break;
	case 2:
		printf("Введите имя\n");
		char name[20];
		scanf_s("%s", name, 20);
		for (int i = 0; i < 3; i++)
		{
			if (*stud[i].name == *name)
			{
				printf("Cтудент %s %s обучается на факультете %s, номер зачётной книжки %d \n", stud[i].famil, stud[i].name,
					stud[i].facult, stud[i].Nomzach);
			}
		}
		break;
	case 3:
		printf("Введите факультет\n");
		char facult[20];
		scanf_s("%s", facult, 20);
		for (int i = 0; i < 3; i++)
		{
			if (*stud[i].facult == *facult)
			{
				printf("Cтудент %s %s обучается на факультете %s, номер зачётной книжки %d \n", stud[i].famil, stud[i].name,
					stud[i].facult, stud[i].Nomzach);
			}
		}
		break;
	case 4:
		printf("Введите номер зачетной книжки\n");
		int Nomzach;
		scanf_s("%d",&Nomzach);
		for (int i = 0; i < 3; i++)
		{
			if (stud[i].Nomzach == Nomzach)
			{
				printf("Cтудент %s %s обучается на факультете %s, номер зачётной книжки %d \n", stud[i].famil, stud[i].name,
					stud[i].facult, stud[i].Nomzach);
			}
		}
		break;
	default:
		printf("Неправильный ввод.\n");
	}
}
