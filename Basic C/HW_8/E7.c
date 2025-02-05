/*
 * E7.c
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
/* Инверсия половинок
Считать массив из 10 элементов и выполнить инверсию отдельно для 1-ой и 2-ой половин массива. Необходимо изменить считанный массив и напечатать его одним циклом.
Формат входных данных
10 целых элементов массива через пробел.
Формат результата
10 целых элементов массива через пробел.
Примеры
Входные данные
4 -5 3 10 -4 -6 8 -10 1 0
Результат работы
-4 10 3 -5 4 0 1 -10 8 -6 */

#include <stdio.h>

#define SIZE 10

int input_arr(int *a, int n) // Функция ввода  массива 
{
//	printf("Введите массив из %d элементов через пробел",SIZE);
	int i=0;
	for (i=0; i<n; i++)
	{
		scanf("%d", &a[i]);
//		printf("%d ",a[i]);
	} 
	return i;	
}


void invertor_arr(int *a,int n)
{
	int temp=0;
	int i;
	int j;
	int k;
	for(i=0;i<n;i++)
	{
		if (i<2)
		{	
			j=4;
			k=9;
			temp=a[j-i];
			a[j-i]=a[i];
			a[i]=temp;
			temp=a[k-i];
			a[k-i]=a[5+i];
			a[5+i]=temp;
		}

		printf("%d ",a[i]);
	}	
}


int main(int argc, char **argv)
{
	int a[SIZE]={0};
	input_arr(a,SIZE);
	invertor_arr(a,SIZE);
	
	return 0;
}

