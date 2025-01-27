#include <stdio.h>
#include <string.h>

int main(int argc, char *argv[]) {
    if (!argv[1]) {
        printf("Please give a code");
        return 1;
    }

    char *code = argv[1];

    int count = 0;

    for (int i = 0; i < strlen(code); i++) {
        char curr = code[i];
        if (curr == '(') count++;
        if (curr == ')') count--;
    }

    if (count > 0) printf("Er mist een sluitend haakje.\n");
    if (count < 0) printf("Een haakje sluit te vroeg.\n");
    if (count == 0) printf("Geen problemen gevonden.\n");

    return 0;
}