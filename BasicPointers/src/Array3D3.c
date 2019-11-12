/*
 *  Array3D3.c
 *  Created on: 11 Nov 2019
 *  Author: Kjell Carlsson
 */


#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// define struct holding 3D info
typedef struct{
	int blocks;
	int rows;
	int cols;
}ArrayInfo;

// function prototypes
void standard_sort(int list[], int n);
void show_block(int *block, ArrayInfo dimlist);
void set_array(int *array, ArrayInfo dimlist);

/* --------------------- Start of Main Program ------------------------ */
int main()
{
ArrayInfo diminfo = {};
int *apnt, arraysize;
int k, start;

srand(42);

	setbuf(stdout, NULL);

	// get user input of specific dimension size
	do{
		printf("\n Input size of dimension 1 (cols - max 6)   : ");
		scanf(" %d", &diminfo.cols);
	}while(!(diminfo.cols>0 && diminfo.cols<=6));

	do{
		printf(" Input size of dimension 2 (rows - max 6)   : ");
		scanf(" %d", &diminfo.rows);
	}while(!(diminfo.rows>0 && diminfo.rows<=6));

	do{
		printf(" Input size of dimension 3 (blocks - max 4) : ");
		scanf(" %d", &diminfo.blocks);
	}while(!(diminfo.blocks >0 && diminfo.blocks <=4));

	// dynamic allocation of array on user request
	arraysize=diminfo.blocks*diminfo.rows*diminfo.cols;
	if( (apnt=(int *)malloc(sizeof(int)*arraysize)) == NULL){
		printf("\n Cannot allocate memory !!!");
		exit(1);
	}

	printf("\n Current dimension of array : %dx%dx%d",
			 diminfo.blocks, diminfo.rows, diminfo.cols);
	// set random numbers to all positions in a user defined 3D array
	set_array(apnt, diminfo);

	// show blocks using dimension info for correct array handling
	start=0;

	for(k=0; k<diminfo.blocks; k++){
			printf("\n Block %d unsorted", k+1);
			show_block(apnt+start, diminfo);

			// call general sort routine
			standard_sort(apnt+start, diminfo.rows*diminfo.cols);
			printf("\n Block %d sorted", k+1);
			show_block(apnt+start, diminfo);

			// calculate offset to next block in array
			start+=diminfo.rows*diminfo.cols;
		}
		// free allocated memory
		free(apnt);

	printf("\n -------------------- End of program ---------------------");

	return 0;
}


/* ---------------------- function standard_sort --------------------
	sorts a list of n integers in rising order. In this function
	pointers are used to handle entire array, no dim-parameters needed
	input - list to sort, list length		output - none
	---------------------------------------------------------------- */
void standard_sort(int list[], int n)
{
int *kp, *ip, temp;

	for(kp=list; kp<list+n-1; kp++){
		for(ip=kp+1; ip<list+n; ip++){
			if(*kp>*ip){
				temp=*kp;
				*kp=*ip;
				*ip=temp;
			}
		}
	}
}

/* ---------------------- function show_ block -------------------------
	print out contents of a block on screen in a box shaped area via
	use pointer handling to a list of dimensions set in dimlist.
	input  - pointer to int array, struct for dimension info,
	output - none
	---------------------------------------------------------------- */
void show_block(int *ppnt, ArrayInfo dimlist)
{
int x,y;

	// show block by block via pointer handling and dimension info
	for(y=0; y<dimlist.rows; y++){
		printf("\n");
		for(x=0; x<dimlist.cols; x++){
			printf("%3d", *ppnt++);
		}
	}
	printf("\n");
}

/* ---------------------- function set_array ------------------------
	set array values via call of random function add 10 for each block
	use pointer handling to a 1-dimension list.
	input  - pointers to int array, struct for dimension info
	output - none
	---------------------------------------------------------------- */
void set_array(int *array, ArrayInfo dimlist)
{
int k, i, j;

	for(k=0; k<dimlist. blocks; k++){
		for(i=0; i<dimlist.rows; i++){
			for(j=0; j<dimlist.cols; j++){
				*array++ = rand()%10+(k+1)*10;
			}
		}
	}
}
