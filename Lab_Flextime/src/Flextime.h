/*
     .-,--' .          .                 .
. ,   \|__  |  ,-. . , |- . ,-,-. ,-.    |-.
-X-    |    |  |-'  X  |  | | | | |-'    | |
' `   `'    `' `-' ' ` `' ' ' ' ' `-' :; ' '

       ,--.             .        .                ,-,-.
. ,     | `-' ,-. ,-. ,-. |- ,-. ,-|   ,-. ,-. :;   ` | |   ,-. .  ,    , ,-,      ,-, ,-.  , ,-.
-X-     |   . |   |-' ,-| |  |-' | |   | | | |        | |-. | | | /    '|  /        /  |/| '| `-|
' `     `--'  '   `-' `-^ `' `-' `-^   `-' ' ' :;    ,' `-' `-' `'      ` '-` :;   '-` `-'  ` `-'
                                                                                 '
             ,.       .  .               ,-,---.                 .       ,.   .          .   .
. ,         / |   . . |- |-. ,-. ,-. :;   '|___/ ,-. ,-. ,-. ,-. |      / |   |  ,-. ,-. |-. |-. ,-. ,-.
-X-        /~~|-. | | |  | | | | |        ,|   \ ,-| `-. `-. |-' |     /~~|-. |  | | ,-| | | | | ,-| | |
' `      ,'   `-' `-^ `' ' ' `-' '   :;  `-^---' `-^ `-' `-' `-' `'  ,'   `-' `' ' ' `-^ ^-' ' ' `-^ ' '
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
#define FRI_TO_MON 3
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
 * used to convert an array of strings to an array of Flextime structures
 * input - an empty multidimentional array of strings
 * output - a pointer to the first element of created array of type Flextime */
TimeStamp *get_stamples(char *input[NO_OF_WEEKS][NO_OF_DAYS][TIME_STAMPLE]);

/* used to calculate the working hours for a specific number of days and save them in an array of type Worktime
 * input - a pointer to the first element of the sequence of structures with flextime type
 * output - a pointer to the array of type WorkTime*/
WorkTime *convert2work_struct(TimeStamp *flx_ptr);

/*used to read a file content and save it into array of strings(each string is a time stamp)
 * input - file name and the array that holds the time stamps as strings
 * output - none*/
void file_read(char f_path[], char *content[NO_OF_WEEKS][NO_OF_DAYS][TIME_STAMPLE]);

/*used to write the working hours to a data file
 * input - a pointer to the first element of the Working times in structures of type WorkTime
 * output - the file name excluding the postfix  */
char *output_write(WorkTime *output_structs,char file_name[]);

/*used to read the data file and present the working times to the console
 * input - the file name as a string
 * output - none*/
void output_file_present(char *fname);

/*used to handle and catch the info from file name (name,number,period) and save them to a struct "Employee" variable
 * input - a string holds the file name
 * output - a variable of Employee type*/
Employee get_employee_info(char *file_name);
#endif /* FLEXTIME_H_ */
