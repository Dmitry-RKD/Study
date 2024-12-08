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
/* дать решение задачи G7-Количество букв
Имя входного файла:	input.txt
Имя выходного файла:	output.txt
Ограничение времени:	1 с
Ограничение реального времени:	5 с
Ограничение памяти:	64M
Количество букв
В файле input.txt считать символьную строку, не более 10 000 символов. Посчитать количество строчных (маленьких) и прописных (больших) букв в введенной строке. Учитывать только английские буквы. Результат записать в файл output.txt.
Формат входных данных
Строка состоящая из английских букв, цифр, пробелов и знаков препинания.
Формат результата
Два целых числа. Количество строчных букв и количество заглавных букв.
Примеры
Входные данные в файле input.txt
aabbAB
Результат работы в файле output.txt
4 2
Входные данные в файле input.txt
HELLO WORLD
Результат работы в файле output.txt
0 10 */

#include <stdio.h>
# define SIZE 10



int main(int argc, char **argv)
{
	FILE *f;
	signed char c;
	int count_a=0;
	int count_A=0;
	f=fopen("input.txt","r");
	c=getc(f);
	while (c!=EOF)
	{
		if (c>='a' && c<='z')
			count_a++;
		else if (c>='A' && c<='Z')
			count_A++;
		c=getc(f);
	}
	fclose(f);
	f=fopen("output.txt","w");
	fprintf(f,"%d %d",count_a, count_A);
	return 0;
}

