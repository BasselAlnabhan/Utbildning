/* >>>>>>>>>>>>>>>>>>>>>>>>>>>>  STRUCTMX.C  <<<<<<<<<<<<<<<<<<<<<<<<
 Subject        : Memory allocation for structs
 Programmer     : Kjell H Carlsson
 Last update	: 2015-08-10
 ================================================================= */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// struct definition
struct phonelist
{
   int area;
   long int phone;
   char name[10];
};


int main()
{
	struct phonelist *spnt; // declare a struct pointer

	setbuf(stdout, NULL);

	// Allocate dynamic memory for the struct pointer
	spnt=(struct phonelist*) malloc(sizeof(struct phonelist));

	printf("\n Dynamic memory allocation for a struct \n");
	// Defining constant input to structure 'phonelist'
	spnt->area=520;
	spnt->phone=55987123;
	strcpy(spnt->name, "Mr G");

	printf("\n Dial %ld to call %s who lives in area %04d ",\
			spnt->phone, spnt->name, spnt->area);

	free(spnt);                   // free allocated memory

return 0;
}
