/*
 * functions.c
 *
 *  Created on: 6 nov. 2019
 *      Author: bassel Alnabhan
 */
#include <stdio.h>
#include <stdlib.h>

#include "DS_Xercise.h"

#define ALPHABET 26

char* generate_string(int letters_count)
{
	int k;
	char *letters;



	if( (letters  = (char*)malloc(sizeof(char) * letters_count)) == NULL)
	{ printf("\n Cannot allocate memory!!!"); }

	for(k=0; k<letters_count; k++)
	{
			letters[k]=rand()%ALPHABET +'A';
	}
	letters[k++] = '\0';
	printf("\n The Generated string: %s", letters);
	return letters;
}


char find_lowest_ascii(char *first_letter, int letters_count)
{
	char cmpr, *ip=first_letter;
	cmpr = *first_letter;
	do{
		if(cmpr>*ip)
			cmpr = *ip;
		ip++;
	}while(*ip!= '\0');
	return cmpr;
}
