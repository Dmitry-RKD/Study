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
/* Строка и цифры
Считать число N из файла input.txt. Сформировать строку из N символов. N четное число, не превосходящее 26. На четных позициях должны находится четные цифры в порядке возрастания, кроме 0, на нечетных позициях - заглавные буквы в порядке следования в английском алфавите. Результат записать в файл output.txt
Формат входных данных
Четное N ≤ 26
Формат результата
Строка из английских букв и цифр
Примеры
Входные данные в файле input.txt
10
Результат работы в файле output.txt
A2B4C6D8E2
Входные данные в файле input.txt
16
Результат работы в файле output.txt
A2B4C6D8E2F4G6H8 */

#include <stdio.h>

int main(void)
{
	FILE *f;
	int count=0;
	f = fopen("input.txt", "r"); 
	fscanf(f,"%d",&count);
	fclose(f);
	f=fopen("output.txt", "w");
	int temp=2;
	char a=65;
	for (int i=1;i<=count;i++)
	{

		if(i%2==0)
		{
			fprintf(f,"%d",temp);
			temp+=2;
			if (temp>8)
				temp=2;
		}
		else
			fprintf(f,"%c",a++);
	}
	fclose(f);
	return 0;
	
}

