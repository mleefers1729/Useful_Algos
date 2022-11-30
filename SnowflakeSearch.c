/*This solution implements a hash table of linked lists for the search.
For an input of 100,000 snowflakes, this program should take < 2seconds to complete the search.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Testing.c"
#define MAX_LINE_LENGTH 1000
#define SIZE 100000

//using typedef and struct to define a structure for linked list nodes that we will use to create our hash table
typedef struct flake_node {
	int flake[6];
	struct flake_node* next;
}flake_node;

//Hashing function for the snowflakes. Add the elements then mod by by the max number of snowflakes
int code(int flake[])
{
	return (flake[0] + flake[1] + flake[2] + flake[3] + flake[4] + flake[5]) % SIZE;
}

//checking for left to right match
int moving_right(int sf1[], int sf2[], int start)
{
	for (int i = 0; i < 6; ++i)
	{
		if (sf1[i] != sf2[(start + i) % 6])
			return 0;
	}
	return 1;
}

//checking for right to left match
int moving_left(int sf1[], int sf2[], int start)
{
	for (int i = 0; i < 6; ++i)
	{
		int sf2_index = start - i;
		if (sf2_index < 0)
			sf2_index = sf2_index + 6;
		if (sf1[i] != sf2[sf2_index])
			return 0;
	}
	return 1;
}

//moving through a list of snowflakes and checking them
int are_identical(int sf1[], int sf2[])
{
	int start;
	for (start = 0; start < 6; ++start)
	{
		if (moving_right(sf1, sf2, start))
		{
			return 1;
		}
		if (moving_left(sf1, sf2, start))
		{
			return 1;
		}
	}
	return 0;
}

//The function that will return the result and call all other functions needed to find the identical snowflakes. We are initializing and using the linked
//list nodes with the 'are_identical' funtion defined above.
void find_identical(flake_node* flakes[])
{
	flake_node* node1, * node2;
	for (int i = 0; i < SIZE; ++i)
	{
		node1 = flakes[i];
		//printf("%d\n", i);
		while (node1 != NULL)
		{
			node2 = node1->next;
			while (node2 != NULL)
			{
				if (are_identical(node1->flake, node2->flake))
				{
					printf("Twin Snowflake Found!");
					return;
				}
				node2 = node2->next;
			}
			node1 = node1->next;
		}
	}
	printf("No Alike Flakes Found");
	return;
}

//We are reading the input from a text file in this function. Any kind of input could be used but I found it quick to use Python to create a bunch of lists of 
//random integers and output a text file. Python code for that can be found in the repo and is called "SnowflakeInput.py".
int main(void)
{
	//Starting by printing a little bit of a heading to make the output look nicer. It matters okay??
	printf("%c", 10);
	printf("----------Snowflake Search Algo-----------%c", 10);
	printf("%c", 10);
	testFunc();

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

	printf("\n");
	return 0;
}