/*
 * C20.c
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

void C20(char c)
{
    int count_1=0,count_2=0;
    int stop=0;
    while (c && c!='.' && stop==0)
    {
//  printf("%c",c);
    if (c=='(')
        count_1++;
    else if (c==')')
        count_2++;
    if (count_2>count_1)
        stop=1;
    c=getchar();
    }
//  printf("%d,%d",count_1,count_2);
    if (count_2>count_1)
        printf("NO\n");
    else if (count_1==count_2)
        printf("YES\n");
    else
        printf("NO\n");
}

int main(int argc, char **argv)
{
    char c;
    c=getchar();
    C20(c);
    return 0;
}

