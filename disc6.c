#include <stdio.h>
#include <time.h>
#include <stdlib.h>  // For rand()

int partition(int a[], int low, int high) {
    int i, j, temp, pivot;
    pivot = a[low];
    i = low + 1;
    j = high;

    while (1) {
        while (i <= high && a[i] <= pivot) i++;
        while (a[j] > pivot) j--;
        if (i < j) {
            temp = a[i];
            a[i] = a[j];
            a[j] = temp;
        } else {
            temp = a[j];
            a[j] = a[low];
            a[low] = temp;
            return j;
        }
    }
}

void quick_sort(int a[], int low, int high) {
    int j;
    if (low < high) {
        j = partition(a, low, high);
        quick_sort(a, low, j - 1);
        quick_sort(a, j + 1, high);
    }
}

int main() {
    int i, n, a[200000];
    double clk;
    clock_t starttime, endtime;

    printf("Enter the number of student records: \n");
    scanf("%d", &n);

    for (i = 0; i < n; i++) {
        a[i] = rand() % 100;
        printf("The roll numbers are: \t%d\n", a[i]);
    }

    starttime = clock();
    quick_sort(a, 0, n - 1);
    endtime = clock();

    clk = (double)(endtime - starttime) / CLOCKS_PER_SEC;

    printf("\nSorted roll numbers are:\n");
    for (i = 0; i < n; i++) {
        printf("\t%d", a[i]);
    }
    printf("\nThe run time is %f seconds\n", clk);

    return 0;
}
INPUT: 
Enter the number of USNs: 10

USNs (randomly generated):
1234
5678
9101
2345
6789
3456
7890
4567
8901
12345
