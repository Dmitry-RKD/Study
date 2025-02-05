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
 * Шифр Цезаря
На стандартном потоке ввода задается целое неотрицательное число N и последовательность допустимых символов в кодировке ASCII, 
оканчивающаяся точкой. Допустимые символы - латинские буквы 'a' ... 'z', 'A' ... 'Z' и пробел. Требуется закодировать латинские буквы ('a' ... 'z', 'A' ... 'Z') 
шифром Цезаря, пробелы вывести без изменения. Число N задает сдвиг в шифре. Шифр Цезаря заключается в следующем преобразовании. Пусть буквы алфавита пронумерованы от 0 до K - 1, 
где K - число символов в алфавите. Тогда символ с номером n кодируется символом с номером p = (n + N) mod K (mod - операция взятия остатка). На стандартном потоке вывода напечатать 
зашифрованное сообщение, оканчивающееся точкой. Преобразование требуется выполнять независимо для заглавных и строчных латинских букв. Указание: использовать массивы запрещается.
 * 
 */


#include <stdio.h>


int main()
{
    int N;
    char A,Temp;
    
    if (scanf("%d", &N) != 1) 
    {
        printf("Ошибка считывания входных данных.\n");
        return 1;
    }
    if (N < 0) 
    {
        printf("Некоректные данные: N должно быть больше 0.\n");
        return 1;
    }
    Temp=getchar();
    if (Temp>='a' && Temp <= 'z')
		A=97+(Temp+N-'a')%26;
	else if (Temp>='A' && Temp <= 'Z')
		A=65+(Temp+N-'a')%26;
    while (Temp!='.')
    {
		if (Temp>='a' && Temp <= 'z')
			A=97+(Temp+N-'a')%26;
		else if (Temp>='A' && Temp <= 'Z')
			A=65+(Temp+N-'A')%26;
		else
			A=Temp;
		putchar(A);
		Temp=getchar();
		if(Temp=='.')
			putchar(Temp);
    }
    return 0;
}

