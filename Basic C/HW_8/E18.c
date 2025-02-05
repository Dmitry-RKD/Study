/*
 * E18.c
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
/*  Кратность прежде всего
В диапазоне натуральных чисел от 2 до N определить, сколько из них кратны любому из чисел в диапазоне от 2 до 9.
Формат входных данных
Одно целое число N большее 2 и не превосходящее 10000
Формат результата
Все числа от 2 до 9 в формате: 2 количество чисел кратных 2 3 количество чисел кратных 3 4 количество чисел кратных 4 5 количество чисел кратных 5 6 количество чисел кратных 6 7 количество чисел кратных 7 8 количество чисел кратных 8 9 количество чисел кратных 9
Примеры
Входные данные
99
Результат работы
2  49
3  33
4  24
5  19
6  16
7  14
8  12
9  11 */

#include <stdio.h>

void print_number(int a)
{
	int temp=2;
	while (temp<10)
	{
		int count=0;
		for(int i=temp;i<=a;i++)
		{
			if (i%temp==0)
				count++;
		}
	printf("%d	%d\n",temp, count);
	temp++;
	}
}

int main(int argc, char **argv)
{
	int a;
	scanf("%d",&a);
	print_number(a);	
	return 0;
}

