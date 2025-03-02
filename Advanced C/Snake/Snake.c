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
#include <stdlib.h>
#include <time.h>
#include <ncurses/ncurses.h>
#include <inttypes.h>
#include <string.h>
#include <unistd.h>

#define MIN_Y  0
#define Start_Y 20
#define Start_X 20
enum {LEFT=1, UP, RIGHT, DOWN, STOP_GAME=KEY_F(10), START_NEW=KEY_F(5)};
enum {MAX_TAIL_SIZE=100, START_TAIL_SIZE=5, MAX_FOOD_SIZE=6, FOOD_EXPIRE_SECONDS=2,SEED_NUMBER=5,COLLOR_SNAKE=5,COLLOR_TAIL=1};
// параметры рабочего окна игры змейка
#define width  100
#define height 20
#define offsetx  2
#define offsety  10
// параметры информационного окна
#define W_width  100
#define W_height 10
#define W_offsetx  2
#define W_offsety  0

struct control_buttons
{
    int down;
    int up;
    int left;
    int right;
}control_buttons;

struct control_buttons default_controls[3] = {{KEY_DOWN, KEY_UP, KEY_LEFT, KEY_RIGHT}, {'s', 'w', 'a', 'd'}, {'S', 'W', 'A', 'D'}};

/*
 Голова змейки содержит в себе
 x,y - координаты текущей позиции
 direction - направление движения
 tsize - размер хвоста
 *tail -  ссылка на хвост
 */
 void InitColors() 
{
    init_pair(1, COLOR_RED, COLOR_BLACK);
    init_pair(2, COLOR_BLUE, COLOR_BLACK);
    init_pair(3, COLOR_GREEN, COLOR_BLACK);
    init_pair(4, COLOR_YELLOW, COLOR_BLACK);
    init_pair(5, COLOR_MAGENTA, COLOR_BLACK);
    init_pair(6, COLOR_CYAN, COLOR_BLACK);
}
 
 
typedef struct snake_t
{
    int x;
    int y;
    int direction;
    size_t tsize;
    struct tail_t *tail;
    struct control_buttons controls;
    int collor;
} snake_t;

/*
 Хвост это массив состоящий из координат x,y
 */
typedef struct tail_t
{
    int x;
    int y;
    int collor;
} tail_t;

struct food
{
    int x;
    int y;
    time_t put_time;
    char point;
    uint8_t enable;
} food[MAX_FOOD_SIZE];

void initFood(struct food f[], size_t size)
{
    struct food init = {0,0,0,0,0};
    for(size_t i=0; i<size; i++)
    {
        f[i] = init;
    }
}

void initTail(struct tail_t t[], size_t size)
{
    struct tail_t init_t={0,0,COLLOR_TAIL};
    for(size_t i=0; i<size; i++)
    {
        t[i]=init_t;
    }
}
void initHead(struct snake_t *head, int x, int y)
{
    head->x = x;
    head->y = y;
    head->direction = RIGHT;
}

void initSnake(snake_t *head, size_t size, int x, int y)
{
tail_t*  tail  = (tail_t*) malloc(MAX_TAIL_SIZE*sizeof(tail_t));
    initTail(tail, MAX_TAIL_SIZE);
    initHead(head, x, y);
    head->tail = tail; // прикрепляем к голове хвост
    head->tsize = size+1;
    head->controls = default_controls[3];
    head->collor=COLLOR_TAIL;
}

void setColor(int objectType)
{
    attroff(COLOR_PAIR(1));
    attroff(COLOR_PAIR(2));
    attroff(COLOR_PAIR(3));
    attroff(COLOR_PAIR(4));
    attroff(COLOR_PAIR(5));
    attroff(COLOR_PAIR(6));
    switch (objectType)
    {
        case 1:
        { // SNAKE1
            attron(COLOR_PAIR(1));
            break;
        }
        case 2:
        { // SNAKE2
            attron(COLOR_PAIR(2));
            break;
        }
        case 3:
        { // FOOD
            attron(COLOR_PAIR(3));
            break;
        }
        case 4:
        {
			attron(COLOR_PAIR(4));
			break;
		}
		case 5:
        {
			attron(COLOR_PAIR(5));
			break;
		}
		case 6:
        {
			attron(COLOR_PAIR(6));
			break;
		}
    }
}


