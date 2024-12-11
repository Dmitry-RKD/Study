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
/* Разобрать на слова
В файле input.txt дано предложение требуется разобрать его на отдельные слова. Напечатать каждое слово на отдельной строке в файл output.txt.
Формат входных данных
Одна строка из английских букв и пробелов не более 1000 символов.
Формат результата
Каждое слово на отдельной строке
Примеры
Входные данные в файле input.txt
Mama mila ramu
Результат работы в файле output.txt
Mama
mila
ramu */

#include <stdio.h>
# define STRING_SIZE 1001

void Split_into_words(FILE *f, FILE *p)
{
	int flag=0;
	signed char c=0;
	c=getc(f);
	while (c!=EOF && c!='\n')
	{
		if ((c>='a' && c<='z') || (c>='A' && c<='Z'))
		{
			fprintf(p,"%c",c);
			flag=1;
		}	
		else if (c==' ' && flag==1)
		{
			fprintf(p,"\n");
			flag=0;
		}
		c=getc(f);
	}
}
	
int main(int argc, char **argv)
{
	FILE *f,*p;
	f=fopen("input.txt","r");
	p=fopen("output.txt","w");
	Split_into_words(f,p);
	fclose(f);
	fclose(p);
	return 0;
}

