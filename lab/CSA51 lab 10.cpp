
#include <stdio.h>
#include <string.h>
#include <ctype.h>

char matrix[5][5] = {
    {'M', 'F', 'H', 'I', 'K'},
    {'U', 'N', 'O', 'P', 'Q'},
    {'Z', 'V', 'W', 'X', 'Y'},
    {'E', 'L', 'A', 'R', 'G'},
    {'D', 'S', 'T', 'B', 'C'}
};

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

int main() {
    char message[] =
        "MUST SEE YOU OVER CADOGAN WEST. COMING AT ONCE";
    char text[200], a, b;
    int i, j = 0;
    int r1, c1, r2, c2;

    // Remove spaces and punctuation
    for (i = 0; message[i] != '\0'; i++) {
        if (isalpha((unsigned char)message[i])) {
            a = toupper((unsigned char)message[i]);
            if (a == 'J')
                a = 'I';
            text[j++] = a;
        }
    }
    text[j] = '\0';

    // Prepare letter pairs, inserting X for repeated letters
    char prepared[300];
    int k = 0;

    for (i = 0; i < j;) {
        a = text[i++];

        if (i < j && text[i] != a) {
            b = text[i++];
        } else {
            b = 'X';
        }

        prepared[k++] = a;
        prepared[k++] = b;
    }
    prepared[k] = '\0';

    printf("Prepared text: %s\n", prepared);
    printf("Ciphertext: ");

    for (i = 0; i < k; i += 2) {
        findPosition(prepared[i], &r1, &c1);
        findPosition(prepared[i + 1], &r2, &c2);

        if (r1 == r2) {
            printf("%c%c",
                matrix[r1][(c1 + 1) % 5],
                matrix[r2][(c2 + 1) % 5]);
        } else if (c1 == c2) {
            printf("%c%c",
                matrix[(r1 + 1) % 5][c1],
                matrix[(r2 + 1) % 5][c2]);
        } else {
            printf("%c%c",
                matrix[r1][c2],
                matrix[r2][c1]);
        }
    }

    printf("\n");
    return 0;
}

