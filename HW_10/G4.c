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
/* По одному разу
В файле input.txt даны два слова не более 100 символов каждое, разделенные одним пробелом. Найдите только те символы слов, которые встречаются в обоих словах только один раз. Напечатайте их через пробел в файл output.txt в лексикографическом порядке.
Формат входных данных
Два слова из маленьких английских букв через пробел. Длинна каждого слова не больше 100 символов.
Формат результата
Маленькие английские буквы через пробел.
Примеры
Входные данные в файле input.txt
hello world
Результат работы в файле output.txt
o
Входные данные в файле input.txt
aabcd bcef
Результат работы в файле output.txt
b c */

#include <stdio.h>
# define STRING_SIZE 205



int main(int argc, char **argv)
{
	char str[STRING_SIZE]={0};
	int count_world_1=0;
	int count_world_2=0;
	FILE *f;
	f=fopen("input.txt", "r");
	signed char c;
	c=fgetc(f);
	int flag=0;
	while (c!=EOF && c!='\n') 
	{
		if(flag==0)
		{
			if(c!=' ')
			{
			str[count_world_1++]=c;
			c=fgetc(f);
			}
			if (c==' ')
			{
				flag=1;
				count_world_2=count_world_1;
				c=fgetc(f);
			}
		}
		else
		{
			str[count_world_2++]=c;
			c=fgetc(f);
		}
	}
	fclose(f);
	f=fopen("output.txt", "w");
	int i=0;
	char temp=0;
	int count=0;
	while (i<count_world_1)
	{
		temp=str[i];
		for (int j=0;j<count_world_1;j++)
		{
			if (temp==str[j])
				count++;
		}
		if (count==1)	
		{	
			for (int j=count_world_1;j<count_world_2;j++)
			{
				if (temp==str[j])
					count++;
			}
			if (count==2)
				fprintf(f,"%c ",str[i]);
		}
		count=0;
		i++;
	}
	fclose(f);
	return 0;
}

