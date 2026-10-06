#include <stdio.h>
#include <string.h>
#include <ctype.h>

char matrix[5][5];

/* Create the 5 x 5 matrix */
void createMatrix(char key[]) {
    int used[26] = {0};
    int i, j, k = 0;
    char ch;

    used['J' - 'A'] = 1;   // Combine I and J

    /* Insert key characters */
    for (i = 0; key[i] != '\0'; i++) {
        ch = toupper(key[i]);

        if (ch == 'J')
            ch = 'I';

        if (ch >= 'A' && ch <= 'Z' && !used[ch - 'A']) {
            matrix[k / 5][k % 5] = ch;
            used[ch - 'A'] = 1;
            k++;
        }
    }

    /* Insert remaining alphabets */
    for (ch = 'A'; ch <= 'Z'; ch++) {
        if (!used[ch - 'A']) {
            matrix[k / 5][k % 5] = ch;
            used[ch - 'A'] = 1;
            k++;
        }
    }
}

/* Find position of a character */
void findPosition(char ch, int *row, int *col) {
    int i, j;

    if (ch == 'J')
        ch = 'I';

    for (i = 0; i < 5; i++) {
        for (j = 0; j < 5; j++) {
            if (matrix[i][j] == ch) {
                *row = i;
                *col = j;
                return;
            }
        }
    }
}

/* Encrypt plaintext */
void encrypt(char text[]) {
    int i;
    int r1, c1, r2, c2;
    char a, b;

    for (i = 0; text[i] != '\0'; i += 2) {

        a = text[i];
        b = text[i + 1];

        findPosition(a, &r1, &c1);
        findPosition(b, &r2, &c2);

        /* Same row */
        if (r1 == r2) {
            printf("%c%c",
                   matrix[r1][(c1 + 1) % 5],
                   matrix[r2][(c2 + 1) % 5]);
        }

        /* Same column */
        else if (c1 == c2) {
            printf("%c%c",
                   matrix[(r1 + 1) % 5][c1],
                   matrix[(r2 + 1) % 5][c2]);
        }

        /* Rectangle rule */
        else {
            printf("%c%c",
                   matrix[r1][c2],
                   matrix[r2][c1]);
        }
    }
}

int main() {
    char key[100];
    char plaintext[100];
    char prepared[100];
    int i, j = 0;

    printf("Enter the key: ");
    scanf("%s", key);

    createMatrix(key);

    printf("\nPlayfair Matrix:\n");

    for (i = 0; i < 5; i++) {
        for (j = 0; j < 5; j++) {
            printf("%c ", matrix[i][j]);
        }
        printf("\n");
    }

    printf("\nEnter plaintext: ");
    scanf("%s", plaintext);

    /* Prepare plaintext */
    j = 0;

    for (i = 0; plaintext[i] != '\0'; i++) {
        char ch = toupper(plaintext[i]);

        if (ch == 'J')
            ch = 'I';

        prepared[j++] = ch;
    }

    /* Add X if length is odd */
    if (j % 2 != 0)
        prepared[j++] = 'X';

    prepared[j] = '\0';

    printf("\nPrepared Plaintext: %s", prepared);

    printf("\nEncrypted Text: ");
    encrypt(prepared);

    printf("\n");

    return 0;
}
