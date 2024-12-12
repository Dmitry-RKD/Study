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
/* Пары соседних символов
В файле input.txt записаны символы. Необходимо разработать функцию, которая меняет местами пары соседних символов не обращая внимание на символы пробел. Если количество символов нечетно (пробелы не считаем), то последний символ не меняем. Результат записать в файл output.txt.
Формат входных данных
Строка из английских букв, пробелов и знаков препинания. Не более 1000 символов.
Формат результата
Строка из английских букв, пробелов и знаков препинания. */

#include <stdio.h>
# define STRING_SIZE 1001

void swap_simvol(FILE *f, FILE *p, char *a)
{
	int i=0;
	int temp=0;
	int count=0;
	int ind=0;
	signed char c;
	c=getc(f);
	while (c!=EOF && c!='\n')
	{
		a[i]=c;
		if ((c>='a' && c<='z') || (c>='A' && c<='Z'))
		{
			if (count==0)
			{
				ind=i;	
				temp=c;
				count++;
			}
		
			else 
			{
				a[ind]=c;
				a[i]=temp;
				count=0;				
			}
		}
		i++;
		c=getc(f);
	}
	fprintf(p,"%s",a);
}


int main(int argc, char **argv)
{
	char str[STRING_SIZE]={0};
	FILE *f,*p;
	f=fopen("input.txt","r");
	p=fopen("output.txt","w");
	swap_simvol(f,p,str);
	fclose(f);
	fclose(p);
	return 0;
}

