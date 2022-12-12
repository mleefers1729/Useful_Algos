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

extern char *readLine(int size) {
	char *str;
	int ch;
	int len = 0;
	str = malloc(size);
	if (str == NULL) {
		fprintf(stderr, "malloc error\n");
		exit(1);
	}
	while ((ch = getchar()) != EOF && (ch != '\n')) {
		str[len++] = ch;
		if (len == size) {
			size = size * 2;
			str = realloc(str, size);
			if(str == NULL) {
				fprintf(stderr, "realloc error\n");
				exit(1);
			}
		}
	}
	str[len] = '\0';
	return str;
}

extern int CompoundWordFind(void){
	printf("Compund Words Ran");
return 0; }

typedef struct word_node {
	char** word;
	struct word_node* next;
}word_node;

int inHashTable(word_node* hash_table[], char* find, unsigned find_len) {
	unsigned word_code;
	word_node* wordPtr;
	word_code = oaat(find, find_len, NUM_BITS);
}
