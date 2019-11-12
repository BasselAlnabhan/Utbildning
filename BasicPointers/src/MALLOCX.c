/* >>>>>>>>>>>>>>>>>>>>>>>>>>>>  MALLOCX.C  <<<<<<<<<<<<<<<<<<<<<<<<
 Subject        : Memory allocation
 Programmer     : Kjell H Carlsson
 Last update	: 2015-08-10
 ================================================================= */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
	int n;
	int *digitpnt, *ip;

	srand(time(0));

	setbuf(stdout, NULL);

	printf("\n Dynamic memory allocation of n integers");

	do{
		printf("\n Enter number of random digits (max 200): ");  fflush(stdout);
		scanf(" %d", &n);
	}while(!(n>0 && n<=200));

	// allocate dynamic memory if possible
	if ((digitpnt=(int *)malloc(sizeof(int)*n)) != NULL){

		printf("\n Random digits \n");
		for(ip=digitpnt; ip<digitpnt+n; ip++){
			*ip=rand()%10;
			printf(" %d", *ip);
		}

		free(digitpnt); // free allocated memory
	}
	else
		puts("\n Cannot allocate memory!!!");

	return 0;
}
