/*
 * F15.c
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
/* Больше по модулю
Составить функцию которая определяет в массиве, состоящем из положительных и отрицательных чисел, сколько элементов превосходят по модулю максимальный элемент. Прототип функции int count_bigger_abs(int n, int a[]); Например, на отрезке [4, 6] в массиве 1 2 3 4 5 6 7 8 9 10 функция вернет 3 значения
Формат входных данных
Функция получает размер массива и массив целых чисел
Формат результата
Функция возвращает целое число равное количеству элементов превосходящих по модулю максимальный элемент.
Примеры
Входные данные
1 -20 3 4 -50 6 7 8 9 10
Результат работы
2 */

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

int count_bigger_abs(int n, int a[])
{
	int temp=0;
	int count=0;
	int max=a[0];
	int i=0;
	for (i=1;i<n;i++)
	{
		if (max<a[i])
		max=a[i];
	}
	for (i=0;i<n;i++)
	{	
		temp=a[i];
		if (temp<0)
			temp=0-temp;
		if (temp>max)
			count++;
	}
	
	return count;
}


int main(int argc, char **argv)
{
	int a[SIZE];
	int count=0;
	inputArr(SIZE,a);
	count=count_bigger_abs(SIZE,a);
	printf("%d\n",count);
	return 0;
}

