/*
 * F14.c
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
/* Сумма в интервале
Составить функцию которая возвращает сумму элементов в заданном отрезке [from, to] для массива. Прототип функции int sum_between_ab(int from, int to, int size, int a[])
Формат входных данных
Функция принимает концы отрезка from и to, размер массива, массив целых чисел
Формат результата
Функция возвращает сумму элементов в интервале [from, to]
Примеры
Входные данные
4 6 1 2 3 4 5 6 7 8 9 10
Результат работы
15 */

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

int sum_between_ab(int from, int to, int size, int a[])
{
	int sum=0;
	if (from>to)
	{
		int temp=from;
		from=to;
		to=temp;
	}
	for (int i=0;i<size;i++)
	{
		if (a[i]>=from && a[i]<=to)
		sum+=a[i];
	}
	return sum;
}


int main(int argc, char **argv)
{
	int a[SIZE];
	int sum=0;
	inputArr(SIZE,a);
	sum=sum_between_ab(3,5,SIZE,a);
	printf("%d\n",sum);
	return 0;
}


