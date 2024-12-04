/*
 * F16.c
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
#define SIZE 2
// 'A'=65, '0'=48
void cheasboard(char *s,int size)
{
	if (s[0]>=65 && s[0]<=72 && s[1]>=48 && s[1]<=56)
	{
		if(s[0]%2==1 && s[1]%2==1)
			printf("BLACK\n");
		else if(s[0]%2==1 && s[1]%2==0)
			printf("WHITE\n");
		else if (s[0]%2==0 && s[1]%2==0)
			printf("BLACK\n");
		else
			printf("WHITE\n");
	}
	
	else 
		printf("The entered line is not a chessboard\n");
	
}

int main(int argc, char **argv)
{
	char s[SIZE];
	scanf("%s",s);
//	printf("%s\n",s);
	cheasboard(s,SIZE);
	return 0;
}

