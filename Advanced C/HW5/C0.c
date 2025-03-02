/*
 * C0.c
 * 
 * Copyright 2025 Дмитрий <Дмитрий@DESKTOP-V4T7I45>
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
#include <string.h>
#include <stdlib.h>

int main() {
    char n[255];
    scanf("%s", n);
    int len = strlen(n);
    int count = 0;
    int distinct[1000] = {0}; 

    for (int i = 0; i < len; i++) 
    {
        for (int j = i + 1; j < len; j++)
        {
            for (int k = j + 1; k < len; k++)
            {
                int num = (n[i] - '0') * 100 + (n[j] - '0') * 10 + (n[k] - '0');
                if (num >= 100 && num <= 999 && distinct[num] == 0) {
                    distinct[num] = 1;
                    count++;
                }
            }
        }
    }

    printf("%d\n", count);

    return 0;
}



