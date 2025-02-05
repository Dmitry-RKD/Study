/*
 * F2.c
 * 
 * Copyright 2024 Dmitry <Dmitry@DESKTOP-J3GNGPV>
 * 
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 * 
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 * 
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston,
 * MA 02110-1301, USA.
 * 
 * 
 */
/* Два одинаковых
Написать только одну логическую функцию, которая определяет, верно ли, что среди элементов массива есть два одинаковых. Если ответ «да», функция возвращает 1; если ответ «нет», то 0. Строго согласно прототипу:
int is_two_same(int size, int a[]);
Формат входных данных
Массив из целых чисел
Формат результата
Функция возвращает 1 или 0
Примеры
Входные данные
1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 17 18 19 20 21 22 23 24 25 26 27 28 29 30 31 32 33 34 35 36 37 38 39 40 41 42 43 44 45 46 47 48 49 50 51 52 53 54 55 56 57 58 59 60 61 62 63 64 65 66 67 68 69 70 71 72 73 74 75 76 77 78 79 80 81 82 83 84 85 86 87 88 89 90 91 92 93 94 95 96 97 98 99 100
Результат работы
NO
Входные данные
1 2 1 4 5
Результат работы
YES */

#include <stdio.h>
#define SIZE 10

void inputArr(int n, int *a)
{
    for (int i=0;i<n;i++)
        scanf("%d",&a[i]);
}

int is_two_same(int size, int a[])
{
	int count=0; ;
	int i=0;
	while (i<size-1)
	{
		count=0;	
		for (int j=0;j<size;j++)
		{
			if(a[j]==a[i])
				count++;
		}
		if (count>1)
			return 1;
	i++;
	}
	return 0;
}


int main(int argc, char **argv)
{
	int a[SIZE];
	printf("Введите массив из %d элементов через пробел\n",SIZE);
	inputArr(SIZE,a);
	is_two_same(SIZE, a);
}

