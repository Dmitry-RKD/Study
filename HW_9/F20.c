/*
 * F20.c
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
/* Четные и нечетные
Дан целочисленный массив из 10 элементов. Необходимо определить количество четных и нечетных чисел. Если количество чётных чисел больше, чем количество нечётных, заменить каждое нечетное число на произведение нечетных цифр в его десятичной записи. Если количество нечётных чисел больше или равно количеству чётных, заменить каждое чётное число на произведение чётных цифр в его десятичной записи.
Формат входных данных
10 целых чисел через пробел
Формат результата
10 целых чисел через пробел
Примеры
Входные данные
48 31 20 61 97 12 18 100 200 123
Результат работы
48 3 20 1 63 12 18 100 200 3
Входные данные
48 25 57 34 23 91 90 85 30 79
Результат работы
32 25 57 4 23 91 0 85 0 79 */

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

void F20(int n, int *a)
{
	int count_even=0;
	int count_odd=0;
	for(int i=0;i<n;i++)
	{
		if (a[i]%2==0)
			count_even++;
		else
			count_odd++;
	}
	if (count_even>count_odd)
	{
		int temp=0;
		int temp1=1;
		for(int i=0;i<n;i++)
		{
			if (a[i]%2==1)
			{
				temp=a[i];
				temp1=1;
				while(temp!=0)
				{
					int k=temp%10;
					if(k%2==1)
						temp1*=k;
					temp=temp/10;
				}
				a[i]=temp1;
			}
		}
	}
	else
	{
		int temp=0;
		int temp1=1;
		for(int i=0;i<n;i++)
		{
			if (a[i]%2==0)
			{
				temp=a[i];
				temp1=1;
				while(temp!=0)
				{
					int k=temp%10;
					if(k%2==0)
						temp1*=k;
					temp=temp/10;
				}
				a[i]=temp1;
			}
		}
	}
}

int main(int argc, char **argv)
{
	int a[SIZE];
	inputArr(SIZE,a);
	F20(SIZE,a);	
	printArr(a,SIZE);
	return 0;
}

