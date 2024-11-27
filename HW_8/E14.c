/*
 * E14.c
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

/* Более одного раза
Считать массив из 10 элементов и выделить в другой массив все числа, которые встречаются более  одного раза. В результирующем массиве эти числа не должны повторяться.
Формат входных данных
10 целых чисел через пробел
Формат результата
Целые числа через пробел, которые встречаются более одного раза в исходном массиве.
Примеры
Входные данные
4 1 2 1 11 2 34 8 9 10
Результат работы
1 2 */

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

int coppy_repeat_number(int *a, int *b, int n)
{
	int count=0,i=0,j=0,k=0;
	int temp=0;
	int next=0;
	while (i<n)
	{ 
		next=0;
		temp=a[i];
		for(j=i+1;j<n;j++)
		{
			if (temp==a[j])
			{
				for(k=0;k<i;k++)
				{
					if (temp==a[k])
					{
						next=1;
						break ;
					}
				}
				if (next==0)
				{
					b[count]=temp;
					count++;
					break ;
				}
			}
		}
		i++;
	}
//	printf("%d\n",count);	
	return count ;
}

int main(int argc, char *argv[])
{
 int a[SIZE]={0};
 int b[SIZE]={0};
 inputArr(a,SIZE);
 int count=coppy_repeat_number(a,b,SIZE);
 printArr(b,count);
 return 0;
}

