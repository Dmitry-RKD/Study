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
/* Сдать решение задачи F12-Поменять местами
Ограничение времени:	1 с
Ограничение реального времени:	5 с
Ограничение памяти:	64M
Поменять местами
Составить функцию которая меняет в массиве минимальный и максимальный элемент местами. Прототип функции void change_max_min(int size, int a[])
Формат входных данных
Функция принимает на вход размер массива и массив чисел типа int
Формат результата
Функция не возвращает значения, измененный массив сохраняется на месте исходного.
Примеры
Входные данные
1 2 3 4 5 6 7 8 9 10
Результат работы
10 2 3 4 5 6 7 8 9 1 */

#include <stdio.h>
#define SIZE 10 

void inputArr(int n, int *a)
{
    for (int i=0;i<n;i++)
		scanf("%d",&a[i]);
}

void printArr(int *a, int n)
{
    for (int i=0;i<n;i++)
        printf("%d ",a[i]);
}

void change_max_min(int size, int a[])
{
	int i_max=0, i_min=0;
	int max=a[0], min=a[0] ;
	for (int i=1;i<size;i++)
	{
		if (a[i]>max)
		{
			max=a[i];
			i_max=i;
		}
		if (a[i]<min)
		{
			min=a[i];
			i_min=i;
		}
	}
	a[i_max]=min;
	a[i_min]=max;
}

int main(int argc, char **argv)
{
	int a[SIZE];
	inputArr(SIZE,a);
	change_max_min(SIZE,a);
	printArr(a,SIZE);
	
	return 0;
}

