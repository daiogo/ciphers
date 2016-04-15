/** 
	Character frequency analyzer in a text
	Author: Diogo G. Garcia de Freitas
**/

#include <stdio.h>

#define ASCII_UPPERCASE_A 65
#define ASCII_UPPERCASE_Z 90
#define ASCII_LOWERCASE_A 97
#define ASCII_LOWERCASE_Z 122
#define ASCII_ZERO 48
#define ASCII_NINE 57
#define TOTAL_CHARACTERS 62
#define ALPHABET_SIZE 26
#define NUMBERS_SIZE 10

int main()
{
	char characters[TOTAL_CHARACTERS];
	float frequency[TOTAL_CHARACTERS] = {00.00};
	int total_chars_in_stdin = 0;
	char cursor;
	int i;

	/** Generate characters array to easily display character frequency **/
	for (i = 0; i < ALPHABET_SIZE ; i++)
		characters[i] = ASCII_UPPERCASE_A + i;

	for (i = 0; i < ALPHABET_SIZE ; i++)
		characters[i + ALPHABET_SIZE] = ASCII_LOWERCASE_A + i;

	for (i = 0; i < NUMBERS_SIZE ; i++)
		characters[i + (2*ALPHABET_SIZE)] = ASCII_ZERO + i;

	/** Reads from stdin and counts frequency in the frequency array **/
	while ((cursor = fgetc(stdin)) != EOF)
	{
		if ((cursor >= ASCII_UPPERCASE_A) && (cursor <= ASCII_UPPERCASE_Z))
		{
			frequency[cursor - ASCII_UPPERCASE_A]++;
			total_chars_in_stdin++;
		}
		else if ((cursor >= ASCII_LOWERCASE_A) && (cursor <= ASCII_LOWERCASE_Z))
		{
			frequency[cursor - ASCII_LOWERCASE_A + ALPHABET_SIZE]++;
			total_chars_in_stdin++;
		}
		else if ((cursor >= ASCII_ZERO) && (cursor <= ASCII_NINE))
		{
			frequency[cursor - ASCII_ZERO + (2*ALPHABET_SIZE)]++;
			total_chars_in_stdin++;
		}
	}

	/** Prints percentual frequency of all letters **/
	for (i = 0 ; i < TOTAL_CHARACTERS ; i++)
		printf("%c = %.2f\n", characters[i], 100*(frequency[i]/total_chars_in_stdin));

}
