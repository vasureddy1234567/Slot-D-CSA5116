#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main() {
    char plaintext[100], key[100], ciphertext[100];
    int i, j = 0;
    int keyLen;

    printf("Enter the plaintext: ");
    scanf("%s", plaintext);

    printf("Enter the key: ");
    scanf("%s", key);

    keyLen = strlen(key);

    for (i = 0; plaintext[i] != '\0'; i++) {
        char p = toupper(plaintext[i]);
        char k = toupper(key[j % keyLen]);

        ciphertext[i] = ((p - 'A') + (k - 'A')) % 26 + 'A';

        j++;
    }

    ciphertext[i] = '\0';

    printf("Ciphertext: %s\n", ciphertext);

    return 0;
}
