/*
 * main_Flestime.c
 *
 *  Created on: Nov 12, 2019
 *      Author: Bassel Alnabhan
 */

#include <stdio.h>
#include <stdlib.h>

#include "Flextime.h"

int main()
{
	Flextime *flx_ptr,test_values [NO_OF_WEEKS][NO_OF_DAYS][TIME_STAMPLE] = {
			{{{308,07,33},{308,11,44},{308,12,31},{308,16,10}},
			{{309,07,52},{309,11,52},{309,12,35},{309,16,18}},
			{{310,07,24},{310,11,40},{310,12,30},{310,16,14}},
			{{311,07,15},{311,11,38},{311,12,36},{311,16,27}},
			{{312,07,12},{312,11,47},{312,12,30},{312,16,12}}},
			{{{315,07,12},{315,11,34},{315,12,27},{315,16,52}},
			{{316,07,15},{316,11,49},{316,12,31},{316,16,13}},
			{{317,07,59},{317,11,44},{317,12,38},{317,16,42}},
			{{318,07,52},{318,11,41},{318,12,30},{318,16,12}},
			{{319,8,03},{319,11,32},{319,12,39},{319,16,07}}}};

	//convert the string to a multidimentional array holds the values

	setbuf(stdout,NULL);
	//convert the values in the multidimensional array to flextime structures
	flx_ptr = flextime_fill(test_values);
	// calculate and present the working time for everyday of every week in the whole period
	present_work_weeks(flx_ptr);

	return 0;
}
