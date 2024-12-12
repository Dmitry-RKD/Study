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
Считать предложение из файла input.txt и определить можно ли из английских букв предложения записанного в файле получить одно слово - палиндром. Ответ напечатать на стандартный поток вывода. Требуется реализовать логическую функцию и применить ее.
is_palindrom(string)
Формат входных данных
Строка из маленьких английских букв и пробелов. Не более 1000 символов.
Формат результата
YES или NO*/

#include <stdio.h>
# define STRING_SIZE 1001

void palindrome (FILE *f, FILE *p, char *a)
{
	signed char c;
	c=getc(f);
	int i=0;
	while (c!=EOF && c!='\n')
	{
		if ((c>='a' && c<='z') || (c>='A' && c<='Z'))
			a[i++]=c;	
		c=getc(f);
	}
	int long_p=0;
	int count=0;
	int temp=96;
	char word='z';
	while (temp<123)
	{
	// a=97 z=122
		temp++;
		count=0;
		for(int j=0;j<i;j++)
		{
			if (temp==a[j])
				count++;			
		}
		if(count%2==1 && temp<word)
			word=temp;
		count=count/2;
		long_p+=count;
	}
	long_p*=2;
	i=i-long_p;
	if (long_p>0 && (i==0 || i==1))
		printf("YES\n");
	else
		printf("NO\n");
}

int main(int argc, char **argv)
{
	char str[STRING_SIZE]={0};
	FILE *f,*p;
	f=fopen("input.txt","r");
	p=fopen("output.txt","w");
	palindrome(f,p,str);
	fclose(f);
	fclose(p);
	return 0;
}

