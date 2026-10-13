
#include <stdio.h>
#include <string.h>
#include <ctype.h>

char matrix[5][5];

void generateMatrix(char key[]) {
    int used[26] = {0};
    int i, j, k = 0;
    char ch;

    used['J' - 'A'] = 1;

    for (i = 0; key[i] != '\0'; i++) {
        ch = toupper((unsigned char)key[i]);
        if (ch < 'A' || ch > 'Z')
            continue;
        if (ch == 'J')
            ch = 'I';

        if (!used[ch - 'A']) {
            matrix[k / 5][k % 5] = ch;
            used[ch - 'A'] = 1;
            k++;
        }
    }

    for (ch = 'A'; ch <= 'Z'; ch++) {
        if (!used[ch - 'A']) {
            matrix[k / 5][k % 5] = ch;
            k++;
        }
    }
}

void decrypt(char text[]) {
    int i, r1, c1, r2, c2, r, c;
    char a, b;

    printf("Decrypted text: ");

    for (i = 0; text[i] && text[i + 1]; i += 2) {
        a = toupper((unsigned char)text[i]);
        b = toupper((unsigned char)text[i + 1]);

        if (a < 'A' || a > 'Z' ||
            b < 'A' || b > 'Z')
            continue;

        if (a == 'J') a = 'I';
        if (b == 'J') b = 'I';

        for (r = 0; r < 5; r++)
            for (c = 0; c < 5; c++) {
                if (matrix[r][c] == a) {
                    r1 = r;
                    c1 = c;
                }
                if (matrix[r][c] == b) {
                    r2 = r;
                    c2 = c;
                }
            }

        if (r1 == r2) {
            printf("%c%c",
                matrix[r1][(c1 + 4) % 5],
                matrix[r2][(c2 + 4) % 5]);
        } else if (c1 == c2) {
            printf("%c%c",
                matrix[(r1 + 4) % 5][c1],
                matrix[(r2 + 4) % 5][c2]);
        } else {
            printf("%c%c",
                matrix[r1][c2],
                matrix[r2][c1]);
        }
    }
    printf("\n");
}

int main() {
    char key[100];
    char cipher[] =
        "KXJEYUREBEZWEHEWRYTUHEYFS"
        "KREHEGOYFIWTTTUOLKSYCAJPO"
        "BOTEIZONTXBYBNTGONEYCUZWR"
        "GDSONSXBOUYWRHEBAAHYUSEDQ";

    int i, j;

    printf("Enter Playfair keyword: ");
    scanf("%99s", key);

    generateMatrix(key);

    printf("\nPlayfair Key Matrix:\n");
    for (i = 0; i < 5; i++) {
        for (j = 0; j < 5; j++)
            printf("%c ", matrix[i][j]);
        printf("\n");
    }

    decrypt(cipher);

    return 0;
}

