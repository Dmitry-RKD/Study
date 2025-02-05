/*
 * B18.c
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

void fiban(int a)
{
    if (a==1)
        printf("%d",1);
    else if (a==0)
        printf("%d",0);
    else
    {
        int r_1=1,r_2=0;
        int sum=0;
        for (int b=1;b<=a;b++)
        {
            sum=r_1+r_2;
            r_1=r_2;
            r_2=sum;
            printf(" %d",sum);
        }
    }
}
int main(int argc, char **argv)
{
    int a_print;
    scanf("%d",&a_print);
    fiban(a_print);

    return 0;
}

