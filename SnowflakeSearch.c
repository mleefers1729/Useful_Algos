#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_LINE_LENGTH 1000
#define SIZE 100000

typedef struct flake_node {
	int flake[6];
	struct flake_node *next;
}flake_node;

int code(int flake[])
{
	return (flake[0] + flake[1] + flake[2] + flake[3] + flake[4] + flake[5]) % SIZE;
}

int moving_right(int sf1[], int sf2[], int start)
{
	for (int i = 0; i < 6; ++i)
	{
		if (sf1[i] != sf2[(start + i) % 6])
			return 0;
	}
	return 1;
}

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

void find_identical(flake_node *flakes[])
{
	flake_node *node1, *node2;
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

int main(void)
{
	printf("%c", 10);
	printf("----------Algo Testing Number 2 - Snowflake Search Algo-----------%c", 10);
	printf("%c", 10);
	
	FILE * textfile;
	char line[MAX_LINE_LENGTH];
	static flake_node *flakes[SIZE] = {NULL};
	flake_node *snow;
	int tmpFlake[6];
	int flakeCode;
	//int lineCount = 0;

	textfile = fopen("SnowflakeInput.txt","r");
	
	while (fgets(line, MAX_LINE_LENGTH, textfile))
	{
		char* ptr = strtok(line, ",");
		int idx = 0;
		snow = malloc(sizeof(flake_node));
		//printf("%c\n", line);
		if (snow == NULL)
		{
			fprintf(stderr, "malloc error\n");
			exit(1);
		}
		while (ptr != NULL)
		{
			tmpFlake[idx] = atoi(ptr);
			ptr = strtok(NULL, ",");
			++idx;
		}
		
		for (int r = 0; r < 6; r++)
		{
			if (tmpFlake[r] != 0)
				snow->flake[r] = tmpFlake[r];
		}
		flakeCode = code(snow->flake);
		snow->next = flakes[flakeCode];
		flakes[flakeCode] = snow;
	}

	fclose(textfile);
	printf("\nInput File Closed\nFinding Identical Flakes...\n");
	find_identical(flakes);

	printf("%c", 10);
	return 0;
}