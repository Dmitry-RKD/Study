#include "ssd1306.h"
#include <math.h>
#include <stdlib.h>
#include <string.h>  // For memcpy

// Команда для отправки байта в регистр управления драйвером
void ssd1306_WriteCommand(uint8_t byte) {
    HAL_I2C_Mem_Write(&SSD1306_I2C_PORT, SSD1306_I2C_ADDR, 0x00, 1, &byte, 1, HAL_MAX_DELAY);
}

// Команда для отправки данных
void ssd1306_WriteData(uint8_t* buffer, size_t buff_size) {
    HAL_I2C_Mem_Write(&SSD1306_I2C_PORT, SSD1306_I2C_ADDR, 0x40, 1, buffer, buff_size, HAL_MAX_DELAY);
}


// Буффер дисплея
static uint8_t SSD1306_Buffer[SSD1306_BUFFER_SIZE];

// Screen object
static SSD1306_t SSD1306;

/* Заливка Буфера экрана со значениями из заданного буфера фиксированной длины */
SSD1306_Error_t ssd1306_FillBuffer(uint8_t* buf, uint32_t len) {
    SSD1306_Error_t ret = SSD1306_ERR;
    if (len <= SSD1306_BUFFER_SIZE) {
        memcpy(SSD1306_Buffer,buf,len);
        ret = SSD1306_OK;
    }
    return ret;
}

/* Иницилизация Oled дисплея */
void ssd1306_Init(void) {

    ssd1306_SetDisplayOn(0); //Выключения дисплея

    ssd1306_WriteCommand(0x20); //Установка режима адресации памяти
    ssd1306_WriteCommand(0x00); // 00b,Горизонтальная адрессация памяти; 01b,Вертикальная адрессация памяти;
                                // 10b,Режим адресации страниц: ; 11b,Неопределлено

    ssd1306_WriteCommand(0xB0); //Установить начальный адрес страницы для режима адресации страниц, 0-7

#ifdef SSD1306_MIRROR_VERT
    ssd1306_WriteCommand(0xC0); // Зеркало вертикально
#else
    ssd1306_WriteCommand(0xC8); //     Установить направление сканирования выхода COM
#endif

    ssd1306_WriteCommand(0x00); //--- установить адрес нижнего столбца
    ssd1306_WriteCommand(0x10); //--- установить адрес верхнего столбца

    ssd1306_WriteCommand(0x40); //--установить адрес начальной строки - CHECK

    ssd1306_SetContrast(0xFF);

#ifdef SSD1306_MIRROR_HORIZ
    ssd1306_WriteCommand(0xA0); //  Зеркало горизонтальное
#else
    ssd1306_WriteCommand(0xA1); //--установить переназначение сегмента 0 на 127 - CHECK
#endif

#ifdef SSD1306_INVERSE_COLOR
    ssd1306_WriteCommand(0xA7); //--Установка инверсии цвета
#else
    ssd1306_WriteCommand(0xA6); //--Установка цвета
#endif

// Комманды определяющие высоту дисплея
    ssd1306_WriteCommand(0xA8); //--установика коэффициентп мультиплексирования (от 1 до 64) - CHECK
#if (SSD1306_HEIGHT == 32)
    ssd1306_WriteCommand(0x1F); //
#elif (SSD1306_HEIGHT == 64)
    ssd1306_WriteCommand(0x3F); //
#elif (SSD1306_HEIGHT == 128)
    ssd1306_WriteCommand(0x3F); //
#else
#error "Only 32, 64, or 128 lines of height are supported!"
#endif

    ssd1306_WriteCommand(0xA4); //0xa4, Вывод следует содержимому ОЗУ; 0xa5, Вывод игнорирует содержимое ОЗУ

    ssd1306_WriteCommand(0xD3); //-установить смещение дисплея - CHECK
    ssd1306_WriteCommand(0x00); //-Нет смещения

    ssd1306_WriteCommand(0xD5); //--установить коэффициент деления тактовой частоты дисплея/частоту генератора
    ssd1306_WriteCommand(0xF0); //--установить коэффициент деления

    ssd1306_WriteCommand(0xD9); //--установить период предварительной зарядки
    ssd1306_WriteCommand(0x22); //

    ssd1306_WriteCommand(0xDA); //--установить аппаратную конфигурацию COM-контактов - CHECK
#if (SSD1306_HEIGHT == 32)
    ssd1306_WriteCommand(0x02);
#elif (SSD1306_HEIGHT == 64)
    ssd1306_WriteCommand(0x12);
#elif (SSD1306_HEIGHT == 128)
    ssd1306_WriteCommand(0x12);
#else
#error "Only 32, 64, or 128 lines of height are supported!"
#endif

    ssd1306_WriteCommand(0xDB); //--set vcomh
    ssd1306_WriteCommand(0x20); //0x20,0.77xVcc

    ssd1306_WriteCommand(0x8D); //--включить DC-DC
    ssd1306_WriteCommand(0x14); //
    ssd1306_SetDisplayOn(1); //--включить панель SSD1306

    // Очистить экран
    ssd1306_Fill(White);
    
    // Сбросить буфер на экран
    ssd1306_UpdateScreen();
    
    // Установить значения по умолчанию для объекта экрана
    SSD1306.CurrentX = 0;
    SSD1306.CurrentY = 0;
    
    SSD1306.Initialized = 1;
}

