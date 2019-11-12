/*
 * main.c
 *
 *  Created on: 6 nov. 2019
 *      Author: bassel Alnabhan
 */
#include<stdio.h>
#include<stdlib.h>
#include <time.h>
#include"DS_Xercise.h"
#define MAX_LENGTH 50

int main()
{
	char *alphabet, lowest_ascii;
	int letters_count;
	setbuf(stdout, NULL);
	srand(time(0));
	do
	{
		printf("\n please enter how many capital letters do your want me to generate? [max: %d]: ", MAX_LENGTH);
		scanf("%d",&letters_count);

	}while(!(letters_count>0 && letters_count<=MAX_LENGTH));

	alphabet = generate_string(letters_count);
	lowest_ascii = find_lowest_ascii(alphabet,letters_count);
	printf("\n\n The character that holds the lowest ASCII code: %c", lowest_ascii);

	free(alphabet);


	return 0;
}
