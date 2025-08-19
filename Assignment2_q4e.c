#include <stdio.h>

int main() {
    char ch;

    printf("Enter an uppercase character: ");
    scanf("%c", &ch);

    if (ch >= 'A' && ch <= 'Z') {
        ch = ch + 32;
        printf("Lowercase: %c\n", ch);
    } else {
        printf("Character is not uppercase.\n");
    }

    return 0;
}

