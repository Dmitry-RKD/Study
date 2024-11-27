/*
 * E17.c
 * 
 * Copyright 2024 Дмитрий <Дмитрий@DESKTOP-V4T7I45>
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

/* Только один раз
Дан массив из 10 элементов. В массиве найти элементы, которые в нем встречаются только один раз, и вывести их на экран.
Формат входных данных
10 целых чисел через пробел
Формат результата
Элементы которые встречаются только один раз через пробел */

#include <stdio.h>
# define SIZE 10

void inputArr(int *a, int n)
{
    for (int i=0;i<n;i++)
        scanf("%d",&a[i]);
}

void printArr(int *a, int n)
{
    for (int i=0;i<n;i++)
        printf("%d ",a[i]);
}

void print_non_repeat_numbers(int *a, int n)
{
	int i=0;
	int temp=0;
	while (i<n)
	{
		int count=0;
		temp=a[i];
		for(int j=0;j<n;j++)
		{
			if (temp==a[j])
				count++;
		}
		if (count==1)
			printf("%d ",a[i]);
		i++;
	}
}

int main(int argc, char **argv)
{
	int a[SIZE];
	inputArr(a,SIZE);
	print_non_repeat_numbers(a,SIZE);
	
	return 0;
}

