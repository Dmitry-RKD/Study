/*
 * max_for_5numbers.c
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

int max (int a,int b)
{ return a>=b?a:b;
        }

int main(int argc, char **argv)
{
    int a,a1,a2,a3,max1;
    scanf ("%d", &a);
    a1=a/100;
    a2=(a/10)%10;
    a3=a%10;


   max1=max(a1,a2);
   max1=max(max1,a3);
   printf("%d", max1);

    return 0;
}

