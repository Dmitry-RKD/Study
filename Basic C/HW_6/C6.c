/*
 * C6.c
 *
 * Copyright 2024 Дмитрий <Дмитрий@DESKTOP-JEV1I8E>
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
unsigned long long C6(int a)
{
    if (a>1 && a<65)
    {
        unsigned long long an=1;
        for (int count=1;count<a;count++)
        {
            an*=2;
        }
        return an;
    }
    else
        return 1;
}


#include <stdio.h>

int main(void)
{
    int a=0;
//    printf("Введите номер клетки от 1 до 64: ");
    scanf("%d",&a);
    printf("%llu",C6(a));
    return 0;
}

