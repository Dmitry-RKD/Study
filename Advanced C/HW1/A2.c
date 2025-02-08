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
 * Циклический сдвиг
На вход программе подается беззнаковое 32-битное целое число N и натуральное число K (1 ≤ K ≤ 31). 
Требуется циклически сдвинуть битычисла N вправо на K битов и вывести полученное таким образом число.
 */


#include <stdio.h>
#include <inttypes.h>

int main()
{
    uint32_t R_shift,Result,K;
    scanf("%u %u",&K,&R_shift);
    //printf("%u,%d\n",K,R_shift);
    Result=(K >> R_shift) | (K << (32 - R_shift));
	printf("%u\n", Result);
	
    return 0;
}
