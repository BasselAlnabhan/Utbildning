/*
 * Main.c
 *
 *  Created on: 16 okt. 2019
 *      Author: Bassel Alnabhan
 */
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include"Cipher.h"



int main()
{
	_Bool invalid_input_flag = false;
	char user_input[MAX_LENGTH+1] = {'\0'};
	int input_len, letter_count, choice;  								   	// test value1: Hi and 357 x! ZzOK?
	setbuf(stdout,NULL);												    // answer: ljfbAY319EOBJ
	do{
		setbuf(stdin,NULL);
		printf("\nEnter 1 to Encrypt, or 2 to decrypt: ");
		scanf("%d",&choice);
		// encode or decode
		switch (choice)
		{
		case 1:
		{
			puts("\nEnter your Message: ");          				 // test value2: 1DerBaw 52H lw7x
			setbuf(stdin,NULL);		     									// answer: ifY4XM92XBSF8
			// filter user input
			input_len = input_filter(user_input);
			// Letters evaluation
			letter_count = letters_evaluate(user_input);
			// digits modification
			digits_modify(user_input,letter_count);
			// space replacement
			space_replace(user_input);
			printf("\nYour encrypted message is: ");
		}
		break;
		case 2:
		{
			setbuf(stdin,NULL);
			printf("\nEnter your encrypted Message: ");
			input_len = decrypt(user_input);
			printf("\nYour original message is: ");
		}
		break;
		default:
		{
			puts("\nInvalid Choice");
			invalid_input_flag = true;
		}
		}
	}while(invalid_input_flag);
	// output
	output_present(user_input,input_len);
	return 0;
}
