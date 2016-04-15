/** 
	Vernam encoder and decoder
	Author: Diogo G. Garcia de Freitas
**/

#include <stdio.h>

int main(int argc, char* argv[])
{
	char option = argv[1][1];				//Gets the option flag (encode/decode)
    FILE *file = fopen(argv[2], "r");		//argv[2] is the file containing the key

    if (!file)								//If file == NULL, display error message
    {
        printf("ERROR | Key file could not be opened.\n");
    }
    else
    {
        char file_cursor, stdin_cursor;

        while (1)
        {
			stdin_cursor = fgetc(stdin);
			file_cursor = fgetc(file);

			if (stdin_cursor == EOF)
				break;
			else if (file_cursor == EOF)
				break;
			else
				printf("%c", stdin_cursor ^ file_cursor);
        }

        fclose(file);
	}

	return 42;
}
