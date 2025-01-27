#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    if (!argv[1]) {
        printf("Geef een lengte van de pyramide");
        return 1;
    }

    int len = atoi(argv[1]);

    if (len < 2 || len > 20) {
        printf("Vul een getal tussen 3 t/m 20 in.");
        return 1;
    }

    for (int i = 0; i < len; i++) {
        for (int j = 0; j < len-1-i; j++) printf(".");
        for (int j = 0; j < i+1; j++) printf("#");
        printf("#\n");
    }
    return 0;
}