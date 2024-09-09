#include <stdio.h>
#include <stdlib.h> // Use stdlib.h for the abs() function

#define FALSE 0
#define TRUE 1

int x[20]; // Array to store the positions of queens

// Function to check if the queen can be placed in row `k` and column `i`
int place(int k, int i) {
    int j;
    for (j = 1; j < k; j++) {
        // Check if queens are in the same column or diagonals
        if ((x[j] == i) || (abs(x[j] - i) == abs(j - k))) {
            return FALSE;
        }
    }
    return TRUE;
}

// Recursive function to solve the N-Queens problem
void nqueens(int k, int n) {
    int i, a;
    for (i = 1; i <= n; i++) {
        if (place(k, i)) {
            x[k] = i; // Place the queen at position (k, i)
            if (k == n) { // All queens have been placed
                for (a = 1; a <= n; a++) {
                    printf("%d\t", x[a]); // Print the solution
                }
                printf("\n");
            } else {
                nqueens(k + 1, n); // Place the next queen
            }
        }
    }
}

int main() {
    int n;
    printf("\nEnter the number of queens: ");
    scanf("%d", &n);

    if (n <= 0 || n > 20) {
        printf("Invalid number of queens. Please enter a number between 1 and 20.\n");
        return 1;
    }

    printf("\nThe solution to the N Queens problem is:\n");
    nqueens(1, n); // Start the process with the first queen
    return 0;
}
