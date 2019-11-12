/*
 *  Array3D1.c
 *  Created on: 11 Nov 2019
 *  Author: Kjell Carlsson
 */

#include <stdio.h>
#include <stdlib.h>

#define DIM1 6 // low index
#define DIM2 2 // mid index
#define DIM3 3 // high index

// function prototypes
void show_plane(int plane[DIM2][DIM1]);

/* --------------------- Start of Main Program ------------------------ */
int main()
{
// declare and init array of size [3][2][6]
int array[DIM3][DIM2][DIM1]={ 	{ {17,15,13,19,11,18},{14,16,12,10,10,10} },
								{ {27,25,23,26,22,24},{29,21,28,20,20,20} },
								{ {37,35,33,31,32,39},{36,34,38,30,30,30} }
							};
int k;

	setbuf(stdout, NULL);

	printf("\n Current dimension of array : %dx%dx%d", DIM3, DIM2, DIM1);

	// show current contents of a 3D array plane by plane
	for(k=0; k<DIM3; k++){
		// handle 1 plane - use upper dimension index only
		printf("\n");
		show_plane(array[k]);
	}
	printf("\n\n ------------------ End of program -----------------\n");

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
	int x, y;
	// show contents of a plane
	for(y=0; y<DIM2; y++){
		printf("\n");
		for(x=0; x<DIM1; x++){
			printf("%3d", plane[y][x]);
		}
	}
}
