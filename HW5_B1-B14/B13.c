/*
 * B13.c
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

int main(int argc, char **argv)
{
    int a_print,count_even=0,count_odd=0,div=0;
    scanf ("%d",&a_print);
    if (a_print==0)
    {
        printf ("%d %d",1,0);
        return 0;
    }
    while (a_print!=0)
    {
        div=a_print%10;
        a_print=a_print/10;
        if ((div==0)||(div==2)||(div==4)||(div==6)||(div==8))
        {
            count_even++ ;
        }
        else
        {
            count_odd++ ;
        }
    }
    printf ("%d %d",count_even,count_odd);
    return 0;
}

