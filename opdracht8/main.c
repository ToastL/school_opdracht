#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define ERR_MESSAGE__NO_MEM "Not enough memory!"
#define allocator(element, type) _allocator(element, sizeof(type))

void *_allocator(size_t element, size_t typeSize)
{
    void *ptr = NULL;
    if( (ptr = calloc(element, typeSize)) == NULL)
    {printf(ERR_MESSAGE__NO_MEM); exit(1);}
    return ptr;
}

char *append(const char *input, const char c) {
    char *newString, *ptr;

    newString = allocator((strlen(input)+2), char);
    ptr = newString;
    *ptr = c;

    return newString;
}

int main(int argc, char *argv[]) {
    char *morseCode = argv[1];

    for (int i = 0; i < strlen(morseCode); i++) {
        char *currWord = "";

        while (morseCode[i] != ' ' && morseCode[i] != '\0') {
            currWord = append(currWord, morseCode[i]);

            i++;
        }

        printf("%s\n", currWord);
        free(currWord);
    }

    return 0;
}