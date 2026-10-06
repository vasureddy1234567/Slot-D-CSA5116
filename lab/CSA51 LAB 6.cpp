#include <stdio.h>
#include <ctype.h>

int main() {
    char ciphertext[100];
    char plaintext[100];
    int i;
    int a = 3;
    int b = 15;
    int a_inv = 9;

    printf("Enter the ciphertext: ");
    scanf("%s", ciphertext);

    for (i = 0; ciphertext[i] != '\0'; i++) {
        int c = toupper(ciphertext[i]) - 'A';

        /* Decryption formula:
           P = a^-1 (C - b) mod 26
        */

        int p = (a_inv * (c - b + 26)) % 26;

        plaintext[i] = p + 'A';
    }

    plaintext[i] = '\0';

    printf("Decrypted plaintext: %s\n", plaintext);

    return 0;
}
