#include <stdio.h>
#include <string.h>

#define d 256 // Number of characters in the input alphabet (assuming ASCII)
#define q 101 // A prime number for hashing (to reduce the likelihood of collisions)

// Rabin-Karp algorithm for pattern searching
void rabinKarp(char pattern[], char text[], int prime) {
    int M = strlen(pattern); // Length of the pattern
    int N = strlen(text);    // Length of the text
    int i, j;
    int p = 0; // Hash value for the pattern
    int t = 0; // Hash value for the text
    int h = 1;

    // Calculate the value of h = pow(d, M-1) % prime
    for (i = 0; i < M - 1; i++)
        h = (h * d) % prime;

    // Calculate the initial hash value of the pattern and first window of the text
    for (i = 0; i < M; i++) {
        p = (d * p + pattern[i]) % prime;
        t = (d * t + text[i]) % prime;
    }

    // Slide the pattern over the text one by one
    for (i = 0; i <= N - M; i++) {
        // Check if the hash values of the current window of text and pattern match
        if (p == t) {
            // If the hash values match, check for characters one by one
            for (j = 0; j < M; j++) {
                if (text[i + j] != pattern[j])
                    break;
            }
            // If the pattern is found
            if (j == M)
                printf("Pattern found at index %d\n", i);
        }

        // Calculate hash value for the next window of text:
        // Remove the leading digit and add the trailing digit
        if (i < N - M) {
            t = (d * (t - text[i] * h) + text[i + M]) % prime;

            // We might get a negative value of t, so convert it to positive
            if (t < 0)
                t = (t + prime);
        }
    }
}

int main() {
    char text[] = "GEEKS FOR GEEKS";
    char pattern[] = "GEEK";
    int prime = q; // A prime number for hashing
    rabinKarp(pattern, text, prime);
    return 0;
}
