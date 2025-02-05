/*
 * E10.c
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
/* Циклический сдвиг массива вправо на 4
Считать массив из 12 элементов и выполнить циклический сдвиг ВПРАВО на 4 элемента.
Формат входных данных
12 целых чисел через пробел
Формат результата
12 целых чисел через пробел */

#include <stdio.h>

#define SIZE 12

#define shift 4 // определяет разряды для сдвига элементов массива

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

void printArr(int *a, int n)
{
	for(int i=0;i<n;i++)
		printf("%d ",a[i]);
}

void shiftArr_R(int *a,int n, int k) // определяет на сколько разрядов осуществить сдвиг вправо
{
	int count=0;
	while (count!=shift)
	{
		int temp=a[SIZE-1];
			for(int i=SIZE-1;i>0;i--)				
				a[i]=a[i-1];
		a[0]=temp;
		count++;
	}	
}

int main(int argc, char **argv)
{
	int a[SIZE]={0};
	input_arr(a,SIZE);
	shiftArr_R(a,SIZE,shift);
	printArr(a,SIZE);	
	return 0;
}
