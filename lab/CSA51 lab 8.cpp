
#include <stdio.h>
#include <ctype.h>
#include <string.h>

int main() {
    char plain[100], cipher[26];
    char keyword[] = "CIPHER";
    int i, j, k = 0, found;
    
    // Generate cipher sequence using keyword
    for (i = 0; keyword[i] != '\0'; i++) {
        found = 0;
        for (j = 0; j < k; j++) {
            if (cipher[j] == keyword[i]) {
                found = 1;
                break;
            }
        }
        if (!found)
            cipher[k++] = keyword[i];
    }

    // Add remaining unused letters
    for (i = 'A'; i <= 'Z'; i++) {
        found = 0;
        for (j = 0; j < k; j++) {
            if (cipher[j] == i) {
                found = 1;
                break;
            }
        }
        if (!found)
            cipher[k++] = i;
    }

    printf("Plain alphabet : ");
    for (i = 'a'; i <= 'z'; i++)
        printf("%c ", i);

    printf("\nCipher alphabet: ");
    for (i = 0; i < 26; i++)
        printf("%c ", cipher[i]);

    printf("\n\nEnter plaintext: ");
    fgets(plain, sizeof(plain), stdin);

    printf("Ciphertext     : ");
    for (i = 0; plain[i] != '\0'; i++) {
        if (isalpha((unsigned char)plain[i])) {
            char ch = toupper((unsigned char)plain[i]);
            printf("%c", cipher[ch - 'A']);
        } else {
            printf("%c", plain[i]);
        }
    }

    return 0;
}

