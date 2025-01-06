#include "temp_functions.h"

void print_help() 
{
    printf("Usage: ./stats.exe -f <filename.csv> -m <month> \n");
    printf("    -h    Show this help message.\n");
    printf("    -f    Enter the name of the CSV file.le.\n");
    printf("    -m    It can take the value [1-12] to calculate statistics for the specified month. If the -m argument is omitted or the month after the -m argument is omitted, statistics for the year are calculated\n");
    printf("    -v    Enables console output of the line number and a line with incorrect data. Disabled by default. \n");
    printf("    -e    Switches the output of error messages in a data file to a text file: Error.txt. By default, output is made to the console. \n");
} 

int read_data (const char *filename, Sensor data[], int *count, int valid, int error)
{
    FILE *file = fopen(filename, "r");
    FILE *Err = fopen ("Error.txt", "w");
  
    if (file == NULL)
    {
        printf("Error opening file\n");
        return 1;
    }

    char line[1024];
    int line_num = 1;
    char temp_line[1024];
    Sensor info;

    while (fgets(line, sizeof(line), file) != NULL)
    {
        strcpy(temp_line,line);
        //------------------------------------------------------------------------------------------------------------------------------------------------------------------
        if (sscanf(line,"%d;%d;%d;%d;%d;%d", &info.year, &info.month, &info.day, &info.hour, &info.minute, &info.temperature) != 6) 
        {
            if (error == 0)
			    printf("Error parsing line %d: %s\n", line_num, line);
            else
                fprintf(Err, "Error parsing line %d: %s", line_num, line);
        }
        else if (data_validation(&info))
        {
            if (valid)
            {
                if (error ==0 )
                    printf ("Invalid data in line  %d: %s\n", line_num, line); 
                else    
                    fprintf(Err, "Error parsing line %d: %s", line_num, line);
            }
        }
        //------------------------------------------------------------------------------------------------------------------------------------------------------------------
        else 
        {
            data[*count]= info;
            (*count)++;
        }
        line_num++;
        if (*count==SIZE_str) // проверка на максимальную длинну читаемых данных
            break;
    }

    fclose(file);
    return 0;
    
}

void calculate_stats(Sensor data[], int count, int month, float *avg, int *min, int *max)
{
    int count_month = 0;
    float sum_month = 0;
    *min = T_MAX;
    *max = T_MIN;

    for (int i = 0; i < count; i++) 
    {
        if (data[i].month == month)
        {
            count_month++;
            sum_month += data[i].temperature;
            if (data[i].temperature < *min) 
                *min = data[i].temperature;
            if (data[i].temperature > *max) 
                *max = data[i].temperature;
        }
    }
    if (count_month > 0) 
        *avg = sum_month / count_month;
    else 
    {
    *avg = 0;
    *min = 0;
    *max = 0;
    }
}

void print_stats(int month, float avg, int min, int max)
 {
    if (avg!=0 && min!=0 && max!=0)
    {
        printf("Month %d:\n", month);
        printf("  Average temperature: %.2f\n", avg);
        printf("  Minimum temperature: %d\n", min);
        printf("  Maximum temperature: %d\n", max);
    }
    else 
       printf("Month %d: Missing data\n", month); 
 }


void print_year_stats(Sensor data[], int count, float *year_avg, int *year_min, int *year_max)
 {
    float sum = 0;
    *year_min = data[0].temperature ;
    *year_max = data[0].temperature ;

    for (int i = 0; i < count; i++)
    {
        sum += data[i].temperature;
        if (data[i].temperature < *year_min)
            *year_min = data[i].temperature;
        if (data[i].temperature > *year_max) 
            *year_max = data[i].temperature;
    }

    *year_avg = sum / count;
}

int data_validation (Sensor *info)
{
    int DAY=0;
    int YEAR=2024;
    if (info->month < MIN_MONTH || info->month > MAX_MONTH || info->temperature <= T_MIN || info->temperature >= T_MAX)
        return 1;
    switch (info->month)
    {
        case 1: 
            DAY=31;
            break;
        case 2:
            if ((YEAR-(info->year))%4==0)
                DAY=29;
            else
                DAY=28;
            break;
        case 3: 
            DAY=31;
            break;
        case 4: 
            DAY=30;
            break;
        case 5: 
            DAY=31;
            break;
        case 6: 
            DAY=30;
            break;
        case 7: 
            DAY=31;
            break;
        case 8: 
            DAY=31;
            break;
        case 9: 
            DAY=30;
            break;
        case 10: 
            DAY=31;
            break;
        case 11: 
            DAY=30;
            break;
        case 12: 
            DAY=31;
            break;
    }

    if (info->day > DAY || info->hour > HOUR || info->minute > MINUTE)
        return 1;
    return 0;
}