/*
 * B20.c
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

void simple(int a)
{
    int div=0;
    if (a<0)
        a=-a;
    if (a==1)
        printf("NO\n");
    else if (a==2)
        printf("YES\n");
    else
    for (int i=2;i<a;i++)
    {
        div=a%i;
        if(div==0)
        {
            printf("NO\n");
            break ;
        }
    }
    if (div!=0)
        printf("YES\n");
}

int main(int argc, char **argv)
{
    int print=0;
    scanf("%d",&print);
    simple(print);

    return 0;
}

