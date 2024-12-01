/*
 * F2.c
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
/* Сдать решение задачи F5-Максимум в массиве
Ограничение времени:	1 с
Ограничение реального времени:	5 с
Ограничение памяти:	64M
Максимум в массиве
Написать только одну функцию, которая находит максимальный элемент в массиве. Всю программу загружать не надо.
Прототип функции: int find_max_array(int size, int a[])
Формат входных данных
Массив состоящий из целых чисел. Первый аргумент, размер массива, второй аргумент адрес нулевого элемента.
Формат результата
Одно целое число
Примеры
Входные данные
773 307 371 548 531 765 402 27 573 591 217 859 662 493 173 174 125 591 324 231 130 394 573 65 570 258 343 3 586 14 785 296 140 726 598 262 807 794 510 465 66 895 182 218 302 34 205 252 687 660 952 737 2 32 310 680 36 139 346 139 489 217 767 544 158 774 883 154 802 136 569 377 867 423 224 176 118 660 513 734 45 978 983 749 909 601 270 147 433 737 789 304 842 769 815 503 190 399 3
Результат работы
983 */

#include <stdio.h>
#define SIZE 10

void inputArr(int n, int *a)
{
    for (int i=0;i<n;i++)
        scanf("%d",&a[i]);
}

int find_max_array(int size, int a[])
{
	int max=a[0] ;
	int i=1;
	for (i;i<size;i++)
	{
		max=max>a[i]? max: a[i];
	}
	return max;
}


int main(int argc, char **argv)
{
	int a[SIZE];
	printf("Введите массив из %d элементов через пробел\n",SIZE);
	inputArr(SIZE,a);
	int max;
	max=find_max_array(SIZE,a);
	printf("%d \n",max);
	return 0;
}

