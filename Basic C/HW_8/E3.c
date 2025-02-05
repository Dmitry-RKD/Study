/*
 * E3.c
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
 \
 /*Максимум и минимум
Считать массив из 10 элементов и найти в нем максимальный и минимальный элементы и их номера.
Формат входных данных
10 целых чисел через пробел
Формат результата
4 целых числа через пробел: номер максимума, максимум, номер минимума, минимум.
Примеры
Входные данные
4 -5 3 10 -4 -6 8 -10 1 0 */




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

int min_arr(int *a, int n) // Функция поиска минимального значения массива
{
	int i;
	int min=a[0];
	for (i=1;i<n;i++)
	{
		min=min<a[i]? min:a[i];
	}	
//	return printf("%d\n",min);
	return min;
}


int max_arr(int *a, int n) //  Функция поиска максимального значения массива
{
	int i;
	int max=a[0];
	for (i=1;i<n;i++)
	{
		max=max>a[i]? max:a[i];
	}	
//	return printf("%d\n",max);
	return max;
}


int min_index(int *a, int n) //  Функция поиска индекса(нумерация с 1) эемента массива хранящего минимальное значение массива
{
	int min=a[0], pos=1;
	for (int i=1;i<n;i++)
	{
		if (min>a[i])
		{
			min=a[i];
			pos=i+1;
		}
	}	
	return pos;
//	return printf("%d\n",pos);
}

int max_index(int *a, int n) //  Функция поиска индекса(нумерация с 1) эемента массива хранящего максимальгное значение массива
{
	int max=a[0], pos=1;
	for (int i=1;i<n;i++)
	{
		if (max<a[i])
		{
			max=a[i];
			pos=i+1;
		}
	}	
	return pos;
//	return printf("%d\n",pos);
}



int main(int argc, char **argv)
{
	int a[SIZE]={0};
	int p_min=0,p_max=0,min_a=0,max_a=0;
	input_arr(a,SIZE);
	max_a=max_arr(a,SIZE);
	min_a=min_arr(a,SIZE);
	p_min=min_index(a,SIZE);
	p_max=max_index(a,SIZE);
	printf("%d %d %d %d",p_max,max_a,p_min,min_a);
	return 0;
}



