/*
 * pointersFunc.c
 *
 *  Created on: 21 okt. 2019
 *      Author: bassel Alnabhan
 */

#include<stdio.h>
#include"pointers.h"
/********************** Function pnt_sort **************************
	Sort an array of n integers by using pointers
	input  - unsorted array, number of integers
	output - none
  -----------------------------------------------------------------*/

void pnt_sort(int ifield[], int n)
{
int *ip, *jp, *min, temp;

	for (ip=ifield; ip<&ifield[n-1]; ip++){
		min=ip;

		for (jp=ip+1; jp<&ifield[n]; jp++){
			if (*min > *jp )
				min=jp;
		}
		temp=*ip;
		*ip=*min;
		*min=temp;
	}
}

void pnt_mean_value(int ifield[],int n, float *mean_value)
{
	int sum=0, *m;
	for(m=ifield; m<&ifield[n];m++)
	{
		sum+=*m;
	}
	*mean_value = (float)sum/n;
}

void min_max_values(int ifield[], int n, int *min, int *max)
{
	int *m;

	*min=*ifield;
	*max=*ifield;
	for (m=ifield+1; m<&ifield[n]; m++){

		if ( *min > *m )
			*min=*m;
		else
			if(*max < *m)
			*max=*m;
	}
}

void print_out(int *numpnt, int n)
{
int *i;
	 for (i=numpnt; i<numpnt+n; i++){
		printf(" %3d", *i);
	 }
}
