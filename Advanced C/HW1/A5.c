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
 * На вход программе подается беззнаковое 32-битное целое число N. Требуется найти количество единичных битов в двоичном представлении данного числа.

Примеры
 * 
 */


#include <stdio.h>
#include <inttypes.h>

int main()
{
    uint32_t N;
    int count=0;
    int mask=1;
    scanf("%u",&N);
    for(int i=0;i<32;i++)
    {
		if (N & mask)
			count++;
		N=N>>1;
	}
    printf("%d\n", count);
    return 0;
}

