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

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "Flextime.h"
extern _Bool DEBUG;

int main(int argc, char **argv)
{
	TimeStamp *times;
	WorkTime *work_times;
	char *content[NO_OF_WEEKS][NO_OF_DAYS][TIME_STAMPLE],file_name[MAX_LENGTH],*name;

	if(argc > 1)
	{strcpy(file_name, argv[1]);}
	else {strcpy(file_name, "EK_201_201945.txt");}
	if(argc > 2)
	{if(strcmp(argv[2],"DEBUG") == 0) DEBUG = true;}
	setbuf(stdout,NULL);

	// read the file and store in multidimentional array of strings for each timestamp
	file_read(file_name,content);

	//convert string array elements to flextime structures
	times = get_stamples(content);

	// calculate and store work hours info array of output structures
	work_times = convert2work_struct(times);

	// write working hours to a new file.dat
	name = output_write(work_times,file_name);

	// read the new file.dat and present the content on console
	output_file_present(name);

	return 0;
}
