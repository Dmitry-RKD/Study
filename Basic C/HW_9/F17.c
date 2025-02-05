/*
 * F17.c
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
#define SIZE 5


void inputmatrix(int a[][5], int size)
{
	for (int i = 0; i<size; i++)
		for (int j = 0; j<size; j++)
			scanf("%d", &a[i][j]);
   
}

void trace_matrix(int a[][5], int size)
{
	int i=0;
	int sum=0;
	for (i=0;i<size;i++)
	{
		sum=sum+a[i][i];
	}
	printf("%d\n",sum);
}

int main(void)
{
	int a[SIZE][SIZE];
	inputmatrix(a,SIZE);
	trace_matrix(a,SIZE);
	return 0;
}


