/*
 * pointersMain.c
 *
 *  Created on: 21 okt. 2019
 *      Author: bassel Alnabhan
 */


#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include "pointers.h"



/* -------------------- Start of Main Program -------------------- */
int main()
{
	int *num, n ,k, min=0, max=0;
	float  mean=0;



	srand(time(0));

	setbuf(stdout, NULL);

	printf("\n Function parameters using pointers \n");

	do{
		printf("\n Enter number of random values(max 200): ");
		scanf(" %d", &n);
	}while(!(n>0 && n<200));

	if( (num  = (int*)malloc( sizeof( int ) * n )) == NULL)
	{ printf("\n Cannot allocate memory!!!"); }

	puts("\n Unsorted random values");
	for(k=0; k<n; k++){
		num[k]=rand()%100;
		printf("  %2d", num[k]);
	}
//	pnt_sort(num,n);
//	puts("\n\n Sorted random numbers");
//	print_out(num, n);

	pnt_mean_value(num,n,&mean);

	min_max_values(num,n,&min,&max);
	printf("\n\n The mean of all %d numbers is %3.2f\n The minimum value is %d"
			" and the maximum value is %d",n,mean,min,max);
	free(num);

	return 0;
}


