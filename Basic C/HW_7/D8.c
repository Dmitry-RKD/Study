/*
 * D8.c
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

void print_numb(int a,int b)
{
    if (a>b)
    {
        printf("%d ",a);
        if (a==b+1)
            printf("%d",b);
        print_numb(a-1,b);
    }
    if (a<b)
    {
        printf("%d ",a);
        if (a+1==b)
            printf("%d",b);
        print_numb(a+1,b);
    }
}
int main(int argc, char **argv)
{
    int a,b;
    scanf("%d %d",&a,&b);
    if (a==b)
    {
        printf("%d",a);
        return 0;
    }
    print_numb(a,b);
    return 0;
}

