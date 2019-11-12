/*
 * Flextime.h
 *
 *  Created on: Nov 12, 2019
 *      Author: Bassel Alnabhan
 */

#ifndef FLEXTIME_H_
#define FLEXTIME_H_
#include <stdint.h>


#define NO_OF_WEEKS 2
#define NO_OF_DAYS 5* NO_OF_WEEKS
#define TIME_STAMPLE 4
#define CURRENT_YEAR 2019
#define WEEK_WORKING_HOURS 40*NO_OF_WEEKS

typedef struct{
	int day_number;
	int hour_part;
	int minute_percentage;
}Flextime;

Flextime *flextime_fill(Flextime input[NO_OF_DAYS][TIME_STAMPLE], int n);

void present_work_week(Flextime *flx_ptr);

#endif /* FLEXTIME_H_ */
