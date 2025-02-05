/*
 * A0.c
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
 * На стандартном потоке ввода задаётся натуральное число N (N > 0), после которого следует последовательность из N целых чисел.
 * На стандартный поток вывода напечатайте, сколько раз в этой последовательности встречается максимум. Указание: использовать массивы запрещается.
 * 
 */


#include <stdio.h>


int main()
{
    int N, count ;
    long read_num ;
    long max;
    
    if (scanf("%d", &N) != 1) 
    {
        printf("Ошибка считывания входных данных.\n");
        return 1;
    }
    if (N <= 0) 
    {
        printf("Некоректные данные: N должно быть больше 0.\n");
        return 1;
    }
    count = 0;
    for (int i = 0; i < N; i++) 
    {
		if (scanf("%ld", &read_num) != 1)
		{
            break ;
        }
        if (i==0)
        {
			max=read_num;
			count=1;
		}
        else if (read_num > max)
        {
            max = read_num; 
            count = 1; 
        }
        else if (read_num == max)
        {
            count++; 
        }
    }
    printf("%d\n", count);
    return 0;
}

