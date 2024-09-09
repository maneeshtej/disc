#include <stdio.h>

int count = 0, w[10], d, x[10];

// Function to find subsets with a sum equal to `d`
void subset(int cs, int k, int r) {
    int i;
    x[k] = 1;

    // If current subset sum matches the target sum, print the solution
    if (cs + w[k] == d) {
        printf("\nSubset solution = %d\n", ++count);
        for (i = 0; i <= k; i++) {
            if (x[i] == 1)
                printf("%d\n", w[i]);
        }
    }
    // If the current sum plus the next weight can be part of the solution, continue
    else if (cs + w[k] + w[k + 1] <= d) {
        subset(cs + w[k], k + 1, r - w[k]);
    }

    // Backtracking step: if there is still room for more weights, continue without the current one
    if ((cs + r - w[k] >= d) && (cs + w[k + 1] <= d)) {
        x[k] = 0;
        subset(cs, k + 1, r - w[k]);
    }
}

int main() {
    int sum = 0, i, n;
    
    printf("Enter the number of elements:\n");
    scanf("%d", &n);
    
    printf("Enter the elements in ascending order:\n");
    for (i = 0; i < n; i++)
        scanf("%d", &w[i]);
    
    printf("Enter the required sum:\n");
    scanf("%d", &d);
    
    // Calculate the sum of all elements
    for (i = 0; i < n; i++)
        sum += w[i];
    
    // If the sum of elements is less than the required sum, no solution exists
    if (sum < d) {
        printf("No solution exists\n");
    } else {
        printf("The solutions are:\n");
        count = 0;
        subset(0, 0, sum);
    }

    return 0;
}

INPUT:
Enter the number of elements:
5
Enter the elements in ascending order:
1 2 3 4 5
Enter the required sum:
6
