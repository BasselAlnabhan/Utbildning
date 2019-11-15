/*
 * func_Flextime.c
 *
 *  Created on: Nov 12, 2019
 *      Author: Bassel Alnabhan
 */
#include <stdlib.h>
#include "Flextime.h"
#include <stdio.h>
#include <string.h>


Flextime *get_stamples(char input_string[])
{
	Flextime *t;
	int str_index=0;
	int needed_structs = count_stamples(input_string);
	char *structures [needed_structs];
	char seperate_string[] = {STRING_SEPERATOR, '\0'};
	char seperate_digits[] = {DIGIT_SEPERATOR, '\0'};
//	char temp[9];
//	memcpy(temp,input_string,9);
//	memset(temp,0,9);
//	memcpy(temp,input_string+10,9);

	if(DEBUG){printf("DEBUG %d",needed_structs);}

	structures[str_index++] = strtok(input_string, seperate_string);

	for(int i=str_index;i<needed_structs;i++)
	{
		structures[i] = strtok(NULL,seperate_string);
	}

	if( (t  = (Flextime*)malloc(sizeof(Flextime) * needed_structs)) == NULL)
	{ printf("\n Cannot allocate memory!!!"); }

	for(int flex=0;flex<needed_structs;flex++)
	{
		const char *day_no = strtok(structures[flex], seperate_digits);
		const char *hour = strtok(NULL, seperate_digits);
		const char *minute = strtok(NULL, seperate_digits);
		t[flex].day_number = atoi(day_no);
		t[flex].hour_part = atoi(hour);
		t[flex].minute_part = atoi(minute);


	}
		return t;
}

Flextime *flextime_fill(Flextime input[NO_OF_WEEKS][NO_OF_DAYS][TIME_STAMPLE])
{
	Flextime *t,*tp;
	int entries=0;
	if( (tp  = (Flextime*)malloc(sizeof(Flextime) * (NO_OF_WEEKS*NO_OF_DAYS*TIME_STAMPLE))) == NULL)
	{ printf("\n Cannot allocate memory!!!"); }
	t=tp;
	for(int weeks=0;weeks<NO_OF_WEEKS;weeks++)
	{
		for (int days = 0; days < NO_OF_DAYS; days++)
		{
			for(int time_s = 0; time_s < TIME_STAMPLE; time_s++)
			{
				t[entries++] = input[weeks][days][time_s];
			}
		}
	}
	return tp;
}

void present_work_weeks(Flextime *flx_ptr)
{
	char* employee_name = "EK";
	float work_pass=0, time_in=0, time_out=0, working_hours=0, working_times[NO_OF_DAYS*NO_OF_WEEKS]={};
	int work_pass_index=0,weeks=0;
	Flextime *ft, *w_ptr;

	printf("\n Name: %s EmployeeNO: 201 Period:201945-201946\n", employee_name);
	printf("\n Overview\tDay1\tDay2\tDay3\tDay4\tDay5\n");

	for (w_ptr = flx_ptr; weeks<NO_OF_WEEKS; w_ptr+=STAMPLES_PER_WEEK,weeks++)
	{
		printf("\n week %d\t\t",weeks+1);
		for (ft = flx_ptr+(STAMPLES_PER_WEEK*weeks); ft < &flx_ptr[STAMPLES_PER_WEEK*(weeks+1)]; ft+=TIME_STAMPLE)
		{
			for(int i=0; i<=In_OUT_STAMPLES; i+=In_OUT_STAMPLES)
			{
				time_in = (ft+i)->hour_part + ((((float)(ft+i)->minute_part)*PERCENT)/HOUR_MINUTES)/PERCENT;
				time_out = (ft+i+1)->hour_part + ((((float)(ft+i+1)->minute_part)*PERCENT)/HOUR_MINUTES)/PERCENT;
				work_pass = time_out - time_in;
				working_times[work_pass_index] += work_pass;
			}

			printf("%.2f\t",working_times[work_pass_index++]);
		}
	}

	for(int i=0;i<NO_OF_DAYS*NO_OF_WEEKS;i++)
	{
		working_hours += working_times[i];
		if(DEBUG)
			printf("DEBUG %.2f", working_times[i]);
	}

	printf("\n\n Period time: %.2f (%.2f)",working_hours,(working_hours-PERIOD_WORKING_HOURS));

	free(flx_ptr);
}

int count_stamples(char input_string[])
{
	int stamples=0,counter=0;
	do
	{
		if(input_string[counter++] == ';')
			{stamples++;}
	}while(counter != strlen(input_string));
	return stamples;
}
