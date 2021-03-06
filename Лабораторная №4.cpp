﻿// Зиннер Сергей | Лабораторная работа №4 | Вариант 12

#include "pch.h"
#include <stdio.h>
#include <conio.h>
#include <clocale>
#include <time.h>
#include <stdlib.h>

void LaunchProgram()
{
	printf("\n -------------------------------------------------------\n");
	printf(" =========== З А П У С К   П Р О Г Р А М М Ы ===========\n");
	printf(" -------------------------------------------------------\n");
}
void CallMenu()
{
	printf("\n                                                 \n");
	printf(" [+]==---------------------------------------==[+]\n");
	printf("  |                                             |\n");
	printf("  | = =  М Е Н Ю   П О Л Ь З О В А Т Е Л Я  = = |\n");
	printf("  |                                             |\n");
	printf(" [+]==---------------------------------------==[+]\n");
	printf("  |         В Ы Б Е Р И Т Е   П У Н К Т         |\n");
	printf("  | - - - - - - - - - - - - - - - - - - - - - - |\n");
	printf("  |  [1] - ВВОД РАЗМЕРА И ЭЛЕМЕНТОВ МАТРИЦЫ     |\n");
	printf("  |  [2] - ОБРАБОТКА И ВЫВОД МАТРИЦЫ НА ЭКРАН   |\n");
	printf("  |  [3] - ВЫЗОВ МЕНЮ ПОЛЬЗОВАТЕЛЯ              |\n");
	printf("  |  [4] - ВЫХОД ИЗ ПРОГРАММЫ                   |\n");
	printf("  |                                             |\n");
	printf(" [+]==---------------------------------------==[+]\n\n");
}
void CompletionProgram()
{
	printf("\n -------------------------------------------------------\n");
	printf(" ======= З А В Е Р Ш Е Н И Е   П Р О Г Р А М М Ы =======\n");
	printf(" -------------------------------------------------------\n");
}
void ConclusionError()
{
	printf("\n [+]==---------------------------------------==[+]\n");
	printf("  |         ЭЛЕМЕНТЫ МАТРИЦЫ НЕИЗВЕСТНЫ         |\n");
	printf("  |           ВЫПОЛНИТЕ ПУНКТ ПЕРВЫЙ            |\n");
	printf(" [+]==---------------------------------------==[+]\n\n");
}
int SelectoinMenu()
{
	int arg1;
	char symbol;

	while (scanf_s("%d%c", &arg1, &symbol, 1) != 2 || symbol != '\n' || arg1 < 1 || arg1 > 4)
	{
		HANDLE hOUTPUT = GetStdHandle(STD_OUTPUT_HANDLE);
		SetConsoleTextAttribute(hOUTPUT, FOREGROUND_RED | FOREGROUND_INTENSITY);
		printf("\n [+] - - - - - - - - - - - - - - [+]\n");
		printf("  |  ВВЕДИТЕ КОРРЕКТНОЕ ЗНАЧЕНИЕ  |\n");
		printf(" [+] - - - - - - - - - - - - - - [+]\n\n");
		while (getchar() != '\n');
	}

	return arg1;
}
int InputHeight()
{
	int height;
	char symbol;
	printf("\n [+]==----------------------------------==[+]\n");
	printf("  |         ВВЕДИТЕ ВЫСОТУ МАТРИЦЫ         |\n");
	printf(" [+]==----------------------------------==[+]\n\n");

	while (scanf_s("%d%c", &height, &symbol, 1) != 2 || symbol != '\n' || height < 0)
	{
		HANDLE hOUTPUT = GetStdHandle(STD_OUTPUT_HANDLE);
		SetConsoleTextAttribute(hOUTPUT, FOREGROUND_RED | FOREGROUND_INTENSITY);
		printf("\n [+] - - - - - - - - - - - - - - [+]\n");
		printf("  |  ВВЕДИТЕ КОРРЕКТНОЕ ЗНАЧЕНИЕ  |\n");
		printf(" [+] - - - - - - - - - - - - - - [+]\n\n");
		SetConsoleTextAttribute(hOUTPUT, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
		while (getchar() != '\n');
	}
	return height;
}
int InputWidth()
{
	int width;
	char symbol;

	printf("\n [+]==----------------------------------==[+]\n");
	printf("  |         ВВЕДИТЕ ШИРИНУ МАТРИЦЫ         |\n");
	printf(" [+]==----------------------------------==[+]\n\n");

	while (scanf_s("%d%c", &width, &symbol, 1) != 2 || symbol != '\n' || width < 0)
	{
		HANDLE hOUTPUT = GetStdHandle(STD_OUTPUT_HANDLE);
		SetConsoleTextAttribute(hOUTPUT, FOREGROUND_RED | FOREGROUND_INTENSITY);
		printf("\n [+] - - - - - - - - - - - - - - [+]\n");
		printf("  |  ВВЕДИТЕ КОРРЕКТНОЕ ЗНАЧЕНИЕ  |\n");
		printf(" [+] - - - - - - - - - - - - - - [+]\n\n");
		SetConsoleTextAttribute(hOUTPUT, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
		while (getchar() != '\n');
	}
	return width;
}
int** Paragraph1(int height, int width)
{
	int i;
	int j;
	int point;
	char symbol;
	int** mass = NULL;
	mass = new int*[height];
	for (i = 0; i < height; i++)
	{
		mass[i] = new int[width];
	}

	printf("\n [+]==---------------------------------------==[+]\n");
	printf("  |            ВВОД ЭЛЕМЕНТОВ МАТРИЦЫ           |\n");
	printf("  | - - - - - - - - - - - - - - - - - - - - - - |\n");
	printf("  |  [1] - РУЧНОЙ ВВОД                          |\n");
	printf("  |  [2] - АВТОМАТИЧЕСКИЙ ВВОД                  |\n");
	printf(" [+]==---------------------------------------==[+]\n\n");

	while (scanf_s("%d%c", &point, &symbol, 1) != 2 || symbol != '\n' || point > 2 || point < 1)
	{
		HANDLE hOUTPUT = GetStdHandle(STD_OUTPUT_HANDLE);
		SetConsoleTextAttribute(hOUTPUT, FOREGROUND_RED | FOREGROUND_INTENSITY);
		printf("\n [+] - - - - - - - - - - - - - - [+]\n");
		printf("  |  ВВЕДИТЕ КОРРЕКТНЫЕ ЗНАЧЕНИЯ  |\n");
		printf(" [+] - - - - - - - - - - - - - - [+]\n\n");
		SetConsoleTextAttribute(hOUTPUT, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
		while (getchar() != '\n');
	}

	if (point == 1)
	{
		printf("\n [+]==---------------------------------------==[+]\n");
		printf("  |           ВВЕДИТЕ ЭЛЕМЕНТЫ МАТРИЦЫ          |\n");
		printf(" [+]==---------------------------------------==[+]\n\n");
		for (i = 0; i < height; i++)
		{
			for (j = 0; j < width; j++)
			{
				while (scanf_s("%d%c", &mass[i][j], &symbol, 1) != 2 || symbol != '\n')
				{
					HANDLE hOUTPUT = GetStdHandle(STD_OUTPUT_HANDLE);
		SetConsoleTextAttribute(hOUTPUT, FOREGROUND_RED | FOREGROUND_INTENSITY);
					printf("\n [+] - - - - - - - - - - - - - - [+]\n");
					printf("  |  ВВЕДИТЕ КОРРЕКТНОЕ ЗНАЧЕНИЕ  |\n");
					printf(" [+] - - - - - - - - - - - - - - [+]\n\n");
					SetConsoleTextAttribute(hOUTPUT, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
					while (getchar() != '\n');
				}
			}
		}
	}
	if (point == 2)
	{
		for (i = 0; i < height; i++)
		{
			for (j = 0; j < width; j++)
			{
				mass[i][j] = rand() % 10;
			}
		}
	}

	printf("\n [+]==---------------------------------------==[+]\n");
	printf("  |            ВЫВОД МАТРИЦЫ НА ЭКРАН           |\n");
	printf(" [+]==---------------------------------------==[+]\n\n");

	for (i = 0; i < height; i++)
	{
		printf("\n  %d-Я СТРОКА:", i + 1);
		for (j = 0; j < width; j++)
		{
			printf(" %d ", mass[i][j]);
		}
		printf("\n");
	}
	printf("\n [+]==---------------------------------------==[+]\n");
	printf("  |        ПУНКТ ПЕРВЫЙ УСПЕШНО ВЫПОЛНЕН        |\n");
	printf("  | - - - - - - - - - - - - - - - - - - - - - - |\n");
	printf("  |  [3] - ВЫЗОВ МЕНЮ ПОЛЬЗОВАТЕЛЯ              |\n");
	printf(" [+]==---------------------------------------==[+]\n\n");

	return mass;
}
int** Paragraph2(int** mass1, int height, int width)
{
	int i;
	int j;
	int count = 0;
	if (height == width)
	{
		for (i = 0; i < height; i++)
		{
			for (j = 0; j < width - 1 - i; j++)
			{
				if (mass1[i][j] != mass1[height - 1 - j][width - 1 - i])
				{
					count = count + 1;
				}
			}
		}
		if (count == 0)
		{
			printf("\n [+]==---------------------------------------==[+]\n");
			printf("  |  - - -  ОБРАБОТКА МАТРИЦЫ ЗАВЕРШЕНА  - - -  |\n");
			printf(" [+]==---------------------------------------==[+]\n\n");

			for (i = 0; i < height; i++)
			{
				printf("\n  %d-Я СТРОКА:", i + 1);
				for (j = 0; j < width; j++)
				{
					printf(" %d ", mass1[i][j]);
				}
				printf("\n");
			}

			printf("\n [+]==---------------------------------------==[+]\n");
			printf("  |  - - - - -  МАТРИЦА СИММЕТРИЧНА  - - - - -  |\n");
			printf("  |         ДАННЫЕ ЭЛЕМЕНТЫ СИММЕТРИЧНЫ         |\n");
			printf(" [+]==---------------------------------------==[+]\n\n");
		}
		else
		{
			printf("\n [+]==---------------------------------------==[+]\n");
			printf("  |  - - -  ОБРАБОТКА МАТРИЦЫ ЗАВЕРШЕНА  - - -  |\n");
			printf(" [+]==---------------------------------------==[+]\n\n");

			for (i = 0; i < height; i++)
			{
				printf("\n  %d-Я СТРОКА:", i + 1);
				for (j = 0; j < width; j++)
				{
					printf(" %d ", mass1[i][j]);
				}
				printf("\n");
			}

			printf("\n [+]==---------------------------------------==[+]\n");
			printf("  |  - - - -  МАТРИЦА  НЕ СИММЕТРИЧНА  - - - -  |\n");
			printf("  |    НАЙДЕНО < %d > НЕСОВПАДЕНИЙ ЭЛЕМЕНТОВ    |\n", count);
			printf(" [+]==---------------------------------------==[+]\n\n");
		}
	}
	else
	{
		printf("\n [+]==---------------------------------------==[+]\n");
		printf("  |  - - -  ОБРАБОТКА МАТРИЦЫ ЗАВЕРШЕНА  - - -  |\n");
		printf(" [+]==---------------------------------------==[+]\n\n");

		for (i = 0; i < height; i++)
		{
			printf("\n  %d-Я СТРОКА:", i + 1);

			for (j = 0; j < width; j++)
			{
				printf(" %d ", mass1[i][j]);
			}
			printf("\n");
		}

		printf("\n [+]==---------------------------------------==[+]\n");
		printf("  |  - - - -  МАТРИЦА  НЕ СИММЕТРИЧНА  - - - -  |\n");
		printf("  |    НЕРАВНОМЕРНОЕ КОЛ-ВО СТРОК И СТОЛБЦОВ    |\n");
		printf("  | - - - - - - - - - - - - - - - - - - - - - - |\n");
		printf("  |                 СТРОК < %d >                |\n", height);
		printf("  |                СТОЛБЦОВ < %d >              |\n", width);
		printf(" [+]==---------------------------------------==[+]\n\n");
	}

	printf("\n [+]==---------------------------------------==[+]\n");
	printf("  |        ПУНКТ ВТОРОЙ УСПЕШНО ВЫПОЛНЕН        |\n");
	printf("  | - - - - - - - - - - - - - - - - - - - - - - |\n");
	printf("  |  [3] - ВЫЗОВ МЕНЮ ПОЛЬЗОВАТЕЛЯ              |\n");
	printf(" [+]==---------------------------------------==[+]\n\n");

	count = 0;
	return mass1;
}
void Paragraph3(int** mass2, int height)
{
	for (int i = 0; i < height; i++)
	{
		delete[] mass2[i];
	}
	delete[] mass2;
}
void MainUnit()
{
	LaunchProgram();
	CallMenu();
	int Menu;
	int flag1 = 0;
	int height;
	int width;
	int** mass1 = NULL;
	int** mass2 = NULL;
	do
	{
		Menu = SelectoinMenu();
		switch (Menu)
		{
		case 1:
		{
			height = InputHeight();
			width = InputWidth();

			mass1 = Paragraph1(height, width);
			flag1 = 1;

		}break;

		case 2: 
		{
			if (flag1 == 1)
			{
				mass2 = Paragraph2(mass1, height, width);
				flag1 == 0;

			}
			else
			{
				ConclusionError();
			}
		}break;
		
		case 3:
		{
			CallMenu();

		}break;
		}

	} while (Menu != 4);

	CompletionProgram();
}
int main()
{
	setlocale(LC_ALL, "Rus");
	
	MainUnit();

	getchar();
	return 0;
}


