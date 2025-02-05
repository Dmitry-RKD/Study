/*
 * D10.c
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

int is_prime(int n, int i)
{
	if (n<=1)
		return printf("NO\n");
	if (i==n)
		return printf("YES\n");
	if (n%i==0)
		return printf("NO\n");
	return is_prime(n,i+1);
}

int main(int argc, char **argv)
{
	int a,b=2;
	scanf("%d",&a);
	is_prime(a,b);
	return 0;
}

