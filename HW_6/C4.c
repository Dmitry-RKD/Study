/*
 * C4.c
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
int C4(int a)
{
    int b;
    if (a<2 && a>=-2)
    {
        b=a*a;
    return b;
    }
    else if (a>=2)
    {
        b=a*a+(4*a)+5;
        return b;
    }
    else
    {
        b=4;
        return b;
    }
}

int max (int a, int b)
{
    if (a>b)
        return a;
    else
        return b;
}

int main(int argc, char **argv)
{
    int a_print,last=0,next=0,count=0;
    while (scanf("%d",&a_print) && a_print!=0)
    {
        next=C4(a_print);
        if (count==0)
        {
            last=next;
            count++;
        }
        else
            last=max(last,next);
    }
    printf("%d",last);
    return 0;
}

