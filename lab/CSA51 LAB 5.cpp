#include <stdio.h>
#include <string.h>
#include <ctype.h>

int gcd(int a, int b) {
    while (b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

int main() {
    char plaintext[100], ciphertext[100];
    int a, b, i;

    printf("Enter the plaintext: ");
    scanf("%s", plaintext);

    printf("Enter value of a: ");
    scanf("%d", &a);

    printf("Enter value of b: ");
    scanf("%d", &b);

    /* Check whether a is valid */
    if (gcd(a, 26) != 1) {
        printf("Invalid value of a!\n");
        printf("a must be relatively prime to 26.\n");
        return 0;
    }

    for (i = 0; plaintext[i] != '\0'; i++) {
        char p = toupper(plaintext[i]) - 'A';

        /* Affine Cipher formula */
        ciphertext[i] = ((a * p + b) % 26) + 'A';
    }

    ciphertext[i] = '\0';

    printf("Ciphertext: %s\n", ciphertext);

    return 0;
}

