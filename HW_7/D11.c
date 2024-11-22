/*
 * D11.c
 * 
 * Copyright 2024 Дмитрий <Дмитрий@DESKTOP-V4T7I45>
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


#include <stdio.h>
int sum_binar_1(int a,int count)
{
	if (a)
	{	
		if (a%2==1)
			count++;
		sum_binar_1(a/2,count);
//		printf("%d",a%2); вывод числа в 2-ом коде.
		return count;
	}
	printf("%d\n",count); // печать число 1 в двоичном коде
	return 0;
}

int main(int argc, char **argv)
{
	int a,count=0;
	scanf("%d",&a);
	count+=sum_binar_1(a,count);
	return 0;
}

