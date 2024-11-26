/*
 * E11.c
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
/* Отсортировать по последней цифре
Считать массив из 10 элементов и отсортировать его по последней цифре.
Формат входных данных
10 целых чисел через пробел
Формат результата
Этот же массив отсортированный по последней цифре */

#include <stdio.h>
# define SIZE 10

void sortingLN(int *a, int n)
{
    int temp=0;
    int i=0;
    while (i<n)
    {
        temp=a[i];
        for (int j=i;j<n-1;j++)
        {
            if (temp%10>a[j+1]%10)
            {
                temp=a[j+1];
                a[j+1]=a[i];
                a[i]=temp;
            }
        }
         i++;
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
 sortingLN(a,SIZE);
 printArr(a,SIZE);
 return 0;
}

