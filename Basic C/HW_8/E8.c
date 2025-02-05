/*
 * E8.c
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
/*Инверсия каждой трети
Считать массив из 12 элементов и выполнить инверсию для каждой трети массива.
Формат входных данных
12 целых чисел через пробел
Формат результата
12 целых чисел через пробел
Примеры
Входные данные
4 -5 3 10 -4 -6 8 -10 1 0 5 7
Результат работы
10 3 -5 4 -10 8 -6 -4 7 5 0 1 */

#include <stdio.h>

#define SIZE 12

int input_arr(int *a, int n) // Функция ввода  массива 
{
//	printf("Введите массив из %d элементов через пробел из",SIZE);
	int i=0;
	for (i=0; i<n; i++)
	{
		scanf("%d", &a[i]);
//		printf("%d ",a[i]);
	} 
	return i;	
}


void SwapArr(int *a,int n,int from, int to) // From to указывают диапазон индексов массива которые необходимо поменять местами
{
	int temp=0;
	from=from-1;
	to=to-1;
	for(from;from<to;from++)
	{
		temp=a[from];
		a[from]=a[to];
		a[to]=temp;
		to--;
	}	
}

void printArr(int *a, int n)
{
	for(int i=0;i<n;i++)
		printf("%d ",a[i]);
}


int main(int argc, char **argv)
{
	int a[SIZE]={0};
	input_arr(a,SIZE);
	SwapArr(a,SIZE,1,4);
	SwapArr(a,SIZE,5,8);
	SwapArr(a,SIZE,9,12);
	printArr(a,SIZE);
	return 0;
}
