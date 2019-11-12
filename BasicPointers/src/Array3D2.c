/*
 *  Array3D2.c
 *  Created on: 11 Nov 2019
 *  Author: Kjell Carlsson
 */

#include <stdio.h>
#include <stdlib.h>

#define DIM1 6 // low index
#define DIM2 2 // mid index
#define DIM3 3 // high index

// function prototypes
void standard_sort(int *list, int n);
void show_plane(int plane[DIM2][DIM1]);
/* --------------------- Start of Main Program ------------------------ */
int main()
{
	// declare and init array of size [3][2][6]
	int array[DIM3][DIM2][DIM1]={
			{{17,15,13,19,11,18},{14,16,12,10,10,10}},
			{{27,25,23,26,22,24},{29,21,28,20,20,20}},
			{{37,35,33,31,32,39},{36,34,38,30,30,30}} };
	int k, i;

	setbuf(stdout, NULL);

	printf("\n Current dimension of array: %dx%dx%d\n", DIM3, DIM2, DIM1);

	// show current contents of a 3D array plane by plane unsorted/sorted
	for(k=0; k<DIM3; k++){
		// handle 1 plane - use upper dimension index only
		printf("\n Block no %d unsorted", (k+1));
		show_plane(array[k]);

		// sort 1 row - use upper and mid dimensions to pick out a row
		for(i=0; i<DIM2; i++){
			standard_sort(array[k][i], DIM1);
		}
		// handle 1 plane - use upper dimension index only
		printf("\n rows sorted ");
		show_plane(array[k]);

		// sort 1 plane - use upper dimension to pick out a plane
		standard_sort(array[k], DIM2*DIM1);
		// handle 1 plane - use upper dimension index only
		printf("\n fully sorted");
		show_plane(array[k]);

		getchar();
	}

	printf("\n\n -------------------- End of program ---------------------\n");

	return 0;
}

/* ------------------------ function show_plane --------------------
print out contents of a plane on screen in a rectangular area via
use of parameter plane[][], and macros for plane dimensions.
input - 2-dim plane
output - none
---------------------------------------------------------------- */
void show_plane(int plane[DIM2][DIM1])
{
	int x,y;
	for(y=0; y<DIM2; y++){
		printf("\n");
		for(x=0; x<DIM1; x++){
			printf("%3d", plane[y][x]);
		}
	}
	printf("\n");
}

/* ---------------------- function standard_sort --------------------
sorts a list of n integers in rising order. Pointers are used to
handle entire array, no dimension parameters needed.
input - list to sort, list length output - none
---------------------------------------------------------------- */
void standard_sort(int *list, int n)
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
