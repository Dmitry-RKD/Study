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
/* Hello name
В файле input.txt в одной строке фамилию, имя и отчество. Сформировать файл приветствие output.txt, где останутся имя и фамилия
Формат входных данных
Строка состоящая из английских букв и пробелов не более 100 символов. Формат: Фамилия Имя Отчество
Формат результата
Строка состоящая из английских букв и пробелов
Примеры
Входные данные в файле input.txt
Pupkin Vasiliy Ivanovich
Результат работы в файле output.txt
Hello, Vasiliy Pupkin! */

#include <stdio.h>
# define STRING_SIZE 101

void G14(FILE *f, FILE *p, unsigned char *str)
{
	signed char c=0;
	c=getc(f);
	int i=0;
	int index_i=0;
	int index_f=0;
	int count=0;
	while (c!=EOF && c!='\n')
	{
		if ((c>='a' && c<='z') || (c>='A' && c<='Z'))
		{	
			str[i++]=c;
			count=0;
		}
		if (c==' ')
			count++;
		if (count==1)
			str[i++]=c;
		c=getc(f);	
	}
	fprintf(p,"Hello,");
	count=0;
	for(int j=0;j<i;j++)
	{
		if (str[j]==' ' && count==0)
		{
			index_f=j;
			count++;
		}
		if (str[j]==' ' && count==1)
			index_i=j;
	}
	for (int j=index_f;j<=index_i;j++)
		fprintf(p,"%c",str[j]);
	for (int j=0;j<index_f;j++)
		fprintf(p,"%c",str[j]);	
	
	fprintf(p,"!");
}
	
int main(int argc, char **argv)
{
	unsigned char str[STRING_SIZE]={0};
	FILE *f,*p;
	f=fopen("input.txt","r");
	p=fopen("output.txt","w");
	G14(f,p,str);
	fclose(f);
	fclose(p);
	return 0;
}

