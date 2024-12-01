
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
/* Сдать решение задачи F3-Цифры по возрастанию
Ограничение времени:	1 с
Ограничение реального времени:	5 с
Ограничение памяти:	64M
Цифры по возрастанию
Написать функцию и программу демонстрирующую работу данной функции. Вывести в порядке возрастания цифры, входящие в десятичную запись натурального числа N, не более 1000 цифр. Цифра пробел сколько раз данная цифра встречается в числе.
Формат входных данных
Натуральное число не более 1000 цифр
Формат результата
Цифры входящие в число через пробел в порядке возрастания. От самой младшей цифры до самой старшей и количество.
Примеры
Входные данные
54321
Результат работы
1 1
2 1
3 1
4 1
5 1 */

#include <stdio.h>
#include <string.h>


void number_count(char *a)
{	
	int SIZEa=strlen(a);
//	printf("%d\n",SIZEa);
	int i=0;
	int j=0;
	int count[10]={};
	for(i=0;i<SIZEa;i++)
		{
//			printf("%d\n",a[i]);
			for (j=0;j<10;j++)
			{
				if ((a[i]-'0')==j)
					count[j]++;
			}
		}
		for (j=0;j<10;j++)
		{
			if (count[j]>0)
			printf("%d %d\n",j,count[j]);
		}
}


int main(int argc, char **argv)
{
	char a[1001];
	scanf("%s",a);
	number_count(a);
	
	return 0;
}

