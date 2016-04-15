/** 
	Caesar encoder and decoder
	(Shifts in the following array of characters [A-Z,a-z,0-9])
	Author: Diogo G. Garcia de Freitas
**/

#include <stdio.h>

#define ASCII_UPPERCASE_A 65
#define ASCII_LOWERCASE_A 97
#define ASCII_ZERO 48
#define TOTAL_CHARACTERS 62
#define ALPHABET_SIZE 26
#define NUMBERS_SIZE 10
#define NOT_FOUND 404

char characters[TOTAL_CHARACTERS];

int get_cursor_index(char cursor)
{
	int j;
	for (j = 0; j < TOTAL_CHARACTERS; j++)
	{
		if (cursor == characters[j])
			return j;
	}
	return NOT_FOUND;
}

void encode(int key)
{
	int index;
	char cursor;

	while ((cursor = fgetc(stdin)) != EOF)
	{
		index = get_cursor_index(cursor);

		/** When cursor is a non-letter or non-number character **/
		if (index == NOT_FOUND)
			printf("%c", cursor);

		/** When cursor is found in the characters array and index + key is greater than array size **/
		else if (index + key >= TOTAL_CHARACTERS)
			printf("%c", characters[index + key - TOTAL_CHARACTERS]);

		/** When cursor is found in the characters array and index + key is within the array size **/
		else
			printf("%c", characters[index + key]);
	}
}

void decode(int key)
{
	int index;
	char cursor;

	while ((cursor = fgetc(stdin)) != EOF)
	{
		index = get_cursor_index(cursor);

		/** When cursor is a non-letter or non-number character **/
		if (index == NOT_FOUND)
			printf("%c", cursor);

		/** When cursor is found in the characters array and index - key is less than zero (not indexable) **/
		else if (index - key < 0)
			printf("%c", characters[index - key + TOTAL_CHARACTERS]);

		/** When cursor is found in the characters array and index - key is within the array size **/
		else
			printf("%c", characters[index - key]);
	}
}

int main(int argc, char* argv[])
{
	/** Create and initialize variables with arguments passed as strings to argv **/
	int key = atoi(argv[3]);			//Converts the third argument (key) to an integer
	char option = argv[1][1];			//Gets the option flag (encode/decode)

	/** Generate characters array to easily jump from uppercase to lowercase letters and from
		lowercase letters to numbers **/
	int i;
	for (i = 0; i < ALPHABET_SIZE ; i++)
		characters[i] = ASCII_UPPERCASE_A + i;

	for (i = 0; i < ALPHABET_SIZE ; i++)
		characters[i + ALPHABET_SIZE] = ASCII_LOWERCASE_A + i;

	for (i = 0; i < NUMBERS_SIZE ; i++)
		characters[i + (2*ALPHABET_SIZE)] = ASCII_ZERO + i;

	/** Eliminate exceeding rotations on the key **/
	while (key > TOTAL_CHARACTERS)
		key -= TOTAL_CHARACTERS;

	/** Determine if will perform encodeion or decodeion **/
	switch (option)
	{
		case 'e':
			encode(key);
			break;
		case 'd':
			decode(key);
			break;
		default:
			printf("ERROR | Wrong option flag | Use either the -d or the -e flag.\n");
			break;
	}

	return 42;
}
