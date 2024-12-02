#include <stdio.h>

// Function to find the length of a string using pointers
int findLen(char *str) {
    int length = 0;
    while (*str != '\0') { 
        length++;
        str++; 
    }
    return length;
}

// Function to reverse a string using pointers
void revStr(char *str) {
    char *first = str;
    char *last = str;
    char temp;

    while (*(last+1) != '\0') {
        last++;
    }

   while (first < last) {
        temp = *first;
        *first = *last;
        *last = temp;

        first++;
        last--;
    }
}

// Function to concatenate two strings using pointers
void conStr(char *str1, char *str2) {
    while (*str1 != '\0') {
        str1++;
    }

    while (*str2 != '\0') {
        *str1 = *str2;
        str1++;
        str2++; //adding single character one by one
    }
    *str1 = '\0'; 
}

int main() {
    char str1[20], str2[20];

    printf("Enter the first string: ");
    gets(str1);
    printf("Enter the second string: ");
    gets(str2);

    int len = findLen(str1);
    printf("Length of the first string: %d\n", len);
    len = findLen(str2);
    printf("Length of the second string: %d\n", len);

    revStr(str1);
    printf("Reversed first string: %s\n", str1);
    revStr(str2);
    printf("Reversed first string: %s\n", str2);
    
	revStr(str1);revStr(str2);
	conStr(str1, str2);
    printf("Concatenated string: %s\n", str1);
    
   
    return 0;
}
