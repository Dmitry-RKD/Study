/*
 * B17.c
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
    int a=0;
//    printf ("Введите 1 положительное число от 10\n");
    scanf ("%d",&a);
    for (int i=10;i<=a;i++)
    {
        int sum=0;
        int comp=1;
        int div=0;
        int var=i;
        while (var!=0)
        {
            div=var%10;
            var=var/10;
            sum=sum+div;
            comp=comp*div;
        }
 //       printf("%d %d\n", sum,comp);
        if (comp==sum)
            printf("%d ",i);
    }
    return 0;
}

