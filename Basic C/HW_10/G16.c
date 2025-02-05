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
/* Ling заменить на Cao
В файле input.txt дано предложение. Необходимо заменить все имена «Ling» на «Cao» и результат записать в файл output.txt.
Формат входных данных
Строка из английских букв, пробелов и знаков препинания. Не более 1000 символов.
Формат результата
Строка из английских букв, пробелов и знаков препинания.
Примеры
Входные данные в файле input.txt
Ling, Ling, Ling and Ling!!!
Результат работы в файле output.txt
Cao, Cao, Cao and Cao!!! */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
# define STRING_SIZE 1001 

void replaceWord(FILE *p, FILE *f, char *a)
{
	signed char c=0;
	c=getc(f);
	int i=0;
	while (c!=EOF && c!='\n')
	{
		a[i++]=c;
		c=getc(f);
	}
	char *pos=a ;
	printf("%s\n",a);
	while ((pos = strstr(pos, "Ling")) != NULL)
	{	
		int index=pos-&a[0];
		for (int j=index+3;j<=i;j++)
		{
			a[j]=a[j+1];
		}
		i--;
		memcpy(pos, "Cao", 3);
		pos += 4;
	}
	printf("%s\n",a);
	fprintf(p,"%s",a);
}

int main(int argc, char **argv)
{
	char str[STRING_SIZE]={0};
	FILE *f,*p;
	f=fopen("input.txt","r");
	p=fopen("output.txt","w");
	replaceWord(p,f,str);
	fclose(f);
	fclose(p);
	return 0;
}
  

