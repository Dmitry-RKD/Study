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
/* Самое длинное слово
В файле input.txt дана строка слов, разделенных пробелами. Найти самое длинное слово и вывести его в файл output.txt. Случай, когда самых длинных слов может быть несколько, не обрабатывать.
Формат входных данных
Строка из английских букв и пробелов. Не более 1000 символов.
Формат результата
Одно слово из английских букв.
Примеры
Входные данные в файле input.txt
Hello beautiful world
Результат работы в файле output.txt
beautiful */

#include <stdio.h>
# define STRING_SIZE 1001

void long_word_print(char *a, FILE *f)
{
	int long_count=0; // исп для подсчета длинны слова
	int N[250]={0};// массив хранит длинну считанных слов
	signed char c=0;
	c=getc(f);
	int i=0; // колличество считаных слов из input.txt
	int j=0; 
	while (c!=EOF && c!='\n')
	{
		if ((c>='a' && c<='z') || (c>='A' && c<='Z'))
		{
			long_count++;
			a[j++]=c;
		}	
		else if (c==' ')
		{
			N[i++]=long_count;
			long_count=0;
		}
		c=getc(f);
		//if (c==EOF || c==EOF)
			//N[i++]=long_count;
	}
	N[i++]=long_count;
	//printf("%s\n",a);
	//printf("%d,%d,%d,%d",N[0],N[1],N[2],i);
	fclose(f);
	f=fopen("output.txt","w");
	int k=0;
	int count=0;
	int temp=0;
	int max=0;
	int flag=0;
	while (k<i)
	{
		count=0;
		temp=N[k];
		for (int m=0;m<i;m++) // проверка 
		{
			if (temp<=N[m])
			{
				count++;
				max=k;
			}
		}
		if (count==1)
		{
			flag=1;
			break;
		}
		else
		k++;
	}
	if (flag==1)
	{
		int sum=0;
		for(int m=0;m<max;m++)
			sum=sum+N[m];
		for (int m=0;m<N[max];m++)
		{
			fprintf(f,"%c",a[sum+m]);
		}	
	}
}


int main(int argc, char **argv)
{
	char str[STRING_SIZE]={0};
	FILE *f;
	f=fopen("input.txt","r");
	long_word_print(str,f);
	f=fopen("output.txt","w");
	
	return 0;
}

