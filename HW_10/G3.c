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
/* Последний номер символа
В файле input.txt дана строка из 1000 символов. Показать номера символов, совпадающих с последним символом строки. Результат записать в файл output.txt
Формат входных данных
Строка не более 1000 символов
Формат результата
Целые числа через пробел - номера символа, который совпадает с последним символом строки.
Примеры
Входные данные в файле input.txt
aabbcdb
Результат работы в файле output.txt
2 3 */

#include <stdio.h>
# define STRING_SIZE 1001



int main(int argc, char **argv)
{
	char str[STRING_SIZE]={0};
	int count=0;
	FILE *f;
	f=fopen("input.txt", "r");
	signed char c;
	c=fgetc(f);
	while (c!=EOF && c!='\n')
	{
		str[count++]=c;
		c=fgetc(f);
	}
	fclose(f);
	f=fopen("output.txt", "w");
//	printf("%s",str);
//	printf("%d\n",count);
	for (int i=0;i<count-1;i++)
	{
		if (str[count-1]==str[i])
			fprintf(f,"%d ",i);		
	}
	fclose(f);
	return 0;
}

