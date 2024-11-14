/*
 * B6.c
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

int main(void)
{
    int input,div=0,last=0;
    scanf("%d",&input);
    div = input%10;
    input/=10;
    while (input!=0)
    {
    last=input%10;
    input=input/10;
    div=div-last;
        if (div==0)
        {
          printf("YES\n");
          input=0;
          return 0;
         }
        else
        div=last;
    }

    printf("NO\n");
    return 0;
}

