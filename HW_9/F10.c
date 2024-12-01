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
/* Упаковать строку
Дана строка состоящая из маленьких латинских букв 'a'..'z'. В конце строки точка. Необходимо заменить повторяющиеся буквы на <буква><количество повторений>
Формат входных данных
Входная строка состоящая из букв 'a'-'z' не превышающая 1000 символов. В конце строки символ '.'
Формат результата
Результат состоящий из букв и чисел, без пробелов */

#include <stdio.h>

void pack_a_string(char *s,int N)
{
	int i=0;
	int count=0;
	char temp;
	while (i<N)
	{
		temp=s[i];
		count=0;
		for(int j=i;j<N;j++)
		{
			if (s[i]==s[j])
				count++;
			else 
				break ;
		}
		i+=count;
		printf("%c%d",temp,count);
	}
}

int main(int argc, char **argv)
{
	char str[1001];
	char temp=getchar();
	int i=0;
	while (temp!='.')
	{
		str[i++]=temp;
		temp=getchar();
		
	}
//	printf("%s %d\n",str,i);
	pack_a_string(str,i);
	return 0;
}

