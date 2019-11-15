/*
 * Flextime.h
 *
 *  Created on: Nov 12, 2019
 *      Author: Bassel Alnabhan
 */

#ifndef FLEXTIME_H_
#define FLEXTIME_H_
#include <stdint.h>

// fast debugging constants
#define DEBUG false
#define true 1
#define false 0
// program constants
#define NO_OF_WEEKS 1
#define NO_OF_DAYS 5
#define TIME_STAMPLE 4
#define STAMPLES_PER_WEEK (NO_OF_DAYS*TIME_STAMPLE)
#define PERIOD_WORKING_HOURS 40*NO_OF_WEEKS
#define PERCENT 100
#define HOUR_MINUTES 60
#define In_OUT_STAMPLES 2
#define STRING_SEPERATOR ';'
#define DIGIT_SEPERATOR ','

// defining a structure holds a working time stample information
typedef struct{
	int day_number;
	int hour_part;
	int minute_part;
}Flextime;

Flextime *get_stamples(char *input_string);

/*
 * used to convert dynamicaly a 3D array to Flextime structure
 * input - a 3D array of flextime type
 * output - a pointer to the first variable of a flextime type */
Flextime *flextime_fill(Flextime input[NO_OF_WEEKS][NO_OF_DAYS][TIME_STAMPLE]);

/* used to calculate and display working hours for a specific number of weeks
 * input - a pointer to the first element of the sequence of structures with flextime type
 * output - none*/
void present_work_weeks(Flextime *flx_ptr);

/*used to calculate the number of needed structs to hold the whole working period
 * input - a string of data separated with ';'
 * output - an integer*/
int count_stamples(char input_string[]);

#endif /* FLEXTIME_H_ */
