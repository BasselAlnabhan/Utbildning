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

extern _Bool DEBUG;

TimeStamp *get_stamples(char *input[NO_OF_WEEKS][NO_OF_DAYS][TIME_STAMPLE])
{
	TimeStamp *time_structs;
	int correction;
	//	int str_index=0;
	int needed_structs = NO_OF_DAYS*NO_OF_WEEKS*TIME_STAMPLE;
	//	char *structures [needed_structs];
	//	char seperate_string[] = {STRING_SEPERATOR, '\0'};
	char seperate_digits[] = {DIGIT_SEPERATOR, '\0'};

	//	if(DEBUG){printf("DEBUG counted structs %d\n",needed_structs);}

	//	structures[str_index++] = strtok(input_string, seperate_string);
	//
	//	for(int i=str_index;i<needed_structs;i++)
	//	{
	//		structures[i] = strtok(NULL,seperate_string);
	//	}
	int t_loop=0;
	if( (time_structs  = (TimeStamp*)malloc(sizeof(TimeStamp) * needed_structs)) == NULL)
	{ printf("\n Cannot allocate memory!!!"); exit(1);}

	for(int week=0;week<2;week++)
	{
		for (int day=0;day<5;day++)
		{

			for(int stamp=0;stamp<4;stamp++)
			{
				const char *day_no = strtok(input[week][day][stamp], seperate_digits);
				const char *hour = strtok(NULL, seperate_digits);
				const char *minute = strtok(NULL, seperate_digits);
				time_structs[t_loop].day_number = atoi(day_no);
				time_structs[t_loop].hour_part = atoi(hour);
				time_structs[t_loop].minute_part = atoi(minute);
				if(time_structs[t_loop].day_number == 0){
					if(t_loop%TIME_STAMPLE==0){
						if(t_loop%(NO_OF_DAYS*TIME_STAMPLE)==0){correction = 3;}
						else{correction = 1;}
					}
					else{
						time_structs[t_loop].day_number = time_structs[t_loop-1].day_number + correction;
						time_structs[t_loop].hour_part = FULL_TIME;
					}
				}
				t_loop++;
			}
		}
	}


	return time_structs;
	free(input);
}

void flextime_fill(TimeStamp *tp,TimeStamp input[NO_OF_WEEKS][NO_OF_DAYS][TIME_STAMPLE])
{
	TimeStamp *t;
	int entries=0;
	t=tp;
	for(int weeks=0;weeks<NO_OF_WEEKS;weeks++)
	{
		for (int days = 0; days < NO_OF_DAYS; days++)
		{
			for(int time_s = 0; time_s < TIME_STAMPLE; time_s++)
			{
				input[weeks][days][time_s] = t[entries++];
			}
		}
	}
}

WorkTime *convert2work_struct(TimeStamp *flx_ptr)
{
	float work_pass=0, time_in=0, time_out=0, working_hours=0;
	int work_pass_index=0,weeks=0;
	TimeStamp *ft, *w_ptr;
	WorkTime *wt;

	if( (wt  = (WorkTime*)malloc(sizeof(WorkTime) * (NO_OF_DAYS*NO_OF_WEEKS))) == NULL)
			{ printf("\n Cannot allocate memory!!!");}

	for (w_ptr = flx_ptr; weeks<NO_OF_WEEKS; w_ptr+=STAMPLES_PER_WEEK,weeks++)
	{
			for (ft = flx_ptr+(STAMPLES_PER_WEEK*weeks); ft < &flx_ptr[STAMPLES_PER_WEEK*(weeks+1)]; ft+=TIME_STAMPLE)
		{
			wt[work_pass_index].weekNum = weeks+1;
			wt[work_pass_index].time = 0.0f;                                 // a slight difference if not
			for(int i=0; i<=In_OUT_STAMPLES; i+=In_OUT_STAMPLES)
			{
				time_in = (ft+i)->hour_part + ((((float)(ft+i)->minute_part)*PERCENT)/HOUR_MINUTES)/PERCENT;
				time_out = (ft+i+1)->hour_part + ((((float)(ft+i+1)->minute_part)*PERCENT)/HOUR_MINUTES)/PERCENT;
				work_pass = time_out - time_in;
				wt[work_pass_index].time += work_pass;
			}

			wt[work_pass_index++].dayNum = ft->day_number;
		}
	}

	for(int output_counter=0;output_counter<NO_OF_DAYS*NO_OF_WEEKS;output_counter++)
	{working_hours += wt[output_counter].time;}

	free(flx_ptr);
	return wt;
}

