/*This solution implements a hash table of linked lists for the search.
For an input of 100,000 snowflakes, this program should take < 2seconds to complete the search.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_LINE_LENGTH 1000
#define SIZE 100000

//using typedef and struct to define a structure for linked list nodes that we will use to create our hash table
typedef struct flake_node {
	int flake[6];
	struct flake_node* next;
}flake_node;

//Hashing function for the snowflakes. Add the elements then mod by by the max number of snowflakes
extern int code(int flake[])
{
	return (flake[0] + flake[1] + flake[2] + flake[3] + flake[4] + flake[5]) % SIZE;
}

//checking for left to right match
extern int moving_right(int sf1[], int sf2[], int start)
{
	for (int i = 0; i < 6; ++i)
	{
		if (sf1[i] != sf2[(start + i) % 6])
			return 0;
	}
	return 1;
}

//checking for right to left match
extern int moving_left(int sf1[], int sf2[], int start)
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
extern int are_identical(int sf1[], int sf2[])
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
extern void find_identical(flake_node* flakes[])
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
