/*
 * D0.c
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
 
 //Отсортировать слова
//Дана строка, состоящая из английских букв и пробелов. В конце строки символ точка. Все слова разделены одним пробелом. Необходимо составить из слов односвязный список и упорядочить по алфавиту. Список необходимо удалить в конце программы. Для сравнение строк можно использовать strcmp. Необходимо использовать данную структуры организации списка.
//struct list {
//char word[20];
//struct list *next;
//}
//Необходимо реализовать односвязный список и обслуживающие его функции.

//add_to_list
 //swap_elements
 //print_list
 //delete_list
//Примеры
//Входные данные
//efg abcd zzz.
//Результат работы
//abcd efg zzz

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORD_LENGH 20

struct list 
{
    char word[MAX_WORD_LENGH];
    struct list *next;
};

void add_to_list(struct list **next, char *word) 
{
    struct list *newword = (struct list *)malloc(sizeof(struct list));
    if (newword == NULL) 
    {
        printf("Ошибка выделения памяти\n");
        return ;
    }
    strcpy(newword->word, word);
    newword->next = NULL;

    if (*next == NULL)
        *next = newword;
    else 
	{
        struct list *current = *next;
        while (current->next != NULL) 
        {
            current = current->next;
        }
        current->next = newword;
    }
}

void swap_elements(struct list *node1, struct list *node2) 
{
    char temp[MAX_WORD_LENGH];
    strcpy(temp, node1->word);
    strcpy(node1->word, node2->word);
    strcpy(node2->word, temp);
}

void sort_list(struct list *head) 
{
    if (head == NULL)
    {
        return;
    }
	int temp;
    struct list *a;
    struct list *b = NULL;

    do 
    {
        temp = 0;
        a = head;
        while (a->next != b) 
        {
            if (strcmp(a->word, a->next->word) > 0)
            {
                swap_elements(a, a->next);
                temp = 1;
            }
            a = a->next;
        }
        b = a;
    } 
    while (temp);
}

void print_list(struct list *head) 
{
    struct list *current = head;
    while (current != NULL) 
    {
        printf("%s ", current->word);
        current = current->next;
    }
    printf("\n");
}

void delete_list(struct list **head) {
    struct list *current = *head;
    struct list *next;
    while (current != NULL) 
    {
        next = current->next;
        free(current);
        current = next;
    }
    *head = NULL;
}

int main(int argc, char **argv)
{
	char input[1000];
    char word[MAX_WORD_LENGH];
    struct list *head = NULL;

    fgets(input, sizeof(input), stdin);

    int i = 0;
    int j = 0;
    while (input[i] != '.' && input[i] != '\0') 
    {
        if (input[i] != ' ') 
			word[j++] = input[i];
		else 
		{
            word[j] = '\0';
            add_to_list(&head, word);
            j = 0;
        }
        i++;
    }

    // Добавление последнего слова
    word[j] = '\0';
    add_to_list(&head, word);

    // Сортировка списка
    sort_list(head);

    // Печать отсортированного списка
    print_list(head);

    // Удаление списка
    delete_list(&head);

    return 0;
}

