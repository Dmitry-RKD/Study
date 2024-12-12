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
/* Равносторонние треугольники
Cia очень любит равносторонние треугольники. Он все время выкладывает их из камней. Ling дал Cia камни и попросил его составить такой треугольник если это возможно. Помогите Cia сложить треугольник используя все камни или напечатайте слов NO, если это невозможно. Пример треугольников, которые составляет Cia:
 *
* *

  *
 * *
* * *

   *
  * *
 * * *
* * * *
Во входном файле input.txt записано некоторое количество символов * (камней). Необходимо построить равносторонний треугольник используя все символы * и символ пробел, записать ответ в выходной файл output.txt. Между соседними символами * строго один пробел. Если треугольник невозможно составить, используя все камни, то необходимо записать единственное слово NO в файл output.txt.
Формат входных данных
Текстовый файл состоит из различных символов и символов *.
Формат результата
Равносторонний треугольник составленный из символов *, символов пробела и символов переноса строк или слово NO.
Примеры
Входные данные в файле input.txt
***
Результат работы в файле output.txt
 *
* **/

#include <stdio.h>
# define STRING_SIZE 1001

void palindrome (FILE *f, FILE *p, char *a)
{
	signed char c;
	c=getc(f);
	int i=0;
	while (c!=EOF)
	{
		if (c=='*')
			a[i++]=c;	
		c=getc(f);
	}
	int flag=0;
	int temp=3;
	int count=0;
	if(i==temp)
	{
		flag=1;
		count=1;
	}
	if(flag==0)
	{
		count=2;
		for (int j=3;j<100;j++)
		{
			temp+=j;
			if(i==temp)
			{
				flag=1;
				break ;
			}
			count++;
		}
	}
	printf("%d",count);
	printf("%d",flag);
	if (flag==0)
	{
		fprintf(p,"NO");
		return;
	}
	int j=1;
	int k=0;
	int l=0;
	for(j=1;j<=i;j++)
	{
		while(l<count)
		{
			fprintf(p," ");
			l++;
		}
		count-=1;
		l=0;
		while (k<j)
		{
			fprintf(p,"* ");
			k++;
		}
		i=i-k;
		k=0;
		fprintf(p,"\n");
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

