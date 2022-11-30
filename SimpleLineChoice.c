#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int shortest_line_index(int lines[], int n)
{
	int j;
	int shortest = 0;
	for (j = 1; j < n; ++j)
	{
		if (lines[j] < lines[shortest])
		{
			shortest = j;
			break;
		}
	}
	return shortest;
}

int main() {
	printf("%c", 10);
	printf("----------Algo Testing Number 1 - Shortest Lines Finder-----------%c",10);
	printf("%c", 10);
	int m = 42;
	int n = 7;
	int lines[] = { 3,2,5,10,9,1,3 };
	int idx;

	for (int i = 0; i < m; ++i)
	{
		idx = shortest_line_index(lines, n);
		lines[idx] = lines[idx] + 1;
	}

	for (int p = 0; p < n; ++p)
	{
		printf("Lines %d: %d\n", p + 1, lines[p]);
	}
	
	printf("%c",10);
	return 0;
}
