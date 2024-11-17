/*
 * B16.c
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


#include <stdio.h>

int NOD(int a, int b)
{
    int a1;
    a1=a;
    int count=0;
    if (count==0 && a<b)
    {
        a=b;
        b=a1;
        count++;
    }

    while (b != 0)
    {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

int main(void)
{
    int a, b;
//    printf("Введите два неотрицательных целых числа:\n");
    scanf("%d %d", &a, &b);
    if (a < 0 || b < 0)
    {
//    printf("Введены отрицательные числа.\n");
        return 1;
    }
    if (a == 0 && b == 0)
        return 1;
    int result=0;
    result=NOD(a,b);
    printf("%d", result);
    return 0;
}