void putFoodSeed(struct food *fp)
{
    char spoint[2] = {0};
     //int max_x=0, max_y=0;
    // getmaxyx(stdscr, max_y, max_x);
    mvprintw(fp->y, fp->x, " ");
    fp->x = rand() % (width-offsetx)+offsetx+1;
    fp->y = rand() % (height-offsety)+offsety+1; //Не занимаем верхнюю строку
    fp->put_time = time(NULL);
    fp->point ='$';
    fp->enable = 1;
    spoint[0] = fp->point;
	setColor(4);
    mvprintw(fp->y, fp->x, "%s", spoint);
    attroff(COLOR_PAIR(4));
}

void putFood(struct food f[], size_t number_seeds)
{
    for(size_t i=0; i<number_seeds; i++)
    {
        putFoodSeed(&f[i]);
    }
}


void refreshFood(struct food f[], int nfood)
{
    for(size_t i=0; i<nfood; i++)
    {
        if( f[i].put_time )
        {
            if( !f[i].enable || (time(NULL) - f[i].put_time) > FOOD_EXPIRE_SECONDS )
            {
                putFoodSeed(&f[i]);
            }
        }
    }
}



/*
 Движение головы с учетом текущего направления движения
 */
void go(struct snake_t *head)
{
    char ch = '@';
	mvprintw(head->y, head->x, " ");
	setColor(head->collor);
    switch (head->direction) // Циклическое движение, чтобы не уходить за пределы экрана
    {
        case LEFT:
            if(head->x <= offsetx+1) 
                head->x =(width+offsetx-1);
            mvprintw(head->y, --(head->x), "%c", ch);
        break;
        case RIGHT:
			if(head->x >= (width+offsetx-2))
				head->x = offsetx+1;
            mvprintw(head->y, ++(head->x), "%c", ch);
        break;
        case UP:
			if(head->y <= offsety+1)
				head->y=(height+offsety-1);	
            mvprintw(--(head->y), head->x, "%c", ch);
        break;
        case DOWN:
			if (head->y >= height+offsety-2)
				head->y = offsety;
            mvprintw(++(head->y), head->x, "%c", ch);
        break;
        default:
        break;
    }
    attroff(COLOR_PAIR(head->collor));
    refresh();
}

void changeDirection(struct snake_t* snake, const int32_t key)
{
	for (int i=0;i<3;i++)
	{
		snake->controls = default_controls[i];
		if (key == snake->controls.down && snake->direction != UP)
			snake->direction = DOWN;
		else if (key == snake->controls.up && snake->direction != DOWN)
			snake->direction = UP;
		else if (key == snake->controls.right && snake->direction != LEFT)
			snake->direction = RIGHT;
		else if (key == snake->controls.left && snake->direction != RIGHT)
			snake->direction = LEFT;
    }
}

/*
 Движение хвоста с учетом движения головы
 */
void goTail(struct snake_t *head)
{
    char ch = '#';
    mvprintw(head->tail[head->tsize-1].y, head->tail[head->tsize-1].x, " ");
    setColor(COLLOR_TAIL);
    for(size_t i = head->tsize-1; i>0; i--)
    {
        head->tail[i] = head->tail[i-1];
        if( head->tail[i].y || head->tail[i].x)
            mvprintw(head->tail[i].y, head->tail[i].x, "%c", ch);
    }
    attroff(COLOR_PAIR(COLLOR_TAIL));
    head->tail[0].x = head->x;
    head->tail[0].y = head->y;

}

int checkBump(struct snake_t *head )
{
	for(size_t i = head->tsize-1; i>0; i--)
	{
		if ( head->tail[i].x == head->x && head->tail[i].y == head->y)
			return 1;
	}
	return 0;
}
_Bool haveEat (struct snake_t *head, struct food f[],int *count)
{
	for (int i=0;i<SEED_NUMBER;i++)
	{
		if (head->x == f[i].x && head->y == f[i].y)
		{
			f[i].enable=0;
			(*count)++;
			return 1;
		}
	}
	return 0;
}

void addTail(struct snake_t *head)
{
	head->tsize+=1;
}

