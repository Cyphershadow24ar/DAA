// Naive String Matching algorithm

#include <stdio.h>
#include <string.h>

int main() {
    // storing the character in an array.
    char text[100];
    char match[50];

    //user input.
    printf("Enter the main text: ");
    scanf("%s", text);
    
    //to check the length of user input text.
    int p = strlen(text);
    printf("Text length: %d\n", p);

    // taking the pattern from the user which is to be matched.
    printf("Enter the pattern to match: ");
    scanf("%s", match);

    // checking the length of matching pattern
    int t = strlen(match);
    printf("Pattern length: %d\n", t);

    // Loop for checking the pattern 
    for (int i = 0; i <= p - t; i++) { // i = is checking for text index
        int j;  // j= is checking for pattern index 
        for (j = 0; j < t; j++) {
            if (text[i + j] != match[j]) // to check if pattern is not matching the loop then breaks
                break;
        }
        // If j equal to text the pattern was found
        if (j == t) {
            printf("Pattern found at index: %d\n", i);
        }
    }
}
