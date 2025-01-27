#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[]) {
	if (!argv[1]) {
		printf("Geef een bestand");
		return 1;
	}

	FILE *fp;
	char *line = NULL;
	size_t len = 0;
	ssize_t read;

	fp = fopen(argv[1], "r");
	if (fp == NULL) {
		printf("Bestand niet gevonden: %s\n", argv[1]);
		return 1;
	}

	char* buffer = (char*) calloc(1, sizeof(char));
	buffer[0] = '\0';

	while ((read = getline(&line, &len, fp)) != -1) {
		buffer = (char*) realloc(buffer, (strlen(buffer) + strlen(line) + 1) * sizeof(char));
		strcat(buffer, line);
	}

	fclose(fp);
	if (line)
		free(line);

	printf("%s\n", buffer);
	return 0;
}
