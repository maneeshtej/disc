#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_PHONE_NUMBERS 1000

void insertion_sort(int arr[], int n) {
    int i, j, key;
    for (i = 1; i < n; i++) {
        key = arr[i];
        j = i - 1;
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}

void generate_random_phone_numbers(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        arr[i] = rand() % 1000000000;  // Random 10-digit numbers
    }
}

int main() {
    int n;
    int arr[MAX_PHONE_NUMBERS];
    double clk;
    clock_t starttime, endtime;

    printf("Enter the number of phone numbers: ");
    scanf("%d", &n);

    generate_random_phone_numbers(arr, n);

    printf("\nPhone Numbers:\n");
    for (int i = 0; i < n; i++) {
        printf("%d\n", arr[i]);
    }

    starttime = clock();
    insertion_sort(arr, n);
    endtime = clock();

    clk = (double)(endtime - starttime) / CLOCKS_PER_SEC;

    printf("\nSorted Phone Numbers:\n");
    for (int i = 0; i < n; i++) {
        printf("%d\n", arr[i]);
    }

    printf("\nThe run time is %f seconds\n", clk);

    return 0;
}

// INPUT: 
// Enter the number of phone numbers: 5

// Phone Numbers:
// 123456789
// 987654321
// 456789123
// 654321987
// 789123456
