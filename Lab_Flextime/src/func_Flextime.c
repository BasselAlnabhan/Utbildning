/*
 * func_Flextime.c
 *
 *  Created on: Nov 12, 2019
 *      Author: Bassel Alnabhan
 */
#include <stdlib.h>
#include "Flextime.h"
#include <stdio.h>


Flextime *flextime_fill(Flextime input[NO_OF_DAYS][TIME_STAMPLE], int number_of_weeks)
{
	Flextime *t,*tp;
	int entries=0;
	if( (tp  = (Flextime*)malloc(sizeof(Flextime) * (NO_OF_DAYS*TIME_STAMPLE))) == NULL)
	{ printf("\n Cannot allocate memory!!!"); }
	t=tp;

		for (int days = 0; days < NO_OF_DAYS; days++)
		{
			for(int times = 0; times < TIME_STAMPLE; times++)
			{
				t[entries++] = input[days][times];
			}
		}

	return tp;
}

void present_work_week(Flextime *flx_ptr)
{
	char* employee_name = "EK";
	float work_pass=0,time_in=0,time_out=0, working_times[NO_OF_DAYS]={},working_hours=0;
	int work_pass_index=0;
	Flextime *ft;
	printf("\n Name: %s EmployeeNO: 201 Period:201945\n", employee_name);
	printf("\n Overview\tDay1\tDay2\tDay3\tDay4\tDay5\n");
	for(int weeks = 1; weeks <= NO_OF_WEEKS; weeks++)
	{
		printf("\n week %d\t\t",weeks);
		for (ft = flx_ptr; ft < &flx_ptr[17]; ft+=4)
		{
			for(int i=0; i<=2; i+=2)
			{
				time_in = (ft+i)->hour_part + ((float)(ft+i)->minute_percentage/100);
				time_out = (ft+i+1)->hour_part + ((float)(ft+i+1)->minute_percentage/100);
				work_pass = time_out - time_in;
				working_times[work_pass_index] += work_pass;
			}

			printf("%.2f\t",working_times[work_pass_index++]);
		}
	}
	for(int i=0;i<NO_OF_DAYS;i++)
	{working_hours += working_times[i];}

	printf("\n\n Period time: %.2f (%.2f)",working_hours,WEEK_WORKING_HOURS-working_hours);
free(flx_ptr);
}
