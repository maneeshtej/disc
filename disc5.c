#include <stdio.h>
#include <time.h>
#include <stdlib.h>  // For rand()

#define MAX_SIZE 500000  // Define a constant for the maximum size of array

int a[MAX_SIZE];  // Array to hold the elements

void merge(int low, int mid, int high) {
    int h, i, j, b[MAX_SIZE], k;
    h = low;
    i = low;
    j = mid + 1;

    while ((h <= mid) && (j <= high)) {
        if (a[h] <= a[j]) {
            b[i] = a[h];
            h++;
        } else {
            b[i] = a[j];
            j++;
        }
        i++;
    }

    if (h > mid) {
        for (k = j; k <= high; k++) {
            b[i] = a[k];
            i++;
        }
    } else {
        for (k = h; k <= mid; k++) {
            b[i] = a[k];
            i++;
        }
    }

    for (k = low; k <= high; k++) {
        a[k] = b[k];
    }
}

void merge_sort(int low, int high) {
    int mid;
    if (low < high) {
        mid = (low + high) / 2;
        merge_sort(low, mid);
        merge_sort(mid + 1, high);
        merge(low, mid, high);
    }
}

int main() {
    int h[20], n, i;
    double clk;
    clock_t starttime, endtime;

    printf("\nEnter the number of resumes: ");
    scanf("%d", &n);

    for (i = 0; i < n; i++) {
        h[i] = rand() % 100;
        printf("The candidates' ranks are: \t%d", h[i]);
    }

    printf("\n");

    // Copy the ranks into the global array a for sorting
    for (i = 0; i < n; i++) {
        a[i] = h[i];
    }

    starttime = clock();
    merge_sort(0, n - 1);
    endtime = clock();

    clk = (double)(endtime - starttime) / CLOCKS_PER_SEC;

    printf("\nThe ranks in sorted order:\n");
    for (i = 0; i < n; i++) {
        printf("\t%d", a[i]);
    }

    printf("\nThe run time is %f seconds\n", clk);

    return 0;
}

INPUT:
Enter the number of employee records: 10

Employee IDs (randomly generated):
82930
98435
56432
12345
45678
23456
78901
34567
56789
45678
