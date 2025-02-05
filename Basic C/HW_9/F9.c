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
/* Поменять местами
Составить только функцию которая в массиве находит максимальный из отрицательных элементов и меняет его местами с последним элементом массива. Гарантируется, что в массиве только один такой элемент или же такой элемент отсутствует. Если отрицательных элементов нет - массив не менять.
Прототип функции: void swap_negmax_last(int size, int a[])
Формат входных данных
Функция принимает на вход размер массива и указатель на начало массива. Массив состоит из целых чисел.
Примеры
Входные данные
1 -2 -3 -4 5 6 7 8 9 10
Результат работы
1 10 -3 -4 5 6 7 8 9 -2 */

#include <stdio.h>
#define SIZE 10

void inputArr(int n, int *a)
{
    for (int i=0;i<n;i++)
    {
		scanf("%d",&a[i]);
    }
}

void printArr(int *a, int n)
{
    for (int i=0;i<n;i++)
        printf("%d ",a[i]);
}

void swap_negmax_last(int size, int a[])
{
	int negmax;
	int flag=1;
	int i=0;
	int indx=0;
	for (i=0;i<size;i++)
	{
		if (a[i]<0 && flag==1)
		{
			negmax=a[i];
			flag=0;
			indx=i;
		}
		if (a[i]<0 && flag==0)
		{
			if (negmax<a[i])
			{
				negmax=a[i];
				indx=i;
			}
		}
	}
	if (flag==0)
	{
		i=a[size-1];
		a[size-1]=a[indx];
		a[indx]=i;		
	}	
}


int main(int argc, char **argv)
{
	int a[SIZE];
	inputArr(SIZE,a);
	swap_negmax_last(SIZE,a);
	printArr(a,SIZE);
	return 0;
}

