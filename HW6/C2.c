/*
 * C2.c
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
int power (int a,int b)
{
  int k=a;
  if (b==0)
    return a=1;
  for (int i=2;i<=b;i++)
    {
        a*=k;
    }
  return a;
}

int main(int argc, char **argv)
{
    int a1,a2;
    scanf ("%d %d",&a1,&a2);
    printf ("%d",power(a1,a2));

    return 0;
}

