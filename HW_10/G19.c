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
/* Составить палиндром
Разработать функцию дана строка из маленьких английских букв. Составить из символов палиндром максимальной длинны. При составлении палиндрома буквы в палиндроме должны быть расположены в лексикографическом порядке. Записать ответ в файл output.txt.
Формат входных данных
Строка из маленьких английских букв. Не более 1000 символов.
Формат результата
Строка из маленьких английских букв. */

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
	printf("%d",long_p);
	temp=96;
	while (temp<123)
	{
		temp++;
		count=0;
		for(int j=0;j<i;j++)
		{
			if (temp==a[j])
				count++;	
			if (count==2)
			{
				fprintf(p,"%c",temp);
				count=0;
			}		
		}
	}
	fprintf(p,"%c",word);
	temp=123;
	while (temp>95)
	{
		temp--;
		count=0;
		for(int j=0;j<i;j++)
		{
			if (temp==a[j])
				count++;	
			if (count==2)
			{
				fprintf(p,"%c",temp);
				count=0;
			}		
		}
	}
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

