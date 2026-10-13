
#include <stdio.h>
#include <string.h>

int main() {
    char ciphertext[] =
        "53‡‡†305))6*;4826)4‡.)4‡);806*;48†8¶60))85;;]8*;:‡*8†83\n"
        "(88)5*†;46(;88*96*?;8)*‡(;485);5*†2:*‡(;4956*2(5*—4)8¶8*\n"
        ";4069285);)6†8)4‡‡;1(‡9;48081;8:8‡1;48†85;4)485†528806*81 "
        "(‡9;48;(88;4(‡?34;48)4‡;161;:188;‡?;";

    int i;

    printf("Ciphertext:\n%s\n", ciphertext);

    printf("\nCharacter Frequency:\n");

    for (i = 0; ciphertext[i] != '\0'; i++) {
        int j, count = 0, found = 0;

        for (j = 0; j < i; j++) {
            if (ciphertext[i] == ciphertext[j]) {
                found = 1;
                break;
            }
        }

        if (!found && ciphertext[i] != '\n' &&
            ciphertext[i] != ' ') {
            for (j = 0; ciphertext[j] != '\0'; j++) {
                if (ciphertext[i] == ciphertext[j])
                    count++;
            }

            printf("%c : %d\n", ciphertext[i], count);
        }
    }

    return 0;
}

