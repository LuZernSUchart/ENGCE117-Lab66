#include <stdio.h>
#include <string.h>

void explode(char str1[], char splitter, char str2[][10]);

int main() {
    char str2[10][10];
    char str1[10];
    printf("Enter text using / instead of spaces. :");
    scanf("%s", str1);
    
    explode( str1, '/', str2);
    return 0;
}

void explode(char str1[], char splitter, char str2[][10]) {
    int j = 0;
    int k = 0;
    
    
    for (int i = 0; str1[i] != '\0'; i++) {
        if (str1[i] == splitter) {
            str2[j][k] = '\0';
            j++;
            k = 0;
        } else {
            printf("%c", str1[i]);
            str2[j][k] = str1[i];
            k++;
        }
    }
    printf("\n\n");
    for (int i = 0; i <= j; i++) {
        printf("Str2[%i] :%s\n", i, str2[i]);
    }
}
