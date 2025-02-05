/*
 * E2.c
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
 * Найти минимум
Ввести c клавиатуры массив из 5 элементов, найти минимальный из них.
Формат входных данных
5 целых чисел через пробел
Формат результата
Одно единственное целое число
 */


#include <stdio.h>

#include <stdio.h>

#define SIZE 5

int input_arr(int *a, int n)
{
	int i=0;
	for (i=0; i<n; i++)
	{
		scanf("%d", &a[i]);
//		printf("%d ",a[i]);
	} 
	return i;	
}

int min_arr(int *a, int n)
{
	int i;
	int min=a[0];
	for (i=1;i<n;i++)
	{
		min=min<a[i]? min:a[i];
	}	
	return printf("%d\n",min);
}



int main(int argc, char **argv)
{
	int a[SIZE]={0};
	input_arr(a,SIZE);
	min_arr(a,SIZE);
	return 0;
}

