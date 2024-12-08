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
/* Сдать решение задачи G9-Удалить повторяющиеся символы
Имя входного файла:	input.txt
Имя выходного файла:	output.txt
Ограничение времени:	1 с
Ограничение реального времени:	5 с
Ограничение памяти:	64M
Удалить повторяющиеся символы
В файле input.txt строка из меленьких и больших английских букв, знаков препинания и пробелов. Требуется удалить из нее повторяющиеся символы и все пробелы. Результат записать в файл output.txt.
Формат входных данных
Строка из меленьких и больших английских букв, знаков препинания и пробелов. Размер строки не более 1000 сивмолов.
Формат результата
Строка из меленьких и больших английских букв.
Примеры
Входные данные в файле input.txt
abc cde def
Результат работы в файле output.txt
abcdef */

#include <stdio.h>
# define STRING_SIZE 1001


int main(int argc, char **argv)
{
	char str[STRING_SIZE]={0};
	signed char c;
	FILE *f;
	f=fopen("input.txt","r");
	c=getc(f);
	int i=0;
	int count=0;
	while (c!=EOF && c!='\n')
	{
		if((c>='a' && c<='z') || (c>='A' && c<='Z'))
		{
			for (int j=0;j<i;j++)
			{
				if (c==str[j])
					count++;
			}
			if (count==0)
			{
				str[i++]=c;
			}
			count=0;
		}
		c=getc(f);
	}
	fclose(f);
	f=fopen("output.txt","w");
	for(int j=0;j<i;j++)
		fprintf(f,"%c",str[j]);
	return 0;
}

