#include <stdio.h>
#include <time.h>
#include <stdlib.h>  // For rand()

#define TRUE 1
#define FALSE 0

void heapbottomup(int h[], int n) {
    int i, heap, v, j, k;
    for (i = n / 2; i >= 1; i--) {  // Use >= 1 for 1-based index
        k = i;
        v = h[k];
        heap = FALSE;
        while (!heap && (2 * k) <= n) {
            j = 2 * k;
            if (j < n && h[j] < h[j + 1]) {
                j = j + 1;
            }
            if (v >= h[j]) {
                heap = TRUE;
            } else {
                h[k] = h[j];
                k = j;
            }
        }
        h[k] = v;  // Place the value in the correct position
    }
}

void heapsort(int h[], int n) {
    int i, temp, last = n;
    if (n <= 1) return;
    heapbottomup(h, n);
    for (i = n; i > 1; i--) {  // Build the sorted array
        temp = h[1];
        h[1] = h[i];
        h[i] = temp;
        heapbottomup(h, i - 1);
    }
}

int main() {
    int h[21], n, i;  // Adjusted size for 1-based index
    double clk;
    clock_t starttime, endtime;

    printf("Enter the number of resumes: ");
    scanf("%d", &n);

    for (i = 1; i <= n; i++) {
        h[i] = rand() % 100;
        printf("The candidates' ranks are: \t%d\n", h[i]);
    }

    starttime = clock();
    heapsort(h, n);
    endtime = clock();

    clk = (double)(endtime - starttime) / CLOCKS_PER_SEC;

    printf("\nThe ranks in sorted order:\n");
    for (i = 1; i <= n; i++) {
        printf("\t%d", h[i]);
    }
    printf("\nThe run time is %f seconds\n", clk);

    return 0;
}

// INPUT:
// Enter the number of resumes: 5

// Resumes (randomly generated):
// 65
// 23
// 87
// 45
// 78
