/*
 * pointers.h
 *
 *  Created on: 21 okt. 2019
 *      Author: bassel Alnabhan
 */

#ifndef POINTERS_H_
#define POINTERS_H_

/*used to sort an integer array indexes in an ascending order
 * input - an array of integers, an integer of how many indexes is in the array
 * output - none*/
void pnt_sort(int ifield[], int n);


/*used to calculate the mean of an integer array indexes
 * input - an array of integers, an integer of how many indexes is in the array
 * and a float pointer to save the mean value
 * output - none*/
void pnt_mean_value(int ifield[],int n,float *mean);

/*used to check an integer array indexes to find minimum and maximum values
 * input - an array of integers, an integer of how many indexes is in the array
 * and two pointers to save the min and max values
 * output - none*/
void min_max_values(int ifield[], int n, int *min, int *max);

/*used to print out the result
 * input - a pointer refers to an integer array and an integer
 *  of how many indexes is in the array
 *  output - none*/
void print_out(int *numpnt, int n);

#endif /* POINTERS_H_ */
