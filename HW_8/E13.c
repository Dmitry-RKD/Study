/*
 * E13.c
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
/* Вторая с конца ноль
Считать массив из 10 элементов и отобрать в другой массив все числа, у которых вторая с конца цифра (число десятков) – ноль.
Формат входных данных
10 целых чисел через пробел.
Формат результата
Целые числа через пробел, у котороых вторая с конца цифра - ноль
Примеры
Входные данные
40 105 203 1 14 1000 22 33 44 55
Результат работы
105 203 1 1000 */

#include <stdio.h>
# define SIZE 10

void sorting_increase(int *a, int n,int from, int to)
{
    int temp=0;
    from-=1;
    to-=1;
    while (from<to)
    {
        temp=a[from];
        for (int j=from;j<to;j++)
        {
            if (temp>a[j+1])
            {
                temp=a[j+1];
                a[j+1]=a[from];
                a[from]=temp;
            }
        }
         from++;
    }
}

int E13_count(int *a, int n)
{
    int count=0;
		
		for (int i=0;i<n;i++)
        {
            if ((a[i]/10)%10==0)
				count++;
        }
        return count++;
}


void sorting_x0x(int *a,int n, int *b)
{
	int i=0;
	for (int j=0;j<n;j++)
		{
			if ((a[j]/10)%10==0)
			{
				b[i]=a[j] ;
				i++;
			}
		}
}
//

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

int main(int argc, char *argv[])
{
 int a[SIZE]={0};
 int b[SIZE]={0};
 inputArr(a,SIZE);
 int count=E13_count(a,SIZE);
 sorting_x0x(a,SIZE,b);
 printArr(b,count);
 return 0;
}

