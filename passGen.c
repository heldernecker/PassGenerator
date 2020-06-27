#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

char* letters = "AaBbCcDdEeFfGgHhIiJjKkLlMmNnOoPpQqRrSsTtUuVvWwXxYyZz";
char* numbers = "0123456789";
char* special = " !\"#$%&'()*+,-./:;<=>?@[\\]^_`{|}~";

int main() {
    srand(time(NULL));
    int charNumber;
    int option;
    char* password;
    password = (char*) malloc(50 * sizeof(char));
    strcpy(password, "");

    printf("Welcome to Pass Generator, please enter the number os characteres: ");
    scanf("%d", &charNumber);

    printf("\nSelect one option:\n");
    printf("1 - Only letters\n");
    printf("2 - Alphanumeric\n");
    printf("3 - Alphanumeric with Special Characters\n");
    printf("\nYour option is: ");
    scanf("%d", &option);

    if (option == 1) {
        for (int n = 0; n < charNumber; n++) {
            char ch = letters[rand() % strlen(letters)];
            strncat(password, &ch, 1);
        }
    } else if (option == 2) {
        char alphaNum[strlen(letters) + strlen(numbers) + 1];
        strcpy(alphaNum, letters);
        strcat(alphaNum, numbers);

        for (int n = 0; n < charNumber; n++) {
            char ch = alphaNum[rand() % strlen(alphaNum)];
            strncat(password, &ch, 1);
        }
    } else if (option == 3) {
        char allChars[strlen(letters) + strlen(numbers) + 1];
        strcpy(allChars, letters);
        strcat(allChars, numbers);
        strcat(allChars, special);

        for (int n = 0; n < charNumber; n++) {
            char ch = allChars[rand() % strlen(allChars)];
            strncat(password, &ch, 1);
        }
    }

    printf("\nYour password is: %s\n", password);

    return 0;
}