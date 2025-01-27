#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

int main(int argc, char *argv[]) {
	float out = 0;	

	for (int i = 1; i < argc; i++) {
		char* num = argv[i];

		for (int j = 0; j < strlen(num); j++)
			if (!isdigit(num[j]) && num[j] != '.' && num[j] != '-') return 1;

		out += atof(argv[i]);
	}

	printf("%f\n", out);

	return 0;
}
