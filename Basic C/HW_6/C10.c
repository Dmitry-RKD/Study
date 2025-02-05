/*
 * C10.c
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

int simple(int a) // Функция проверяющая является число простым
{
    int div=0;
    if (a<0)
        a=-a;
    if (a==1 || a==0)
        return -1;
    else if (a==2)
        return 1;
    else
    for (int i=2;i<a;i++)
    {
        div=a%i;
        if(div==0)
        {
            return -1;
        }
    }
    if (div!=0)
        return 1;
}

void pr_simpl(int a) // Функция печати разлочение числа на множество простых чисел
{
    int div=0;
    int temp=2;
    int indicator=0;
//  int stop=a/2;
    while (temp<=a)
    {
        div=a%temp;
        indicator=simple(temp);
//      printf("%d",indicator);
        if (div==0 && indicator==1)
        {
            printf("%d ",temp);
            a=a/temp;
            temp=2;
        }
        else
            temp++;
    }
}

int main(int argc, char **argv)
{
    int a;
    scanf("%d",&a);
    pr_simpl(a);

    return 0;
}

