/*
 * Cipher.h
 *
 *  Created on: 16 okt. 2019
 *      Author: bassel Alnabhan
 */

#ifndef CIPHER_H_
#define CIPHER_H_
#define MAX_LENGTH 25
#define S_2_next_C 31
#define ASCII_NINE 57
#define ASCII_ZERO 48
#define ASCII_a 97

/*used to filter the user input
 * input - a char array to hold the filtered input
 * output - an integer of how many char in the array*/
int input_filter(char input[]);

/*used to replace Lower case letters by the next CAPITAL letter in the alphabet
 * input - char array after it has been filtered
 * output - an integer of how many letters is in the input*/
int letters_evaluate(char input[]);

/*used to replace the digit by the lower part of (number of letters in the text + entered digit)
 * input - char array
 * output - none*/
void digits_modify(char input[], int letters);

/*used to replace Space characters by the corresponding lower case letter representing
 the order of the space in the original text
 * input - char array
 * output - none*/
void space_replace(char input[]);

/*used to print out the encoded text
 * input - char array
 * output - none*/
void output_present(char input[], int len);

/*used to decrypt an encrypted string
 * input - char array
 * output - an integer of how many char in the array*/
int decrypt(char input[]);

#endif /* CIPHER_H_ */
