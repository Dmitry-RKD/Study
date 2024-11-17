/*
 * C17.c
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
int happy_C17(int a)
{
    int sum=0;
    int comp=1;
    int last=a%10;
    sum+=last;
    comp*=last;
    a=a/10;
    while(a!=0)
    {
        last=a%10;
        sum+=last;
        comp*=last;
        a=a/10;
    }
//  printf("comp= %d sum= %d\n",comp,sum);
    if (sum==comp)
        return printf("YES\n");
    else
        return printf("NO\n");
}

int main(int argc, char **argv)
{
    int a;
    scanf("%d",&a);
    happy_C17(a);

    return 0;
}

