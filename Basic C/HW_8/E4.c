/*
 * E4.c
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
/* Два максимума
Считать массив из 10 элементов и найти в нем два максимальных элемента и напечатать их сумму.
Формат входных данных
10 целых чисел через пробел.
Формат результата
Сумма двух максимальных элементов.
Примеры
Входные данные
4 -5 3 10 -4 -6 8 -10 1 0
Результат работы
18
*/




#include <stdio.h>

#define SIZE 10 // Размер массива

#define CSMA 2 // указывает сколько max суммирвоать.


//----------------------------------------------------------------------------------------------  Функция ввода  массива 
int input_arr(int *a, int n) 
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

//--------------------------------------------------------------------------------------------- Функция нахождения суммы максимов в колличестве с
int maxs_arr_N(int *a, int n, int c)  
{
	int i;
	int max[c];
	int indx[c];
	int min=a[0], pos=0;
	for (int i=1;i<n;i++)
	{
		if (min>a[i])
		{
			min=a[i];
			pos=i;
		}
	}	
	for (i=0;i<c;i++)
	{
		int j=0;
		max[i]=a[pos]; // присвоение начальное значение равное минимуму массива.
		for (j=0;j<n;j++)
		{
			if (i!=0)
				{
//					printf("%d \n",j);
					for (int k=0;k<i;k++) // для исключения повторяющихся max по индексам max 100 200 3 4 5 6 7 8 9 10
					{
						if (indx[k]==j)
							goto next;
					}
				}
//			printf("%d \n",j);
			if (max[i]<a[j])
			{
				max[i]=a[j];
				indx[i]=j;
			}
			next: ;
		}
//	printf("\n %d ", max[i]);
	}
	int result=0;
	for (i=0;i<c;i++)
		result+=max[i];
	return result;
}

int main(int argc, char **argv)
{
	int a[SIZE]={0};
	int result=0;
	input_arr(a,SIZE);
	result=maxs_arr_N(a,SIZE,CSMA);
	printf("%d\n",result);
	return 0;
}
