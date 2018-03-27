#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//#include <unistd.h>

int cont = 1;

char* ReadFile(char *filename)
{
   char *buffer = NULL;
   int string_size, read_size;
   FILE *handler = fopen(filename, "rb");
   

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
	char *string = ReadFile(".\\db\\StartScreen.txt");
	//char *string = ReadFile("Start.txt");
    if (string)
    {
        puts(string);
        free(string);
    }
    //char enterkey[1];
    //scanf("%s", enterkey);
    //sleep(1);
    //getchar();
    //system("cls");
    //printf("> ");
}

void getCommand()
{
	printf("> ");
	char input[12];
	scanf("%s", input);
	if(strncmp(input,"IF",12) == 0 || strncmp(input,"if",12) == 0)
	{
		system("cls");
		char *string = ReadFile(".\\db\\IF.txt");
		if (string)
		{
			puts(string);
			free(string);
		}
		//getCommand();
	}
	else if(strncmp(input,"START",12) == 0 || strncmp(input,"start",12) == 0)
	{
		
		system("cls");
		/*
		char *string = ReadFile(".\\db\\StartScreen.txt");
		if (string)
		{
			puts(string);
			free(string);
		}
		*/
		StartPage();
		//sleep(1);
		char c = getchar(); 
		while ((c = getchar()) != '\n' && c != EOF) { }
		system("cls");
		
		
	}
	else if(strncmp(input,"HYDROGEN",12) == 0 || strncmp(input,"hydrogen",12) == 0)
	{
		system("cls");
		char *string = ReadFile(".\\db\\Hydrogen.txt");
		if (string)
		{
			puts(string);
			free(string);
		}
	}
	else if(strncmp(input,"AC",12) == 0 || strncmp(input,"ac",12) == 0)
	{
		system("cls");
		char *string = ReadFile(".\\db\\AmbientComplexity.txt");
		if (string)
		{
			puts(string);
			free(string);
		}
	}
	else if(strncmp(input,"EXIT",12) == 0 || strncmp(input,"exit",12) == 0)
	{
		printf("Thank you for using the TARDIS \nINFORMATION SYSTEM");
		cont = 0;
	}
}

int main()
{
    StartPage();
    getchar();
    system("cls");
    
    while(cont == 1)
    {
		getCommand();
	}
	
	//getCommand();

    return 0;
}
