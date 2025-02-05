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
/* Заменить a на b
В файле input.txt дана символьная строка не более 1000 символов. Необходимо заменить все буквы "а" на буквы "b" и наоборот, как заглавные, так и строчные. Результат записать в output.txt.
Формат входных данных
Строка из маленьких и больших английских букв, знаков препинания и пробелов.
Формат результата
Строка из маленьких и больших английских букв, знаков препинания и пробелов.
Примеры
Входные данные в файле input.txt
aabbccddABCD
Результат работы в файле output.txt
bbaaccddBACD */

#include <stdio.h>
# define STRING_SIZE 1001

void Convert_a_b(char *a,int n, FILE *f)
{
	for (int i=0;i<n;i++)
	{
		if (a[i]=='a' || a[i]=='A')
			fprintf(f,"%c",(a[i]+1));
		else if (a[i]=='b' || a[i]=='B')
			fprintf(f,"%c",(a[i]-1));
		else 
			fprintf(f,"%c",a[i]);
	}
}


int main(int argc, char **argv)
{
	char str[STRING_SIZE]={0};
	FILE *f;
	f=fopen("input.txt","r");
	signed char c;
	c=fgetc(f);
	int count=0;
	while (c!=EOF && c!='\n')
	{
		str[count++]=c;
		c=fgetc(f);
	}
	fclose(f);
	f=fopen("output.txt","w");
	Convert_a_b(str,count,f);
	fclose(f);
	return 0;
}

