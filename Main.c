#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "CompoundWords.c"
#include "Snowflake.c"

int main(void) {
	//Starting by printing a little bit of a heading to make the output look nicer. It matters okay??
	printf("%c", 10);
	printf("----------Snowflake Search Algo-----------%c", 10);
	printf("%c", 10);
	char sel = "";

	while (sel != "xx"){


		//All the function calls will go here based on user input of what to run.
		printf("Choose a function you would like to run. Type the letter of one of the following to run it:\n");
		printf("Snowflake(S), Compoint Word(C)\n");
		scanf("%s", &sel);

		if (sel == "S" || sel == "s") {
			SnowflakeFind();
		}
		else if (sel == "C" || sel == "c") {
			CompoundWordsFind();
		}

		printf("\n");
		printf("Function Results listed above. Thank you come again.\n");
	}
	
	return 0;
}