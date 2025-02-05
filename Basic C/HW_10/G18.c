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
/* Удалить пробелы из текста
В файле input.txt необходимо удалить все лишние пробелы (в начале предложения и сдвоенные пробелы). Для решения задачи разработать функцию. Результат записать в output.txt.
Формат входных данных
Строка из английских букв, знаков препинания и пробелов. Не более 1000 символов.
Формат результата
Строка из английских букв, знаков препинания и пробелов.
Примеры
Входные данные в файле input.txt
    Hello     world!
Результат работы в файле output.txt
Hello world! */

#include <stdio.h>
# define STRING_SIZE 1001

void delete_space (FILE *f, FILE *p, char *a)
{
	signed char c;
	c=getc(f);
	int i=0;
	int flag=2;
	while (c!=EOF && c!='\n')
	{
		if (c!=' ')
		{
			flag=1;		
			a[i++]=c;	
		}
		c=getc(f);
		if (flag==1 && c==' ')
		{
			a[i++]=c;
			flag++;
		}
	}
	fprintf(p,"%s",a);
}

int main(int argc, char **argv)
{
	char str[STRING_SIZE]={0};
	FILE *f,*p;
	f=fopen("input.txt","r");
	p=fopen("output.txt","w");
	delete_space(f,p,str);
	fclose(f);
	fclose(p);
	return 0;
}

