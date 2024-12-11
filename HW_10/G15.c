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
/* Строка из английский букв, знаков препинания и пробелов. Не более 1000 символов.
Формат результата
Строка из английский букв, знаков препинания и пробелов.
Примеры
Входные данные в файле input.txt
Cao, Cao, Cao and Cao!!!
Результат работы в файле output.txt
Ling, Ling, Ling and Ling!!! */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
# define STRING_SIZE 1201 

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
//	printf("%s\n",a);
	while ((pos = strstr(pos, "Cao")) != NULL)
	{	
		int index=pos-&a[0];
		for (int j=i;j>=index;j--)
		{
			a[j+1]=a[j];
		}
		i++;
		memcpy(pos, "Ling", 4);
		pos += 4;
	}
//	printf("%s\n",a);
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
  

