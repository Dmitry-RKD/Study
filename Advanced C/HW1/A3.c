/*
 * A0.c
 * 
 * Copyright 2025 Дмитрий <Дмитрий@DESKTOP-V4T7I45>
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
 * На вход программе подается беззнаковое 32-битное целое число N и натуральное число K (1 ≤ K ≤ 31). Требуется взять K младших битов числа N и вывести полученное таким образом число.

Примеры.
 * 
 */


#include <stdio.h>


int main()
{
    unsigned int N,K,mask;
    scanf("%u %u",&N,&K);
    if (K>=1 && K<=31)
    {
		mask=(1<<K)-1; 
		N&=mask;
	}
	else 
	{
		printf("Ошибка входных данных /n");
		return 1;
	}
	printf("%u\n",N);
    return 0;
}

