#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <inttypes.h>
#include <stdio.h>

#define MIN_MONTH 1
#define MAX_MONTH 12
#define HOUR 24
#define MINUTE 60
#define T_MAX 99    // по заданию
#define T_MIN -99   // по заданию
#define SIZE_str 527041


typedef struct 
{
    uint16_t year;
    uint8_t month;
    uint8_t day;
    uint8_t hour;
    uint8_t minute;
    int8_t temperature;
} Sensor;

int data_validation (Sensor *info);
int read_data(const char *filename, Sensor data[], int *count, int valid, int error);
void calculate_stats(Sensor data[], int count, int month, float *avg, int *min, int *max);
void print_stats(int month, float avg, int min, int max);
void print_year_stats(Sensor data[], int count, float *year_avg, int *year_min, int *year_max);
void print_help();

