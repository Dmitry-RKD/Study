/*
 * E1.c
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
/* Ввести c клавиатуры массив из 5 элементов, найти среднее арифметическое всех элементов массива.
Формат входных данных
5 целых не нулевых чисел через пробел
Формат результата
Олно число в формате "%.3f" */

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

float arithmetic_mean(int *a, int n)
{ 
	float am_sum=0;
	for(int i=0;i<n; i++)
		am_sum+=a[i];
	am_sum= (float) am_sum/n;
//	printf("am_sum = %.3f\n",am_sum);
	return am_sum;	
}



int main(int argc, char **argv)
{
	int a[SIZE]={0};
	float sum=0;
	input_arr(a,SIZE);
	sum=arithmetic_mean(a,SIZE);
	printf("%.3f\n",sum);
	
}

