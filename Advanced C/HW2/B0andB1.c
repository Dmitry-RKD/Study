/*
 * B0andB1.c
 * 
 * Copyright 2025 Dmitry <Dmitry@DESKTOP-J3GNGPV>
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
#include <stdlib.h>

typedef struct list
{
    uint64_t address;
    size_t size;
    char comment[64];
    struct list *next;
} list;

size_t totalMemoryUsage(list *head)
{
    list *temp = head;
    size_t general_memory = temp->size;
    while (temp->next != NULL)
    {
        temp = temp->next;
        general_memory += temp->size;
    }
    return general_memory;
}

uint64_t findMaxBlock(list *head)
{
    list *temp = head;
    size_t max_size;
    uint64_t address_max;
    max_size = temp->size;
    address_max = temp->address;

    while (temp->next != NULL)
    {
        temp = temp->next;
        if (temp->size > max_size)
        {
            max_size = temp->size;
            address_max = temp->address;
        }
    }
    return address_max;
}



int main(void)
{
    return 0;
}

