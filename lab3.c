#include <stdio.h>
#include <time.h>
#include <stdlib.h>  // Include for rand() and srand()

int main() {
    int i, n, a[1000], key, bottom, top, mid, j, temp;
    double clk;
    clock_t starttime, endtime;

    printf("Enter the number of Products: ");
    scanf("%d", &n);

    // Generate random Product IDs and print them
    for(i = 0; i < n; i++) {
        a[i] = rand() % 100;
        printf("The Product ID is: \t%d\n", a[i]);
    }

    // Bubble Sort to sort the Product IDs
    for(i = 0; i < n - 1; i++) {
        for(j = 0; j < n - i - 1; j++) {
            if(a[j] > a[j + 1]) {
                temp = a[j];
                a[j] = a[j + 1];
                a[j + 1] = temp;
            }
        }
    }

    printf("\nSorted Product ID List is:\n");
    for(i = 0; i < n; i++) {
        printf("\t%d", a[i]);
    }
    printf("\n");

    printf("Enter the Product ID to be searched: ");
    scanf("%d", &key);

    starttime = clock();
    
    bottom = 0;  // Initialize bottom to 0 for binary search
    top = n - 1; // Initialize top to n - 1 for binary search

    do {
        mid = (bottom + top) / 2;
        if (key < a[mid]) {
            top = mid - 1;
        } else if (key > a[mid]) {
            bottom = mid + 1;
        }
    } while (key != a[mid] && bottom <= top);

    if (key == a[mid]) {
        printf("Product found!!\n");
        printf("\nProduct %d found in position: %d\n", key, mid + 1);
    } else {
        printf("\nSearch failed\n%d not found\n", key);
    }

    endtime = clock();
    clk = (double)(endtime - starttime) / CLOCKS_PER_SEC;
    printf("Time taken: %f seconds\n", clk);

    return 0;
}
// INPUT: 
// Enter the number of products: 10

// Product ID: 35
// Product ID: 20
// Product ID: 85
// Product ID: 55
// Product ID: 76
// Product ID: 64
// Product ID: 25
// Product ID: 92
// Product ID: 10
// Product ID: 45

// Sorted Product ID List:
// 10 20 25 35 45 55 64 76 85 92 

// Enter the Product ID to be searched: 45
