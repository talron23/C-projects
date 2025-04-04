#include <stdio.h>

/* check if a string is a palindrome (ignores spaces and tabs) */
int palindrome(char s[ ])
{
    int i, j;

    /* remove newline that fgets() might have added at the end */
    for (i = 0; s[i] != '\0'; i++) {
        if (s[i] == '\n') {
            s[i] = '\0';
            break; /* Stop when we find the newline */
        }
    }

    /* (i-1) is the last valid character, now we'll compare characters from both ends */
    for (j = i - 1, i = 0; i < j;) {
        /* Skip any spaces or tabs from the beginning of the string */
        if (s[i] == ' ' || s[i] == '\t') {
            i++; /* Move i forward */
            continue;
        }

        /* Skip spaces or tabs from the end of the string */
        if (s[j] == ' ' || s[j] == '\t') {
            j--; /* Move j backward */
            continue;
        }

        /* If characters don't match, it's not a palindrome */
        if (s[i] != s[j]) {
            return 0; /* Not a palindrome */
        }

        j--; /* Move j backward */
        i++; /* Move i forward */
    }

    return 1; /* It's a palindrome if we make it here */
}

int main(void) {
    char str[81];  /* Max input length of 80 chars, plus space for null terminator */
    int result;

    /* Ask the user for input (max 80 chars) */
    printf("Please enter a string (max 80 chars): ");
    fgets(str, sizeof(str), stdin);
    printf("The given string is: %s\n", str); /* Show the string back to the user */

    /* Check if the input string is a palindrome and print the result */
    result = palindrome(str);
    if (result == 1)
        printf("The given string is a palindrome\n");
    else
        printf("The given string is not a palindrome\n");

    return 0;
}
