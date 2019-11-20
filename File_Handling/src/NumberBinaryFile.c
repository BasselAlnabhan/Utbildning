/*
 *  NumberBinaryFile.c
 *  Created on: 5 Nov 2019
 *  Author: Kjell H Carlsson
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/* --------------------- Start of Main Program ------------------- */
int main()
{
FILE *fpnt;
int k, n, inum, rands[10], frands[10];

	srand(time(0));

	setbuf(stdout, NULL);

	printf("\n New random numbers --------> ");

	/* create 10 random numbers */
	for(k=0; k<10; k++){
		rands[k]= rand()%100;
		printf(" %2d", rands[k]);
	}

	/* write array of 10 numbers to file */
	fpnt=fopen("RandNum.dat", "wb");
	fwrite(rands, sizeof(int), 10, fpnt);
	fclose(fpnt);
	getchar();

	if( (fpnt=fopen("RandNum.dat", "rb")) == NULL){
		printf("\n Cannot read the file!");
		exit(1);
	}

	/* read numbers from file one by one */
	k=0;
	while( fread(&inum, sizeof(int), 1, fpnt)==1){
		frands[k++]=inum;
	}
	fclose(fpnt);

	/* print out file data */
	printf("\n\n Random numbers from file ---> ");
	for(n=0; n<k; n++){
		printf(" %2d", frands[n]);
	}

return 0;
}

