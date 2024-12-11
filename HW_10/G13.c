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
/* СИзменить расширение
В файле input.txt записан полный адрес файла (возможно, без расширения). Необходимо изменить его расширение на ".html" и записать результат в файл output.txt.
Формат входных данных
Строка состоящая из символов: a-z, A-Z, 0-9, /
Формат результата
Исходная строка с измененным расширением.
Примеры
Входные данные в файле input.txt
/DOC.TXT/qqq
Результат работы в файле output.txt
/DOC.TXT/qqq.html
Входные данные в файле input.txt
/DOC.TXT/qqq.com
Результат работы в файле output.txt
/DOC.TXT/qqq.html */

#include <stdio.h>
# define STRING_SIZE 1001

void G13(FILE *f, FILE *p, unsigned char *str)
{
	int count=0;
	signed char c=0;
	c=getc(f);
	int i=0;
	int indx=0;
	while (c!=EOF && c!='\n')
	{
		if (c=='/')
		{
			count++;
			indx=i;
		}
		str[i++]=c;
		c=getc(f);
	}
	if (count==0 || count==1)
	{
		for(int j=0;j<=i;j++)
		{
			if (str[j]=='.' || str[j]==0)
			{
				fprintf(p,".html");
				return ;
			}
			fprintf(p,"%c",str[j]);
		}
	}
	else 
	{
		for (int j=0;j<=i;j++)
		{
			if (( str[j]=='.' && j>indx) || j==i)
			{
				fprintf(p,".html");
				return ;
			}
			fprintf(p,"%c",str[j]);
		}	
	}
}
	
int main(int argc, char **argv)
{
	unsigned char str[STRING_SIZE]={0};
	FILE *f,*p;
	f=fopen("input.txt","r");
	p=fopen("output.txt","w");
	G13(f,p,str);
	fclose(f);
	fclose(p);
	return 0;
}

