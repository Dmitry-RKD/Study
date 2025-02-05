/*
 * D12.c
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


int simpl_number(int n) // Функция для проверки, является ли число простым
{
    if (n <= 1)
		return 0;
    for (int i = 2; i<= n/2; i++)
    {
        if (n % i == 0) 
			return 0;
    }
    return 1;
}

void D13(int n, int i)
{
    if (n <= 1) 
		return;
//    if (simpl_number(i) && n % i == 0)
	if (n%i==0)
	{
		if (simpl_number(i)==1)
		{
			printf("%d ", i);
			D13(n/i,i);
        }
	}
		else 
			D13(n, i + 1);     
}

int main(int argc, char **argv)
{
	int a,b=2;
	scanf("%d",&a);
	D13(a,b);	
	return 0;
}

