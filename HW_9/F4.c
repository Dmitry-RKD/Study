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
/* Сдать решение задачи F4-Цифры в строке
Ограничение времени:	1 с
Ограничение реального времени:	5 с
Ограничение памяти:	64M
Цифры в строке
Написать только одну функцию. Всю программу отправлять не надо. Вывести в порядке возрастания цифры, входящие в строку. Цифра - количество. Функция должно строго соответствовать прототипу:
void print_digit(char s[])
Формат входных данных
Строка из английских букв, пробелов, знаков препинания и цифр
Формат результата
Функция должна принмать на вход строку и выводить на печать по формату: Цифра пробел количество.
Примеры
Входные данные
Hello123 world77.
Результат работы
1 1
2 1
3 1
7 2 */

#include <stdio.h>
#include <string.h>


void print_digit(char s[])
{	
	int SIZEa=strlen(s);
//	printf("%d\n",SIZEa);
	int i=0;
	int j=0;
	int count[10]={};
	for(i=0;i<SIZEa;i++)
		{
//			printf("%d\n",a[i]);
			for (j=0;j<10;j++)
			{
				if ((s[i]-'0')==j)
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
	char a[1001],temp;
	int i=0;
	temp=getchar();
	a[i]=temp;
	while (temp!='\n')
	{
		i++;
		temp=getchar();
		a[i]=temp;
	}
	print_digit(a);
	
	return 0;
}

