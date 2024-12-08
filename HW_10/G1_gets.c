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
/* Три раза
В файле input.txt дана строка. Вывести ее в файл output.txt три раза через запятую и показать количество символов в ней.
Формат входных данных
Строка из английских букв и пробелов. Не более 100 символов. В конце могут быть незначащие переносы строк.
Формат результата
Исходная строка 3 раза подряд, через запятую пробел и количество символов в ней.
Примеры
Входные данные в файле input.txt
aab
Результат работы в файле output.txt
aab, aab, aab 3 */

#include <stdio.h>

//void printArr(char *a,int n)
//{
	//for(int i=0;i<=n;i++)
		//fprintf(f1,"%c",a[i]);
//}

int main(void)
{
	 FILE *f;
	 char str[101]={0};
	 signed char c;
	 int count=0;
	 f = fopen("input.txt", "r"); 
	 c=fgetc(f);
		while ( c!=EOF && c!='\n')
		{
			str[count]=c;
			count++;
			c=fgetc(f);
		}
	FILE *f1;
	f1=fopen("output.txt", "w"); 
	fprintf(f1,"%s, %s, %s %d",str,str,str,count);
	fclose(f);
	fclose(f1);
	return 0;
	
}

