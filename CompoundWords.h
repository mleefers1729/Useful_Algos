#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define hashsize(n) ((unsigned long)1 << (n))
#define hashmask(n) (hashsize(n) - 1)
#define NUM_BITS 17

unsigned long oaat(char* key, unsigned long len, unsigned long bits) {
	unsigned long hash, i;
	for (hash = 0, i = 0; i < len; i++) {
		hash += key[i];
		hash += (hash << 10);
		hash ^= (hash >> 6);
	}
	hash += (hash << 3);
	hash ^= (hash >> 11);
	hash += (hash << 15);
	return hash & hashmask(bits);
}

char* readLine(int size) {
	char* myStr;
	int ch;
	int len = 0;
	myStr = malloc(size);
	if (myStr == NULL) {
		fprintf(stderr, "malloc error\n");
		exit(1);
	}
	while ((ch = getchar()) != EOF && (ch != '\n')) {
		myStr[len++] = ch;
		if (len == size) {
			size = size * 2;
			myStr = realloc(myStr, size);
			if (myStr == NULL) {
				fprintf(stderr, "realloc error\n");
				exit(1);
			}
		}
	}
	myStr[len] = '\0';
	return myStr;
}


typedef struct word_node {
	char** word;
	struct word_node* next;
}word_node;

int inHashTable(word_node* hash_table[], char* find, unsigned find_len) {
	unsigned word_code;
	word_node* wordPtr;
	word_code = oaat(find, find_len, NUM_BITS);
	wordPtr = hash_table[word_code];
	while (wordPtr) {
		if ((strlen(*(wordPtr->word)) == find_len) && (strncmp(*(wordPtr->word), find, find_len) == 0)) {
			return 1;
		}
	}
	return 0;
}