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
/* Сдать решение задачи F2-Четные в начало
Ограничение времени:	1 с
Ограничение реального времени:	5 с
Ограничение памяти:	64M
Четные в начало
Написать только одну функцию, которая ставит в начало массива все четные элементы, а в конец – все нечетные. Не нарушайте порядок следования чисел между собой. Строго согласно прототипу:.
void sort_even_odd(int n, int a[])
Формат входных данных
Функцийя принмате на вход целые числа
Формат результата
Отсортированный исходный массив
Примеры
Входные данные
20 19 18 17 16 15 14 13 12 11 10 9 8 7 6 5 4 3 2 1
Результат работы
20 18 16 14 12 10 8 6 4 2 19 17 15 13 11 9 7 5 3 1 */

#include <stdio.h>
# define SIZE 21

int input_arr(int n, int *a) // Функция ввода  массива 
{
//	printf("Введите массив из %d элементов через пробел из",SIZE);
	int i=0;
	for (i=0; i<n; i++)
	{
		scanf("%d", &a[i]);
//		printf("%d ",a[i]);
	} 
	return i;	
}

void printArr(int n, int *a)
{
	for(int i=0;i<n;i++)
		printf("%d ",a[i]);
}

void sort_even_odd(int n, int a[])
{
	int indx1=n-1;
	int indx0=0;
	int temp[n];
	int i=0;
	for (i=0;i<n;i++)
	{
		if (a[i]%2==0)
		{	
			temp[indx0]=a[i];
			indx0++;
		}
	}
	for(i=n-1;i>0;i--) 
	{
		if (a[i]%2!=0)
		{
			temp[indx1]=a[i];
			indx1--;
		}
	}
	
	for (i=0;i<n;i++)
		a[i]=temp[i];
}

int main(int argc, char **argv)
{
	int a[SIZE]={0};
	input_arr(SIZE,a);
	sort_even_odd(SIZE,a);
	printArr(SIZE,a);
	return 0;
}

