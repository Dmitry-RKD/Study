/*
 * C14.c
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

void C14(int a)
{
    if (a>=0)
    {
        int sum=0;
        int b=0;
        while (a!=0)
        {
            b=a%10;
            sum+=b;
            a=a/10;
        }
        sum=sum%2;
        if (sum==0)
            printf("YES\n");
        else
            printf("NO\n");
    }
    else
        printf("Введенно не корректное число");
}

int main(int argc, char **argv)
{
    int a;
    scanf("%d",&a);
    C14(a);
    return 0;
}

