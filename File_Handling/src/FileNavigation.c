/*
 * FileNavigation.c
 *
 *  Created on: 5 Nov 2019
 *  Author: Kjell H Carlsson
 */

#include <stdio.h>
#include <stdlib.h>

int main()
{
int k, rands[10], inum, n=0;
long int record, pospnt;
FILE *fpnt;
char answer, fmode;

	setbuf(stdout, NULL);

  printf("\n Navigation in a binary file");

  if ((fpnt = fopen("RandNum.dat","r+b"))==NULL){
		printf("\n Cannot read the file!");
		exit(1);
  }

  // read random numbers from file
  while(fread(&rands[n], sizeof(int), 1, fpnt)==1) n++;

  // print out the random numbers
  for(k=0; k<n; k++){
	  printf(" %2d", rands[k]);
  }
  puts("");

  // user dialouge menu input
  do{
	  printf("\n Enter type of file handling ");
	  do{
			fflush(stdin);
			printf("\n 0 - from start, 1 - random, 2 - from end: ");
			fmode = getchar();
	  }while(!(fmode>='0' && fmode<='2'));

	  switch (fmode){
		// at start of file
		case '0':	fseek(fpnt, 0L, 0);			break;
		// at end of file
		case '2':	fseek(fpnt,-1L*sizeof(int), 2);	break;
		// at user input
		case '1':
			do{
				printf("\n Enter record number (1-%d) : ", n);
				scanf(" %ld", &record);
			}while(!(record>=1 && record<=n));

			rewind(fpnt);
			fseek(fpnt,(record-1)*sizeof(int),1);	break;
	  }

	  // read data at chosen position
	  fread(&inum, sizeof(int), 1, fpnt);

	  // get position in file
	  pospnt = ftell(fpnt)/sizeof(int);
	  printf("\n Random number from file %ld - %d ", pospnt, inum);

	  do{
		printf("\n More reading (Y/N)? ");
		fflush(stdin);
		answer = getchar();
	  }while(!(answer=='Y' || answer=='y' || answer=='N' || answer=='n'));

  }while(answer=='Y'|| answer=='y');

  // close file
  fclose(fpnt);
  printf("\n End of file handling! ");

return 0;
}
