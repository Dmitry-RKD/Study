/*
 * E15.c
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

/* Положительные и отрицательные
Считать 10 чисел в диапазоне от -500 до 500 и разложить по двум массивам: в одни помещать только положительные, во второй - только отрицательные. Числа, равные нулю, игнорировать. Вывести на экран все элементы обоих массивов.
Формат входных данных
10 целых чисел через пробел.
Формат результата
Сперва положительные числа, потом отрицательыне числа, через пробел.
Примеры
Входные данные
5 -4 0 1 4 -3 -3 3 0 2
Результат работы
5 1 4 3 2 -4 -3 -3 */

#include <stdio.h>
# define SIZE 10

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

void sorting_NandP_number(int *a, int n, int *b, int *c)
{
	int neg=0;
	int posit=0;
	int i=0;
	for (i=0;i<n;i++)
	{
		if (a[i]>0)
		{
			b[posit]=a[i];
			posit++;
		}
		else if (a[i]<0)
		{
			c[neg]=a[i];
			neg++;
		}
	}
	printArr(b,posit);
	printArr(c,neg);
	
}


int main(int argc, char **argv)
{
	int a[SIZE];
	int positiv[SIZE];
	int negative[SIZE];
	inputArr(a,SIZE);
	sorting_NandP_number(a,SIZE,positiv,negative);
	return 0;
}

