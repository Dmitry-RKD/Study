/*
 * F1.c
 * 
 * Copyright 2024 Dmitry <Dmitry@DESKTOP-J3GNGPV>
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
/* Сдать решение задачи F1-Сортировка по возрастанию
Ограничение времени:	1 с
Ограничение реального времени:	5 с
Ограничение памяти:	64M
Сортировка по взрастанию
Написать только одну функцию, которая сортирует массив по возрастанию. Необходимо реализовать только одну функцию, всю программу составлять не надо.
Строго согласно прототипу. Имя функции и все аргументы должны быть: void sort_array(int size, int a[]).
Всю программу загружать не надо, только одну эту функцию. Можно просто закомментировать текст всей программы, кроме данной функции.
Формат входных данных
Функция принимает на вход, первый аргумент - размер массива, второй аргумент - адрес нулевого элемента.
Формат результата
Функция ничего не возвращает. Производит сортировку переданного ей массива по возрастанию.
Примеры
Входные данные
20 19 4 3 2 1 18 17 13 12 11 16 15 14 10 9 8 7 6 5
Результат работы
1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 17 18 19 20 */

#include <stdio.h>
# define SIZE 10

int input_arr(int n, int *a) // Функция ввода  массива 
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

void printArr(int n, int *a)
{
	for(int i=0;i<n;i++)
		printf("%d ",a[i]);
}

void sort_array(int size, int a[])
{
	int i=0;
	int temp=0;
	while (i<size)
	{
		temp=a[i];
		for (int j=i+1;j<size;j++)
		{
			if (a[j]<temp)
			{
				a[i]=a[j];
				a[j]=temp;
				temp=a[i];
			}
		}
		i++;
	}
	
}

int main(int argc, char **argv)
{
	int a[SIZE]={0};
	input_arr(SIZE,a);
	sort_array(SIZE,a);
	printArr(SIZE,a);
	return 0;
}