int repairSeed(struct food *f, size_t nfood, struct snake_t *head)
{
    for( size_t i=0; i<head->tsize; i++ )
        for( size_t j=0; j<nfood; j++ )
        {
			if(f[j].x == head[i].x && f[j].y == head[i].y)
			{
				refreshFood(f,SEED_NUMBER);
			}
        }
    for( size_t i=0; i<nfood; i++ )
        for( size_t j=1; j<nfood; j++ )
        {
			if(f[i].x == f[j].x && f[i].y ==f[j].y)
			{
				refreshFood(f,SEED_NUMBER);
			}
        }
    return 0;
}
void update (struct snake_t *head, struct food f[],const int32_t key,int *count)
{
	go(head);
	if (haveEat (head, food, &(*count)))
		addTail(head);
    goTail(head);
    setColor(6);
    mvprintw(W_offsety+3, W_offsetx+4,"The amount of food eaten: %d", *count);
    mvprintw(W_offsety+4, W_offsetx+4,"To win, it remains to eat: %d", MAX_FOOD_SIZE-*count);
    mvprintw(W_offsety+5, W_offsetx+4,"Snake Length:%llu  ",head->tsize);

	switch (head->direction)
	{
		case LEFT:
		mvprintw(W_offsety+6, W_offsetx+4,"CURRENT DIRECTIONS: LEFT ");
		break;
		case RIGHT:
		mvprintw(W_offsety+6, W_offsetx+4,"CURRENT DIRECTIONS: RIGHT");
		break;
		case UP:
		mvprintw(W_offsety+6, W_offsetx+4,"CURRENT DIRECTIONS: UP   ");	
		break;
		case DOWN:
		mvprintw(W_offsety+6, W_offsetx+4,"CURRENT DIRECTIONS: DOWN ");
		break;
	}	
	attroff(COLOR_PAIR(6));
	refreshFood(food, SEED_NUMBER);
	repairSeed(food,SEED_NUMBER,head);
    changeDirection(head, key);
}



	



int main()
{
	int count=0;
	snake_t* snake = (snake_t*)malloc(sizeof(snake_t));
	initscr();
    curs_set(0);
    refresh();
    start_color();
	InitColors();
    WINDOW *win = newwin(height, width, offsety, offsetx);
    box(win, 0, 0);
    WINDOW *win1 = newwin(W_height, W_width, W_offsety, W_offsetx);
    box(win1, 0, 0);
    initSnake(snake,START_TAIL_SIZE,Start_X,Start_Y);
    keypad(stdscr, TRUE); // Включаем F1, F2, стрелки и т.д.
    noecho();            // Отключаем echo() режим при вызове getch
    curs_set(FALSE);    //Отключаем курсор
    attron(COLOR_PAIR(3));
    mvprintw(1, 5," Use arrows for control. Press 'F10' for EXIT");
    mvprintw(2, 5," Use the keys to control: wasd,WASD or arrows UP,DOWN,LEFT,RIGHT");
    attroff(COLOR_PAIR(3));
    timeout(0);    //Отключаем таймаут после нажатия клавиши в цикле
    initFood(food, MAX_FOOD_SIZE);
    putFood(food, SEED_NUMBER);// Кладем зерна
    wbkgd(win1, COLOR_PAIR(1));
    wbkgd(win, COLOR_PAIR(2));
    wrefresh(win);
    wrefresh(win1);  
    wbkgd(win1, COLOR_PAIR(1));
    int key_pressed=0;
    while( key_pressed != STOP_GAME )
    {
        key_pressed = getch(); // Считываем клавишу
        update(snake, food, key_pressed, &count);
		if (checkBump(snake)==1)
		{
			clear() ;
			key_pressed=0;
			while(key_pressed!='\n')	
			{	
				int max_x=0, max_y=0;
				getmaxyx(stdscr, max_y, max_x);
				mvprintw(max_y/2, max_x/2-4,"GAME OVER");
				
				key_pressed = getch();
				mvprintw(2, max_x/2-8,"Press ENTER to exit.");
			}
			break;
		}
        if (count>=MAX_FOOD_SIZE)
			{
				clear() ;
				key_pressed=0;
				while (key_pressed!='\n')
				{
					int max_x=0, max_y=0;
					getmaxyx(stdscr, max_y, max_x);
					mvprintw(max_y/2, max_x/2-3,"YOU WIN");
					key_pressed = getch();
					mvprintw(2, max_x/2-8,"Press ENTER to exit.");
				}
			break;
			}
		timeout(50); // Задержка при отрисовке
    }
    free(snake->tail);
    free(snake);
    endwin(); // Завершаем режим curses mod
    return 0;
}