/* Залить  экран заданным цветом */
void ssd1306_Fill(SSD1306_COLOR color) {
    memset(SSD1306_Buffer, (color == Black) ? 0x00 : 0xFF, sizeof(SSD1306_Buffer));
}

/* Запишите экранный буфер с измененными данными на экран */
void ssd1306_UpdateScreen(void) {
	// Записать данные на каждую страницу оперативной памяти. Количество страниц
	// зависит от высоты экрана:
	// * 32px == 4 страницы
	// * 64px == 8 страниц
	// * 128px == 16 страниц
    for(uint8_t i = 0; i < SSD1306_HEIGHT/8; i++) {
        ssd1306_WriteCommand(0xB0 + i); // Установить текущий адрес страницы ОЗУ.
        ssd1306_WriteCommand(0x00 + SSD1306_X_OFFSET_LOWER);
        ssd1306_WriteCommand(0x10 + SSD1306_X_OFFSET_UPPER);
        ssd1306_WriteData(&SSD1306_Buffer[SSD1306_WIDTH*i],SSD1306_WIDTH);
    }
}
/*
* Отрисовать один пиксель в экранном буфере
* X => Координата X
* Y => Координата Y
* цвет => Цвет пикселя
*/
void ssd1306_DrawPixel(uint8_t x, uint8_t y, SSD1306_COLOR color) {
    if(x >= SSD1306_WIDTH || y >= SSD1306_HEIGHT) {
        // Выход за приделы экрана
        return;
    }
    if(color == White) {
        SSD1306_Buffer[x + (y / 8) * SSD1306_WIDTH] |= 1 << (y % 8);
    } else { 
        SSD1306_Buffer[x + (y / 8) * SSD1306_WIDTH] &= ~(1 << (y % 8));
    }
}


char ssd1306_WriteChar(char ch, SSD1306_Font_t Font, SSD1306_COLOR color) {
    uint32_t i, b, j;
    
    // Проверяем, является ли символ допустимым
    if (ch < 32 || ch > 126)
        return 0;
    
    //     Ширина символа не равна ширине шрифта для пропорционального шрифта.
    const uint8_t char_width = Font.char_width ? Font.char_width[ch-32] : Font.width;
    // Проверить оставшееся место на текущей строке
    if (SSD1306_WIDTH < (SSD1306.CurrentX + char_width) ||
        SSD1306_HEIGHT < (SSD1306.CurrentY + Font.height))
    {
        // Недостаточно места на текущей строке
        return 0;
    }
    
    for(i = 0; i < Font.height; i++) {
        b = Font.data[(ch - 32) * Font.height + i];
        for(j = 0; j < char_width; j++) {
            if((b << j) & 0x8000)  {
                ssd1306_DrawPixel(SSD1306.CurrentX + j, (SSD1306.CurrentY + i), (SSD1306_COLOR) color);
            } else {
                ssd1306_DrawPixel(SSD1306.CurrentX + j, (SSD1306.CurrentY + i), (SSD1306_COLOR)!color);
            }
        }
    }
    
    SSD1306.CurrentX += char_width;
    
    //Возвращаем записанный символ для проверки
    return ch;
}

/* Записать полную строку в буфер экрана */
char ssd1306_WriteString(char* str, SSD1306_Font_t Font, SSD1306_COLOR color) {
    while (*str) {
        if (ssd1306_WriteChar(*str, Font, color) != *str) {
            // Символ не может быть записан
            return *str;
        }
        str++;
    }
    return *str;
}

/* Позиция курсора */
void ssd1306_SetCursor(uint8_t x, uint8_t y) {
    SSD1306.CurrentX = x;
    SSD1306.CurrentY = y;
}

