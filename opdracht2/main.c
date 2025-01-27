#include <stdio.h>
#include <string.h>

int isCapital(char c) {
	if (c >= 'A' && c <= 'Z') return 1;
	return 0;
}

int main(int argc, char *argv[]) {
	int charCount = 0;
	int capCount = 0;

	for (int i = 1; i < argc; i++) {
		char *word = argv[i];
		for (int j = 0; j < strlen(word); j++) {
			if (word[j] != ' ') charCount++;
			if (isCapital(word[j])) capCount++;
		}
	}
	
	printf("Aantal letter: %i\n", charCount);
	printf("Aantal hoofdletters: %i\n", capCount);

	return 0;
}