void file_read(char f_path[], char *content[NO_OF_WEEKS][NO_OF_DAYS][TIME_STAMPLE])
{
	FILE *fptr;
	char reading_buf[MAX_LENGTH];
	char *cpnt;
	if ((fptr = fopen(f_path,"rb")) == NULL)
	{
		printf("Error! opening source file");
		exit(1);
	}
	int stamps=0;
	const char stamp_sep[]={STRING_SEPERATOR,'\0'};
	char *stample;
	for(int week=0;week<NO_OF_WEEKS;week++){
		for(int day=0;day<NO_OF_DAYS;day++){

			cpnt =fgets(reading_buf,MAX_LENGTH,fptr);
			if(strlen(cpnt)>STAMP_LENGTH){
				stamps=0;

				stample = strtok(reading_buf,stamp_sep);
				content[week][day][stamps]=(char*) malloc(strlen(stample)*sizeof(char));
				strcpy(content[week][day][stamps++],stample);

				for(stamps=1;stamps<TIME_STAMPLE;stamps++){
					if(strlen(stample)>STAMP_LENGTH-1)
					{stample = strtok(NULL,stamp_sep);}

					if(strlen(stample)>STAMP_LENGTH-1){
						content[week][day][stamps]= (char*)malloc(strlen(stample)*sizeof(char));
						strcpy(content[week][day][stamps],stample);
					}
					else {content[week][day][stamps]=0;}
				}
			}
			else{
				for(stamps=0;stamps<4;stamps++)
				{content[week][day][stamps]=0;}
			}
		}
	}
	free(cpnt);
	fclose (fptr);
}

char *output_write(WorkTime *output_structs,char file_name[])
{
	FILE *newfptr;


	float work_times[NO_OF_WEEKS*NO_OF_DAYS]={};
	char name2struct[MAX_LENGTH];
	const char file_type_remove[] = {'.','\0'};
	strtok(file_name,file_type_remove);
	strcpy(name2struct,file_name);
	strcat(name2struct,"DONE.dat");
	if ((newfptr = fopen(name2struct,"wb")) == NULL){
		printf("Error! opening file");
		exit(1);
	}

	for(int i=0;i<NO_OF_WEEKS;i++)
	{
		for(int j=0;j<NO_OF_DAYS;j++)
		{
			work_times[j+(i*NO_OF_DAYS)] = output_structs[j+(i*NO_OF_DAYS)].time;
			if(DEBUG)
			{float x=output_structs[j+(i*NO_OF_DAYS)].time; printf("DEBUG values in the structs %.2f\t values in the float array %.2f\n",x,work_times[j+(i*NO_OF_DAYS)]);}
		}
	}
	fwrite(work_times,sizeof(float),10,newfptr);
	fclose(newfptr);
	return file_name;
}

void output_file_present(char *fname)
{
	FILE *dat_file;
	Employee my_employee;
	float total_work_time[10]={}, current_work_hours, total_working_hours=0;
	int row=0;
	char name2struct[MAX_LENGTH];
	strcpy(name2struct,fname);
	my_employee = get_employee_info(name2struct);
	if(DEBUG){printf("\nDEBUG %s",fname);}
	strcat(fname,"DONE.dat");
	if ((dat_file = fopen(fname,"rb")) == NULL)
	{
		printf("Error! opening result file");
		exit(1);
	}
	while((fread(&current_work_hours,sizeof(float), 1,dat_file))==1)
	{
		total_work_time[row++] = current_work_hours;
	}
	printf("\n Name:%s \tEmployeeNO:%d  Period:%d\n", my_employee.name,my_employee.emp_no,my_employee.period);
	printf("\n Overview\tDay1\tDay2\tDay3\tDay4\tDay5\n");

	for(int weeks=0;weeks<NO_OF_WEEKS;weeks++)
	{
		printf("\n week %d\t\t",weeks+1);
		for (int days = 0; days < NO_OF_DAYS; days++)
		{
			printf("%.2f\t",total_work_time[days+(weeks*NO_OF_DAYS)]);
		}
	}
	for(int i=0;i<NO_OF_DAYS*NO_OF_WEEKS;i++)
	{
		total_working_hours += total_work_time[i];
		if(DEBUG)
			printf("DEBUG %.2f", total_work_time[i]);
	}

	printf("\n\n Period time: %.2f (%.2f)",total_working_hours,(total_working_hours-PERIOD_WORKING_HOURS));
	fclose(dat_file);
}

Employee get_employee_info(char *file_name)
{
	Employee emp={};

	const char info_sep[] = {'_','\0'};
	emp.name = strtok(file_name,info_sep);
	emp.emp_no = atoi(strtok(NULL,info_sep));
	emp.period = atoi(strtok(NULL,info_sep));
	return emp;
}
