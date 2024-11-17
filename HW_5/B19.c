/*
 * B19.c
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

void B19(int a)
{
    int dev=0;
    int sum=0;
    if (a<0)
        a=-a;
    else
    {
        int number=a;
        while (number!=0)
        {
            dev=number%10;
            sum=sum+dev;
            number=number/10;
        }
        if(sum==10)
            printf ("YES\n");
        else
            printf("NO\n");
    }
}

int main(void)
{
    int print;
    scanf("%d",&print);
    B19(print);
    return 0;
}

