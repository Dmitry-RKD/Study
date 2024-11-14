/*
 * A7.c
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
    int a,b,c ;
    scanf ("%d %d %d", &a, &b, &c);
        if (a>b&&a>c)
         printf("%d", a);
                else if (a>b&&a<c)
                printf("%d",  c);
                   if (b>a&&b>c)
                   printf("%d",  b);
                      else if (b>a&&b<c)
                      printf("%d",  c);
                      else if (a==b&&b==c)
                      printf("%d",  c);
    return 0;
}

