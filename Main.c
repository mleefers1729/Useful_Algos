#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "CompoundWords.h"
#include "Snowflake.h"

//We are reading the input from a text file in this function. Any kind of input could be used but I found it quick to use Python to create a bunch of lists of 
//random integers and output a text file. Python code for that can be found in the repo and is called "SnowflakeInput.py".
//This will be called when the user chooses 'S' for an option.
int SnowflakeFind()
{
	//Defining variables
	FILE* textfile;
	char line[MAX_LINE_LENGTH];
	static flake_node* flakes[SIZE] = { NULL };
	flake_node* snow;
	int tmpFlake[6];
	int flakeCode;

	//opening the text file and looping through each line using fgets to get the list of integers.
	textfile = fopen("SnowflakeInput.txt", "r"); 

	//This loops through each line of the file
	while (fgets(line, MAX_LINE_LENGTH, textfile))
	{
		char* ptr = strtok(line, ",");
		int idx = 0;
		snow = malloc(sizeof(flake_node));
		if (snow == NULL)
		{
			fprintf(stderr, "malloc error\n");
			exit(1);
		}
		//This actually loops through the text on each line. We loop through and get all the integers and put them in an array called tmpFlake. 
		while (ptr != NULL)
		{
			tmpFlake[idx] = atoi(ptr);
			ptr = strtok(NULL, ",");
			++idx;
		}
		//Getting rid of unwanted 0s caued by the strtok function used above. Then getting the hashcode for the flake and building the linked list
		//and inserting it into our hashtable at the the index calculated for the hashcode.
		for (int r = 0; r < 6; r++)
		{
			if (tmpFlake[r] != 0)
				snow->flake[r] = tmpFlake[r];
		}
		flakeCode = code(snow->flake);
		snow->next = flakes[flakeCode];
		flakes[flakeCode] = snow;
	}

	//Closing the file and finally calling the find_identical function on the hash table that we have created.
	fclose(textfile);
	printf("\nInput File Closed\nFinding Identical Flakes...\n");
	find_identical(flakes);
	return 0;
}

int CompoundWordFind() {
	return 0;
}


//The Main function of the Program. Get the user's input then call the correct funtion. Ats it.
int main(void) {
	//Starting by printing a little bit of a heading to make the output look nicer. It matters okay??
	printf("%c", 10);
	printf("----------Its the Super Fun Algo Runner - Test me, I dare you.-----------%c", 10);
	printf("%c", 10);
	char sel[5];
	
	printf("Choose a function you would like to run. Type the letter of one of the following to run it:\n");
	while (! strcmp(sel, "xx") == 0){
		//All the function calls will go here based on user input of what to run.
		printf("\nSnowflake(s), Compoint Word(c)\n");
		scanf("%[^\n]%*c", sel);

		if (strcmp(sel,"s") == 0) {
			printf("Snowflake Match it is...\n");
			SnowflakeFind();
		}
		else if (strcmp(sel, "c") == 0) {
			printf("Compound\n");
			CompoundWordFind();
		}
		if (strcmp(sel, "xx") != 0) {
			printf("\n");
			printf("\nFunction Results listed above. Thank you come again.\n");
		}

	}
	printf("See ya later nerd\n");
	return 0;
}