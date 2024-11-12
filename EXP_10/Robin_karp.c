#include <stdio.h>
#include <string.h>

#define AS 256 //alphabet size
#define P 101 //prime mod 

void rabinKarp(char *txt, char *pat) {
    int m = strlen(pat);  //To check the Length of the pattern
    int n = strlen(txt);  //to check the Length of the text
    int i, j;
    int ph = 0;           //Hash value for pattern
    int th = 0;           //Hash value window
    int h = 1;            // hash multiplier 

    for (i = 0; i < m - 1; i++)
        h = (h * AS) % P;

    for (i = 0; i < m; i++) {
        ph = (AS * ph + pat[i]) % P;  
        th = (AS * th + txt[i]) % P; 
    }

    // Slide the pattern over text one character at a time
    for (i = 0; i <= n - m; i++) {
        // checking the hash values and checking the characters one by one
        if (ph == th) {
            for (j = 0; j < m; j++) {
                if (txt[i + j] != pat[j])
                    break;
            }
            if (j == m) {
                printf("Pattern found at index %d\n", i);
            }
        }

        if (i < n - m) { 
            th = (AS * (th - txt[i] * h) + txt[i + m]) % P;
            if (th < 0) {
                th += P;
            }
        }
    }
}

int main() {
    // array for storing
    char txt[100], pat[100];

    // User input for pattern 
    printf("Enter the text: ");
    scanf("%99s", txt);

    // user input for matching pattern 
    printf("Enter the pattern to search for: ");
    scanf("%99s", pat);

    rabinKarp(txt, pat);

    return 0;
}
