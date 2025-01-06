/*
 * * Copyright 2024 Dmitry <Dmitry@DESKTOP-J3GNGPV>
 */

#include "temp_functions.h"


Sensor data[SIZE_str] = {0};

int main(int argc, char *argv[])

{ 
    char *filename = NULL;
    int month = 0;
    int valid=0;
    int error=0;
    int count=0;
    // Описанание агрументов командной строки
    /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    for (int i=1; i < argc; i++)
	{
		if (strcmp(argv[i], "-h")== 0)
		{
			print_help();
			return 0;
		}
		else if (strcmp(argv[i], "-f")== 0)
		{
			if ((i+1)<argc)
				filename=argv[++i];
			else
			{
				printf("Error, after the -f argument, you must specify the file name in the format: -f name.csv \n");
				return 1;
			}
		}
		else if (strcmp(argv[i], "-m")== 0)
		{
			if (i+1<argc)
				month=atoi(argv[++i]);
			if ( MIN_MONTH > month || month > MAX_MONTH)
			{
				printf("Error, the month value is entered incorrectly after the -m argument, the value can take values from 1 to 12. \n");
				return 1;
			}
		}
        else if (strcmp(argv[i],"-v")==0)
            valid=1;
        
        else if (strcmp(argv[i],"-e")==0)
            error=1;
       else
       {
            printf("Enter -h to get help with the arguments!\n");
            return 1;
       }
	} 
    
	if (filename==NULL)
	{
		printf("Error, the name of the source data file was not entered.Enter it in the line. Enter it in the line ./name.exe -h to get help\n");
		return 1;		
	} 
    // Окончание описание аргументов///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

// Вызов функции чтения файла
    if (read_data(filename, data, &count, valid, error))
    {
      return 1;
    }
// Вызов функции расчета и печати для указанного месяца////////////////////////////////////////////////////////////////////////////////////////////////////
    if (month > 0) 
    {
        float avg;
        int min, max;
        calculate_stats(data, count, month, &avg, &min, &max);
        print_stats(month, avg, min, max);
    } 
    // Вызов функции и печать данных, если не указан месяц в аргументе m //////////////////////////////////////////////////////////////////////////////////////
    else 
    {
        for (int j = 1; j <= 12; j++)
        {
            float avg;
            int min, max;
            calculate_stats(data, count, j, &avg, &min, &max);
            print_stats(j, avg, min, max);
        }
        float year_avg;
        int year_min, year_max;
        print_year_stats(data, count, &year_avg, &year_min, &year_max);
        printf("\nStatistics per yaer:\n");
        printf("  Average temperature: %.2f\n", year_avg);
        printf("  Minimum temperature: %d\n", year_min);
        printf("  Maximum temperature: %d\n", year_max);
    } 
    return 0;
}
