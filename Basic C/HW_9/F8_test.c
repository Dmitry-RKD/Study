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
/* Пропущенное число
В последовательности записаны целые числа от M до N ( M меньше N, M больше или равно 1)в произвольном порядке, но одно из чисел пропущено (остальные встречаются ровно по одному разу). N не превосходит 1000. Последовательность заканчивается числом 0. Определить пропущенное число.
Формат входных данных
Последовательность целых чисел от M до N. M, N не превосходит 1000.
Формат результата
Одно целое число
Примеры
Входные данные
2   3   1   4   7   6   9   8  10   0
Результат работы
5 */

#include <stdio.h>
#define SIZE 1001

int inputArr(int n, int *a)
{
	int count=0;
    for (int i=0;i<n;i++)
    {
		scanf("%d",&a[i]);
		if (a[i]==0)
			break;
		count++;
    }
    return count;
}

void printArr(int *a, int n)
{
    for (int i=0;i<n;i++)
        printf("%d ",a[i]);
}

int max_number_arr(int *a,int N)
{
	int max=a[0];
	int i=1;
	for (i;i<N;i++)
	{
		max=max>a[i]? max:a[i];
	}
	return max;
}
int min_number_arr(int *a,int N)
{
	int min=a[0];
	int i=1;
	for (i;i<N;i++)
	{
		min=min<a[i]? min:a[i];
	}
	return min;
}



int missing_number(int a[], int N)
{
	int max=max_number_arr(a,N);
	int min=min_number_arr(a,N);
	int temp=min;
	int count=0;
//	printf("%d %d",max,min);
	while(temp<max)
	{
		count=0;
		for (int i=0;i<N;i++)
		{
			if (a[i]==temp)
				count++;
		}
		if (count==0)
			return temp;
		temp++;
	}
	return -1;
}


int main(int argc, char **argv)
{
	int a[SIZE];
	int count=0;
	int number;
	count=inputArr(SIZE,a);
	number=missing_number(a,count);
	printf("%d\n",number);
//	printArr(b,count);
	return 0;
}
