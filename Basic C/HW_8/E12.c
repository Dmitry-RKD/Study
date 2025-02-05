/*
 * E12.c
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
/* По убыванию и по возрастанию
Считать массив из 10 элементов и отсортировать первую половину по возрастанию, а вторую – по убыванию.
Формат входных данных
10 целых чисел через пробел
Формат результата
Исходный массив. Первая часть отсортирована по возрастанию, вторая половина по убыванию.
Примеры
Входные данные
14  25  13  30  76  58  32  11  41  97 */

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

void sorting_dicrease(int *a, int n,int from, int to)
{
    int temp=0;
    from-=1;
    to-=1;
    while (from<to)
    {
        temp=a[from];
        for (int j=from;j<to;j++)
        {
            if (temp<a[j+1])
            {
                temp=a[j+1];
                a[j+1]=a[from];
                a[from]=temp;
            }
        }
         from++;
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
 inputArr(a,SIZE);
 sorting_increase(a,SIZE,1,5);
 sorting_dicrease(a,SIZE,6,10);
 printArr(a,SIZE);
 return 0;
}
