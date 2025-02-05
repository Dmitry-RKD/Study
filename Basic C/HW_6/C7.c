/*
 * C7.c
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

int convertor(int a,int p)
{
    if (a == 0)
        return 0;
    else if (p>=2 && p<=9)
    {
        int digit=1;
        int number=0,last=0;
        while (a)
        {
            last=a%p;
            number=number+last*digit;
//            printf("%d\n",number);
            digit*=10;
            a=a/p;
        }
    return number;
    }
    else
    {
        printf("Выбранная система счисления не поддерживается этой программой\n");
        return 1;
    }
}

int main(int argc, char **argv)
{
    int a,p;
    scanf("%d %d", &a,&p);
    printf("%d\n", convertor(a,p));
    return 0;
}

