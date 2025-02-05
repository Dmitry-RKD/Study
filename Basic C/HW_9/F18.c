/*
 * F18.c
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


#include <stdio.h>
#define SIZE 10


void inputmatrix(int a[][10], int size)
{
	for (int i = 0; i<size; i++)
		for (int j = 0; j<size; j++)
			scanf("%d", &a[i][j]);
   
}

void sum_max(int a[][10], int size)
{
	int i=0;
	int sum=0;
	int max=0;
	for (int j=0;j<size;j++)
	{
		max=0;
		for (i=0;i<size;i++)
		{
			if (max<a[j][i])
				max=a[j][i];
			
		}
		sum=sum+max ;
	}
	
	printf("%d\n",sum);
}

int main(void)
{
	int a[SIZE][SIZE];
	inputmatrix(a,SIZE);
	sum_max(a,SIZE);
	return 0;
}

