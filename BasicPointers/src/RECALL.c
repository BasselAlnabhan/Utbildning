/* >>>>>>>>>>>>>>>>>>>>>>>>>>>>  RECALL.C  <<<<<<<<<<<<<<<<<<<<<<<<
 Subject		: Memory re-allocation
 Programmer		: Kjell H Carlsson
 Last update	: 2015-08-10
 ================================================================= */
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
	int n, k;
	int *digitpnt, *ip;

	srand(time(0));

	setbuf(stdout, NULL);

	// allocate and reset memory locations to zero
	if( (digitpnt=(int*)calloc(20, sizeof(int)) ) != NULL) {
		printf("\n Reset memory for 20 random digits \n");
		for(ip=digitpnt, k=1; ip<digitpnt+20; ip++, k++){
			printf(" %d", *ip);
		}

		// get needed memory size via user input
		do{
			printf("\n\n Enter number of random digits (max 20): "); fflush(stdout);
			scanf(" %d", &n);
		}while(!(n>0 && n<=20));

		// reallocate dynamic memory
		digitpnt=(int *)realloc(digitpnt, sizeof(int)*n);
		printf("\n Random digits \n");
		for(ip=digitpnt, k=1; ip<digitpnt+n; ip++, k++){
			*ip=rand()%10;
			printf(" %d", *ip);
		}
		// free allocated memory
		free(digitpnt);
	}
	else
		puts("\n Cannot allocate memory!!!");

	return 0;
}
