/*
 * func_Flextime.c
 *
 *  Created on: Nov 12, 2019
 *      Author: Bassel Alnabhan
 */
#include <stdlib.h>
#include "Flextime.h"
#include <stdio.h>


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
	{working_hours += working_times[i];}

	printf("\n\n Period time: %.2f (%.2f)",working_hours,(working_hours-PERIOD_WORKING_HOURS));

	free(flx_ptr);
}