/* Нарисовать линию*/
void ssd1306_Line(uint8_t x1, uint8_t y1, uint8_t x2, uint8_t y2, SSD1306_COLOR color) {
    int32_t deltaX = abs(x2 - x1);
    int32_t deltaY = abs(y2 - y1);
    int32_t signX = ((x1 < x2) ? 1 : -1);
    int32_t signY = ((y1 < y2) ? 1 : -1);
    int32_t error = deltaX - deltaY;
    int32_t error2;
    
    ssd1306_DrawPixel(x2, y2, color);

    while((x1 != x2) || (y1 != y2)) {
        ssd1306_DrawPixel(x1, y1, color);
        error2 = error * 2;
        if(error2 > -deltaY) {
            error -= deltaY;
            x1 += signX;
        }
        
        if(error2 < deltaX) {
            error += deltaX;
            y1 += signY;
        }
    }
    return;
}

/*  прямоугольник */
void ssd1306_DrawRectangle(uint8_t x1, uint8_t y1, uint8_t x2, uint8_t y2, SSD1306_COLOR color) {
    ssd1306_Line(x1,y1,x2,y1,color);
    ssd1306_Line(x2,y1,x2,y2,color);
    ssd1306_Line(x2,y2,x1,y2,color);
    ssd1306_Line(x1,y2,x1,y1,color);

    return;
}

/* закрашенный прямоугольник */
void ssd1306_FillRectangle(uint8_t x1, uint8_t y1, uint8_t x2, uint8_t y2, SSD1306_COLOR color) {
    uint8_t x_start = ((x1<=x2) ? x1 : x2);
    uint8_t x_end   = ((x1<=x2) ? x2 : x1);
    uint8_t y_start = ((y1<=y2) ? y1 : y2);
    uint8_t y_end   = ((y1<=y2) ? y2 : y1);

    for (uint8_t y= y_start; (y<= y_end)&&(y<SSD1306_HEIGHT); y++) {
        for (uint8_t x= x_start; (x<= x_end)&&(x<SSD1306_WIDTH); x++) {
            ssd1306_DrawPixel(x, y, color);
        }
    }
    return;
}


SSD1306_Error_t ssd1306_InvertRectangle(uint8_t x1, uint8_t y1, uint8_t x2, uint8_t y2) {
  if ((x2 >= SSD1306_WIDTH) || (y2 >= SSD1306_HEIGHT)) {
    return SSD1306_ERR;
  }
  if ((x1 > x2) || (y1 > y2)) {
    return SSD1306_ERR;
  }
  uint32_t i;
  if ((y1 / 8) != (y2 / 8)) {
    for (uint32_t x = x1; x <= x2; x++) {
      i = x + (y1 / 8) * SSD1306_WIDTH;
      SSD1306_Buffer[i] ^= 0xFF << (y1 % 8);
      i += SSD1306_WIDTH;
      for (; i < x + (y2 / 8) * SSD1306_WIDTH; i += SSD1306_WIDTH) {
        SSD1306_Buffer[i] ^= 0xFF;
      }
      SSD1306_Buffer[i] ^= 0xFF >> (7 - (y2 % 8));
    }
  } else {
    const uint8_t mask = (0xFF << (y1 % 8)) & (0xFF >> (7 - (y2 % 8)));
    for (i = x1 + (y1 / 8) * SSD1306_WIDTH;
         i <= (uint32_t)x2 + (y2 / 8) * SSD1306_WIDTH; i++) {
      SSD1306_Buffer[i] ^= mask;
    }
  }
  return SSD1306_OK;
}

/* Рисуем растровое изображение */
void ssd1306_DrawBitmap(uint8_t x, uint8_t y, const unsigned char* bitmap, uint8_t w, uint8_t h, SSD1306_COLOR color) {
    int16_t byteWidth = (w + 7) / 8; // Bitmap scanline pad = whole byte
    uint8_t byte = 0;

    if (x >= SSD1306_WIDTH || y >= SSD1306_HEIGHT) {
        return;
    }

    for (uint8_t j = 0; j < h; j++, y++) {
        for (uint8_t i = 0; i < w; i++) {
            if (i & 7) {
                byte <<= 1;
            } else {
                byte = (*(const unsigned char *)(&bitmap[j * byteWidth + i / 8]));
            }

            if (byte & 0x80) {
                ssd1306_DrawPixel(x + i, y, color);
            }
        }
    }
    return;
}
// Установка яркости
void ssd1306_SetContrast(const uint8_t value) {
    const uint8_t kSetContrastControlRegister = 0x81;
    ssd1306_WriteCommand(kSetContrastControlRegister);
    ssd1306_WriteCommand(value);
}

// Функция вкл/выкл дисплея
void ssd1306_SetDisplayOn(const uint8_t on) {
    uint8_t value;
    if (on) {
        value = 0xAF;   // Display on
        SSD1306.DisplayOn = 1;
    } else {
        value = 0xAE;   // Display off
        SSD1306.DisplayOn = 0;
    }
    ssd1306_WriteCommand(value);
}

uint8_t ssd1306_GetDisplayOn() {
    return SSD1306.DisplayOn;
}
