/*
 * E19.c
 * 
 * Copyright 2024 Дмитрий <Дмитрий@DESKTOP-V4T7I45>
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
/* 
Цифры по порядку
Вывести в порядке следования цифры, входящие в десятичную запись натурального числа N.
Формат входных данных
Одно натуральное число N
Формат результата
Цифры через пробел
Примеры
Входные данные
54412
Результат работы
5 4 4 1 2 */



#include <stdio.h>

void print_number(int n)
{
	if (n == 0) 
		return; 
	print_number (n/10);
	printf("%d ",n%10);
}   
		

int main(int argc, char **argv)
{
	int a;
	scanf("%d",&a);
	if (a==0)
		printf("%d\n",0);
	print_number(a);
	
	return 0;
}

