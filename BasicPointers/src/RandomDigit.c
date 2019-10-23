/*
 *  RandomDigit.c
 *  Created on: 21 Oct 2019
 *  Author: Kjell Carlsson
 */

#include <stdio.h>
#include <time.h>
#include <stdlib.h>

int main()
{
int digit[5], n, k;
int *ip;

srand(time(0));

	setbuf(stdout, NULL);

	printf("\n Using pointers to populate an array \n");

	printf("\n Enter number of random digits(max 5): ");
	scanf(" %d", &n);

	for(ip=digit, k=1; ip<&digit[n]; ip++, k++){
		*ip=rand()%10;
		printf("\n Random digit %d = %d ", k, *ip);
	}

return 0;
}

