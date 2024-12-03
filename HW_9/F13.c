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
/* СВ заданном интервале
Составить функцию которая возвращает количество элементов на заданном отрезке [from, to] для массива. Прототип функции int count_between(int from, int to, int size, int a[]) Например, на отрезке [4, 6] в массиве 1 2 3 4 5 6 7 8 9 10 функция вернет 3 значения
Формат входных данных
Функция принимает значения концов отрезка from и to, размер массива, массив целых чисел.
Формат результата
Функция возвращает целое число - количество числе в интервале [from, to]
Примеры
Входные данные
4 6 1 2 3 4 5 6 7 8 9 10
Результат работы
3 */

#include <stdio.h>
#define SIZE 12 

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

int count_between(int from, int to, int size, int a[]) 
{
	int count=0;
	for (int i=0;i<size;i++)
	{
		if (a[i]>=from && a[i]<=to)
		count++;
	}
	return count;
}


int main(int argc, char **argv)
{
	int a[SIZE];
	int count=0;
	inputArr(SIZE,a);
	count=count_between(4,6,SIZE,a);
	printf("%d\n",count);
	return 0;
}

