#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *readFile(char *path) {
    FILE *fp;
    char *line = NULL;
    size_t len = 0;
    ssize_t read;

    fp = fopen(path, "r");
    if (fp == NULL) {
        printf("Bestand niet gevonden: %s\n", path);
        exit(1);
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

    return buffer;
}

int main(int argc, char *argv[]) {
    char *content = readFile(argv[1]);

    float highest = 0;
    int highestCustomer = 0;
    int currCustomer = 1;

    char *currLine = content;
    while (currLine) {
        char *nextLine = strchr(currLine, '\n');
        if (nextLine) *nextLine = '\0';

        if (strlen(currLine) == 0) {
            currCustomer++;
        }

        float curr = atof(currLine);
        if (curr > highest) {
            highest = curr;
            highestCustomer = currCustomer;
        }

        if (nextLine) *nextLine = '\n';
        currLine = nextLine ? (nextLine+1) : NULL;
    }
    
    printf("%i, %f\n", highestCustomer, highest);

    return 0;
}