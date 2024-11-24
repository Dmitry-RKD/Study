/*
 * E5.c
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

/* Сумма положительных элементов
Считать массив из 10 элементов и посчитать сумму положительных элементов массива.
Формат входных данных
10 целых чисел через пробел
Формат результата
Одно целое число - сумма положительных элементов массива
Примеры
Входные данные
4 -5 3 10 -4 -6 8 -10 1 0
Результат работы
26 */

#include <stdio.h>

#define SIZE 10 // Размер массива

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

int sum_PE_arr(int *a, int n) // Функция нахождения суммы + положительных элементов массива.
{
	int i;
	int result=0;
	
	for (i=0;i<n;i++)
	{
		if (a[i]>0)
			result+=a[i];
	}	
	return result;
}



int main(int argc, char **argv)
{
	int a[SIZE]={0};
	int result=0;
	input_arr(a,SIZE);
	result=sum_PE_arr(a,SIZE);
	printf("%d\n",result);
	return 0;
}

