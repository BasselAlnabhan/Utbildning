/*
 * Flextime.h
 *
 *  Created on: Nov 12, 2019
 *      Author: Bassel Alnabhan
 */

#ifndef FLEXTIME_H_
#define FLEXTIME_H_
#include <stdint.h>


// program constants
#define MAX_LENGTH 50
#define NO_OF_WEEKS 2
#define NO_OF_DAYS 5
#define TIME_STAMPLE 4
#define STAMPLES_PER_WEEK (NO_OF_DAYS*TIME_STAMPLE)
#define PERIOD_WORKING_HOURS 40*NO_OF_WEEKS
#define PERCENT 100
#define HOUR_MINUTES 60
#define In_OUT_STAMPLES 2
#define STRING_SEPERATOR ';'
#define DIGIT_SEPERATOR ','
#define STAMP_LENGTH 9
#define FULL_TIME 8
// defining a structure holds the input information
typedef struct{
	int day_number;
	int hour_part;
	int minute_part;
}TimeStamp;
// defining a structure holds the output information
typedef struct{
	int weekNum, dayNum;
	float time;
}WorkTime;
// defining a struct to hold the employee info
typedef struct{
	char *name;
	int emp_no;
	int period;
} Employee;
/*
 * used to convert dynamicaly a string to an array of Flextime structures
 * input - a string
 * output - a pointer to the first element in the array */
TimeStamp *get_stamples(char *input[NO_OF_WEEKS][NO_OF_DAYS][TIME_STAMPLE]);

/* used to calculate and display working hours for a specific number of weeks
 * input - a pointer to the first element of the sequence of structures with flextime type
 * output - none*/
WorkTime *convert2work_struct(TimeStamp *flx_ptr);

/*used to read a file content and save it in a string
 * input - file name
 * output - a string holds the file content*/
void file_read(char f_path[], char *content[NO_OF_WEEKS][NO_OF_DAYS][TIME_STAMPLE]);

/**/
char *output_write(WorkTime *output_structs,char file_name[]);

/**/
void output_file_present(char *fname);

/**/
Employee get_employee_info(char *file_name);
#endif /* FLEXTIME_H_ */
