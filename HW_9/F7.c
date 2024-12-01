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
/* Упаковать 0 и 1
Написать функцию, которая сжимает серии массива, состоящего из единиц и нулей по следующему принципу: например, массив [0,0,0,0,1,1,1,1,1,1,1,0,0,1,1,1,1] преобразуется в [4,7,2,4] (т.к. начинается с нуля, то сразу записывается количество элементов первой серии); а массив [1,1,1,0,0,0,0,0,0,0] преобразуется в [0,3,7] (т.к. первая серия - это единицы, то первый элемент преобразованного массива 0).
Необходимо реализовать только одну функцию, всю программу загружать не надо. Прототип функции: int compression(int a[], int b[], int N)
Формат входных данных
Функция принимает исходный массив a[] и сжимает в массив b[], N - число элементов в массиве a[].
Формат результата
Функция возвращает число элементов сжатого массива b[]
Примеры
Входные данные
1 1 0 0 1 1 1 0 1 1 0 0 1 0 1 0 0 1 0 0 0 0 1 1 1 1 0 1 0 0 0 0 1 1 1 0 1 1 0 1 0 0 0 1 1 0 0 1 0 0 0 1 0 0 1 1 1 0 1 0 0 0 0 0 0 1 0 1 0 0 1 1 0 1 0 0 0 0 1 0 0 1 1 0 1 0 0 0 1 0 1 1 1 1 1 1 0 1 0 0
Результат работы
[0,2,2,3,1,2,2,1,1,1,2,1,4,4,1,1,4,3,1,2,1,1,3,2,2,1,3,1,2,3,1,1,6,1,1,1,2,2,1,1,4,1,2,2,1,1,3,1,1,6,1,1,2] */

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

int compression(int a[], int b[], int N)
{
	int count_d=0; 
	int count_e=0;
	int i=0;
	if(a[0]==1)
		{
			b[0]=0;
			count_e++;
		}
	int j=0;
	while (i<N)
	{	
		count_d=1;
		for (j=i+1;j<N;j++)
		{
			if(a[j]==a[i])
				count_d++;
			else
				break ;
		}
	b[count_e]=count_d;
	count_e++;
	i=j;
	}
	return count_e;
}


int main(int argc, char **argv)
{
	int a[SIZE];
	int b[SIZE];
	int count=0;
	printf("Введите массив из %d элементов через пробел\n",SIZE);
	inputArr(SIZE,a);
	count=compression(a,b,SIZE);
	printf("%d\n",count);
	printArr(b,count);
	return 0;
}

