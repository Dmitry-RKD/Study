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
/* Проверка на палиндром
В файле input.txt символьная строка не более 1000 символов. Необходимо проверить, является ли она палиндромом (палиндром читается одинаково в обоих направлениях). Реализовать логическую функцию is_palindrom(str) и записать ответ в файл output.txt.
Формат входных данных
Строка из заглавных английских букв
Формат результата
YES или NO
Примеры
Входные данные в файле input.txt
ABCDEF
Результат работы в файле output.txt
NO
Входные данные в файле input.txt
KAZAK
Результат работы в файле output.txt
YES */

#include <stdio.h>
# define STRING_SIZE 1001

int read_string(char *a, int n,FILE *f)
{
	int i=0;
	signed char c;
	c=getc(f);
	while (c!=EOF && c!='\n')
	{
		a[i++]=c;
		c=getc(f);
	}
	return i;

}

void palindrome (FILE *f, char *a, int n)
{
	int flag=0;
	for (int i=0;i<=n;i++)
	{
		if (a[i]!=a[--n])
			flag=1;
	}
	if (flag==0)
		fprintf(f,"YES");
	else
		fprintf(f,"NO");
}

int main(int argc, char **argv)
{
	char str[STRING_SIZE]={0};
	FILE *f;
	f=fopen("input.txt","r");
	int count=0;
	count=read_string(str,STRING_SIZE,f);
	fclose(f);
	f=fopen("output.txt","w");
	palindrome (f,str,count);
	fclose(f);	
	return 0;
}

