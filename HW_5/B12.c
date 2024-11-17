/*
 * B12.c
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
int max(int a, int b)
{
    if (a>b)
        return a;
    return b;
}
int min(int a, int b)
{
    if (a<b)
        return a;
    return b;
}


#include <stdio.h>

int main(int argc, char **argv)
{
    int a_print,k[9]={0},max1=0,min1=9;
    scanf ("%d",&a_print);
    if (a_print==0)
    {
        printf ("%d %d",0,0);
        return 0;
    }
    for (int i=0;a_print!=0;i++)
    {
        k[i]=a_print%10;
        a_print=a_print/10;
        max1=max(max1,k[i]);
        min1=min(min1,k[i]);
    }
    printf("%d %d",min1,max1);
    return 0;
}

