#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int cont = 1;

char* ReadFile(char *filename)
{
   char *buffer = NULL;
   int string_size, read_size;
   FILE *handler = fopen(filename, "r");
   

   if (handler)
   {
       // Seek the last byte of the file
       fseek(handler, 0, SEEK_END);
       // Offset from the first to the last byte, or in other words, filesize
       string_size = ftell(handler);
       // go back to the start of the file
       rewind(handler);

       // Allocate a string that can hold it all
       buffer = (char*) malloc(sizeof(char) * (string_size + 1) );

       // Read it all in one operation
       read_size = fread(buffer, sizeof(char), string_size, handler);

       // fread doesn't set it so put a \0 in the last position
       // and buffer is now officially a string
       buffer[string_size] = '\0';

       if (string_size != read_size)
       {
           // Something went wrong, throw away the memory and set
           // the buffer to NULL
           free(buffer);
           buffer = NULL;
       }

       // Always remember to close the file.
       fclose(handler);
    }

    return buffer;
}

void StartPage()
{
	char *string = ReadFile("./db/StartScreen.txt");
	//char *string = ReadFile("Start.txt");
    if (string)
    {
        puts(string);
        free(string);
    }
    //char enterkey[1];
    //scanf("%s", enterkey);
    getchar();
    system("clear");
    //printf("> ");
}

void getCommand()
{
	printf("> ");
	char input[4];
	scanf("%s", input);
	if(strncmp(input,"IF",4) == 0 || strncmp(input,"if",4) == 0)
	{
		system("clear");
		char *string = ReadFile("./db/IF.txt");
		if (string)
		{
			puts(string);
			free(string);
		}
		//getCommand();
	}
	else if(strncmp(input,"EXIT",4) == 0 || strncmp(input,"exit",4) == 0)
	{
		printf("Thank you for using the TARDIS INFORMATION SYSTEM");
		cont = 0;
	}
}

int main()
{
    StartPage();
    
    while(cont == 1)
    {
		getCommand();
	}
	
	//getCommand();

    return 0;
}
