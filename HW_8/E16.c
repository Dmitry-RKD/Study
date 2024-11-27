/*
 * E16.c
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
/* Чаще других
Дан массив из 10 элементов. Определить, какое число в массиве встречается чаще всего. Гарантируется, что такое число ровно 1.
Формат входных данных
10 целых числе через пробел
Формат результата
Одно число, которое встречается чаще других.
Примеры
Входные данные
4  1  2  1  11  2  34  11  0  11
Результат работы
11 */

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

void max_repeat_number(int *a, int n)
{
	int i=0;
	int temp=0;
	int max=0;
	int pos_max=0;
	while (i<n)
	{
		int count=0;
		temp=a[i];
		for(int j=i+1;j<n;j++)
		{
			if (temp==a[j])
				count++;
		}
		if (count>max)
		{
			max=count;
			pos_max=i;
		}
		i++;
	}
	if (max>0)
		printf("%d\n",a[pos_max]);
	else
		printf("No duplicate numbers found in the array!\n");
}

int main(int argc, char **argv)
{
	int a[SIZE];
	inputArr(a,SIZE);
	max_repeat_number(a,SIZE);
	
	return 0;
}

