#include <stdio.h>
#include <string.h>

int main(int argc, char *argv[]) {
    char *steps = argv[1];

    int forward = 0;
    int backward = 0;

    for (int i = 0; i < strlen(steps); i++) {
        char step = steps[i];

        if (step == '>') forward++;
        if (step == '<') backward++;
    }

    char *plus = "";
    if (forward-backward > 0) plus = "+";

    printf("Stappen voorwaarts: %i\nStappen achterwaarts: %i\nKomt uit op: %s%i", forward, backward, plus, forward-backward);

    return 0;
}