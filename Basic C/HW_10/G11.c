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
/* В файле input.txt дано предложение. Необходимо определить, сколько слов заканчиваются на букву 'а'. Ответ записать в файл output.txt.
Формат входных данных
Строка из английских букв и пробелов не более 1000 символов.
Формат результата
Одно целое число
Примеры
Входные данные в файле input.txt
Mama mila ramu
Результат работы в файле output.txt  && (d==' '|| d=='\n')
2*/

#include <stdio.h>
# define STRING_SIZE 1001

int count_word(char *a,FILE *f)
{
	int count=0;
	signed char c;
	c=getc(f);
	
	while (c!=EOF)
	{
		m: ;
		if (c=='a')
		{
			c=getc(f);
			if (c==' '|| c=='\n' || c==EOF)
				count++;
			else if (c=='a')
				goto m;
		}
		c=getc(f);
	}
	printf("%d",count);
	return count;
}

int main(int argc, char **argv)
{
	char str[STRING_SIZE]={0};
	FILE *f;
	f=fopen("input.txt","r");
	int count=0;
	count=count_word(str,f);
	fclose(f);
	f=fopen("output.txt","w");
	fprintf(f,"%d",count);
	fclose(f);
	return 0;
}

