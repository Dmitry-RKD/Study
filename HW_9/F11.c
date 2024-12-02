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
/* Сумма минимальна
Дан целочисленный массив из 30 элементов. Элементы массива могут принимать произвольные целые значения помещающиеся в int. Необходимо создать функцию, которая находит и выводит в порядке возрастания номера двух элементов массива, сумма которых минимальна.
Формат входных данных
Последовательность из 30 целых чисел через пробел
Формат результата
Два целых числа через пробел
Примеры
Входные данные
1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 17 18 19 20 21 22 23 24 25 26 27 28 29 30
Результат работы
0 1 */

#include <stdio.h>
#define SIZE 30

void inputArr(int n, int *a)
{
    for (int i=0;i<n;i++)
		scanf("%d",&a[i]);
}

void print_2_index(int *a, int n)
{
	int index[2]={0,1};
	int i=0;
	int j=0;
	int temp=0;
	int sum=a[0]+a[1];
	while (i<n)
	{
		for (j=0;j<n;j++)
		{
			if (i==j)
				j++ ;
			temp=a[i]+a[j];
			if (sum>temp)
			{
				sum=temp;
				index[0]=i;
				index[1]=j;
			}
		}
		i++;
	}
//	printf("%d\n",sum);
	if (index[0]<index[1])
		printf("%d %d\n",index[0],index[1]);
	else 
		printf("%d %d\n",index[1],index[0]);
}


int main(int argc, char **argv)
{
	int a[SIZE];
	inputArr(SIZE,a);
	print_2_index(a,SIZE);
	return 0;
}

