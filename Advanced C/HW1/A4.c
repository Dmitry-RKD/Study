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
 * Поиск последовательности бит
На вход программе подается беззнаковое 32-битное целое число N и натуральное число K (1 ≤ K ≤ 31).
 Требуется взять K подряд идущих битов числа N так, чтобы полученное число было максимальным. Программа должна вывести полученное число.
 */
 
#include <stdio.h>
#include <stdint.h>

	uint32_t max_bit(uint32_t n, int k)
	{
		uint32_t M_bit = 0;
		uint32_t mask = (1U << k) - 1;  
		uint32_t temp_bit;

		for (int i = 0; i <= 32 - k; i++) 
		{
			temp_bit = (n >> i) & mask; // Сдвигаем и cчитываем K битов
			if (temp_bit > M_bit) 
				M_bit = temp_bit;
		}
		return M_bit;
	}

	int main()
	{
		uint32_t n;
		int k;

		scanf("%u %d", &n, &k); 
		uint32_t result = max_bit(n, k);
		printf("%u\n", result);
		return 0;
	}

