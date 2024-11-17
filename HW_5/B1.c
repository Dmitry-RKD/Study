/*
 * B1.c
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
#include <inttypes.h>
#include <math.h>

int main(int argc, char **argv)
{
    uint32_t a_print,dabl=0,cube=0;
/    printf ("Введите число от 1 до 100\n");
    scanf ("%d", &a_print);
    if ((a_print>=1)&&(a_print<=100))
    {
    for (int i=1;i<=a_print;++i)
        {
         dabl=pow(i,2);
         cube=pow(i,3);
         printf ("%d %d %d\n", i,dabl,cube);
        }
    return 0;
    }
    else
    {
    printf ("Веденное число вне допустимого диапазона\n");
    return 1;
    }

}


