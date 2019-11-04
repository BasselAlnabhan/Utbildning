/*
 * Func.c
 *
 *  Created on: 16 okt. 2019
 *      Author: bassel Alnabhan
 */
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include<stdbool.h>
#include"Cipher.h"

int input_filter(char input[])
{
	int filter_index=0;
	char temp;
	do
	{
		temp = getchar();
		if(isdigit(temp) || islower(temp) || temp == ' ')
		{
			input[filter_index++] = temp;
		}
	}while(filter_index<=MAX_LENGTH && temp != '\n');
	input[filter_index] = '\0';
	return filter_index;
}

int letters_evaluate(char input[])
{
	int letter_count = 0, letter_index=0;
	while( input[letter_index]!='\0')
	{
		if(isalpha(input[letter_index])){
			letter_count++;
			if(input[letter_index]== 'z')
				input[letter_index]='A';
			else
				input[letter_index] = toupper(input[letter_index])+1;    //	input[letter_index] -= S_2_next_C;
		}
		letter_index++;
	}
	return letter_count;
}
//kgOBICBOMB144MFTTBC    test for decode. result is bassel 007 alnabhan
void digits_modify(char input[], int letters)
{
	int digit_index=0;
	while( input[digit_index]!='\0')
	{
		if(isdigit(input[digit_index]))
		{

			input[digit_index] += letters;
			if(input[digit_index]>'9')
			{
				input[digit_index]%=('9'+1);
				input[digit_index]%=10;
				input[digit_index]+='0';
			}
		}
		digit_index++;
	}
}

void space_replace(char input[])
{

	int space_index=0, space_counter=0;
	while( input[space_index]!='\0')
	{
		if(input[space_index] == ' ')
		{
			input[space_index] = space_index + 'a';
			space_counter++;
		}
		space_index++;
	}
	char lower_case;
	for (int lower_index =0; lower_index<space_index-space_counter; lower_index++)
	{
		if(islower(input[lower_index]))
		{
			for(int push2last=lower_index; push2last<space_index-1;push2last++)
			{
				lower_case = input[push2last+1];
				input[push2last+1]=input[push2last];
				input[push2last]=lower_case;
			}

		}
	}
}

int decrypt(char input[])
{
	char temp, index_changer;
	int letter_count=0,lower_counter=0;
	int de_input_index=0;
	int push2last;
	int space_pos;
	// take the input ----------------------------------------------------------------------------------------
	do
	{
		temp = getchar();
		if(isdigit(temp) || islower(temp) || isupper(temp))
		{
			input[de_input_index++] = temp;
			if(islower(temp))
				lower_counter++;
		}
	}while(de_input_index<=MAX_LENGTH && temp != '\n');
	input[de_input_index] = '\0';

		// change lower index ---------------------------------------------------------------------------------------
		for(int i=lower_counter-1;i>=0;i--)
		{
					space_pos=(input[i]%('a'-1));
				for(push2last=i; push2last<(de_input_index-space_pos);push2last++)
				{
					index_changer = input[push2last+1];
					input[push2last+1]=input[push2last];
					input[push2last]=index_changer;
				}
		}
		// change lower to space -------------------------------------------------------------------------
		for(int i=0;i<=de_input_index;i++)
		{

			if(islower(input[i]))
				input[i]=' ';
		}

	//change capital to lower -----------------------------------------------------------------------
	for(int i=0;i<=de_input_index; i++){
		if(isupper(input[i])){
			if(input[i] == 'A'){
				input[i] = 'z';
				letter_count++;
			}
			else{
				input[i] = tolower(input[i])-1;
				letter_count++;
			}
		}
	}
	// modify digits
	for(int i=0;i<=de_input_index; i++){
		if(isdigit(input[i])){
			input[i] -= letter_count;
			while(input[i]<'0'){
				input[i]='9'-('0'-input[i])+1 ;
			}
		}
	}

	return de_input_index;

}

void output_present(char input[], int len)
{
	for(int print_counter=len;print_counter>=0;print_counter--)
	{
		printf("%c", input[print_counter]);
	}
}
