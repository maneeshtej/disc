1) #include<stdio.h>
#include<time.h>

void bfs(int a[10][10], int n, int source) {
    int s[10], q[10], f = 0, r = -1, t, v;

    // Initialize all vertices as unvisited
    for(v = 0; v < n; v++) {
        s[v] = 0;
    }

    // Enqueue the source node
    q[++r] = source;
    s[source] = 1;

    printf("The BFS traversal is:\n");

    // BFS loop
    while(f <= r) {
        t = q[f++];  // Dequeue the front element

        for(v = 0; v < n; v++) {
            if(a[t][v] == 1 && s[v] == 0) {
                q[++r] = v;  // Enqueue unvisited neighbors
                printf("%d -> %d\n", t, v);  // Print the traversal
                s[v] = 1;  // Mark neighbor as visited
            }
        }
    }
}

int main() {
    int a[10][10], n, i, j, s;
    double clk;
    clock_t starttime, endtime;

    printf("\nEnter the number of cities: ");
    scanf("%d", &n);

    printf("\nEnter the matrix representation:\n");
    for(i = 0; i < n; i++) {
        for(j = 0; j < n; j++) {
            scanf("%d", &a[i][j]);
        }
    }

    printf("\nEnter the source city: ");
    scanf("%d", &s);

    starttime = clock();
    bfs(a, n, s);
    endtime = clock();

    clk = (double)(endtime - starttime) / CLOCKS_PER_SEC;
    printf("\nThe run time is %f seconds\n", clk);

    return 0;
}

INPUT: 

Enter the number of cities (nodes): 4

Enter the adjacency matrix:
0 1 0 1
0 0 1 0
1 0 0 0
0 1 0 0

2) #include <stdio.h>
#include <time.h>

#define MAX 50

int a[MAX][MAX], n, count = 0, reach[MAX], pos[MAX];

// Function to read the adjacency matrix
void read_matrix() {
    printf("\nEnter the adjacency matrix (Enter 0/1):\n");
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= n; j++) {          
            if(i != j) {
                printf("(%d,%d): ", i, j);
                scanf("%d", &a[i][j]);
            }
        }
    }
}

// Function to find the next adjacent vertex
int adjacent(int i) {
    for(int j = pos[i] + 1; j <= n; j++) {
        if(a[i][j] == 1) {
            pos[i] = j;
            return j;
        }
    }
    pos[i] = n + 1;  // Mark end of adjacent vertices
    return 0;
}

// Function to check if a vertex has been reached
int checkreach(int u) {
    for(int i = 1; i <= count; i++) {
        if(reach[i] == u) {
            return 1;  // Vertex already reached
        }
    }
    return 0;  // Vertex not yet reached
}

// Function for Depth First Search
void dfs(int v) {
    int u;
    reach[++count] = v;  // Mark the current vertex as reached
    u = adjacent(v);     // Find the first adjacent vertex
    while(u) {
        if(checkreach(u) == 0) {
            dfs(u);       // Recursively perform DFS on the adjacent vertex
        }
        u = adjacent(v); // Find the next adjacent vertex
    }
}

int main() {
    int v;
    double clk;
    clock_t starttime, endtime;

    printf("\n\t\t\tDEPTH FIRST SEARCH\n");
    printf("\nEnter number of lands to be surveyed: ");
    scanf("%d", &n);

    // Initialize position array
    for(int i = 1; i <= n; i++) {
        pos[i] = 0;
    }

    read_matrix();

    printf("\nEnter the starting land number: ");
    scanf("%d", &v);

    starttime = clock();
    dfs(v);
    endtime = clock();

    clk = (double)(endtime - starttime) / CLOCKS_PER_SEC;

    printf("\nVertices reached from the given vertex are:\n");
    for(int i = 1; i <= count; i++) {
        printf("%d\t", reach[i]);
    }
    printf("\n");

    printf("The run time is %f seconds\n", clk);

    return 0;
}


INPUT: 
Enter number of nodes: 4

Enter the adjacency matrix (Enter 0/1):
(0,0):0
(0,1):1
(0,2):0
(0,3):1
(1,0):0
(1,1):0
(1,2):1
(1,3):0
(2,0):1
(2,1):0
(2,2):0
(2,3):0
(3,0):0
(3,1):1
(3,2):0
(3,3):0
Enter the starting node: 0

3) #include <stdio.h>
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
INPUT: 
Enter the number of products: 10

Product ID: 35
Product ID: 20
Product ID: 85
Product ID: 55
Product ID: 76
Product ID: 64
Product ID: 25
Product ID: 92
Product ID: 10
Product ID: 45

Sorted Product ID List:
10 20 25 35 45 55 64 76 85 92 

Enter the Product ID to be searched: 45

4) #include <stdio.h>
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

INPUT: 
Enter the number of phone numbers: 5

Phone Numbers:
123456789
987654321
456789123
654321987
789123456

5) #include <stdio.h>
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

6) #include <stdio.h>
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

7) #include <stdio.h>
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

INPUT:
Enter the number of resumes: 5

Resumes (randomly generated):
65
23
87
45
78

8) #include<stdio.h>
#include<string.h>
#include<conio.h>
#define MAX 500

int t[MAX];

void shifttable(char p[]) {
    int i, j, m;
    m = strlen(p);
    for(i = 0; i < MAX; i++)
        t[i] = m;
    for(j = 0; j < m - 1; j++)
        t[(int)p[j]] = m - 1 - j;  // Cast p[j] to int for proper indexing
}

int horspool(char src[], char p[]) {
    int i, k, m, n;
    n = strlen(src);
    m = strlen(p);
    printf("\nLength of text = %d", n);
    printf("\nLength of pattern = %d", m);
    i = m - 1;
    
    while(i < n) {
        k = 0;
        while((k < m) && (p[m - 1 - k] == src[i - k]))
            k++;
        if(k == m)
            return (i - m + 1);  // Return starting index
        else
            i += t[(int)src[i]];  // Cast src[i] to int for proper indexing
    }
    return -1;
}

void main() {
    char src[100], p[100];
    int pos;
    
    printf("Enter the text in which pattern is to be searched:\n");
    gets(src);  // gets is unsafe, but as per the instruction, we will not change it
    printf("Enter the pattern to be searched:\n");
    gets(p);
    
    shifttable(p);
    pos = horspool(src, p);
    
    if(pos >= 0)
        printf("\nThe desired pattern was found starting from position %d", pos + 1);
    else
        printf("\nThe pattern was not found in the given text");
    
    getch();  // For pausing the output on screen
}

INPUT:
Enter the text in which pattern is to be searched:
abcababcabca
Enter the pattern to be searched:
abca

9) #include<stdio.h>
#include<time.h>

double clk;
clock_t starttime, endtime;

int min(int a, int b) {
    if (a < b)
        return a;
    else
        return b;
}

void floyd(int n, int W[10][10], int D[10][10]) {
    int i, j, k;
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            D[i][j] = W[i][j];
        }
    }
    
    for (k = 0; k < n; k++) {
        for (i = 0; i < n; i++) {
            for (j = 0; j < n; j++) {
                D[i][j] = min(D[i][j], D[i][k] + D[k][j]);
            }
        }
    }
}

int main() {
    int i, j, n, D[10][10], W[10][10];
    
    printf("Enter the number of vertices: \n");
    scanf("%d", &n);
    
    printf("Enter the cost matrix: \n");
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            scanf("%d", &W[i][j]);
        }
    }
    
    starttime = clock();
    floyd(n, W, D);
    endtime = clock();
    
    clk = (double)(endtime - starttime) / CLOCKS_PER_SEC;
    
    printf("All pair shortest path matrix is:\n");
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            printf("%d\t", D[i][j]);
        }
        printf("\n");
    }
    
    printf("\nThe run time is %f seconds\n", clk);

    return 0;
}

INPUT:
Enter the number of vertices: 
4
Enter the cost matrix:
0 3 999 7
8 0 2 999
5 999 0 1
2 999 999 0

10) #include <stdio.h>
#include <time.h>

int max(int x, int y) {
    return (x > y) ? x : y;
}

int knap(int n, int w[10], int value[10], int m, int v[10][10]) {
    int i, j;
    for (i = 0; i <= n; i++) {
        for (j = 0; j <= m; j++) {
            if (i == 0 || j == 0) {
                v[i][j] = 0;
            } else if (j < w[i]) {
                v[i][j] = v[i - 1][j];
            } else {
                v[i][j] = max(v[i - 1][j], value[i] + v[i - 1][j - w[i]]);
            }
        }
    }

    printf("\nThe table for solving the knapsack problem using dynamic programming is:\n");
    for (i = 0; i <= n; i++) {
        for (j = 0; j <= m; j++) {
            printf("%d\t", v[i][j]);
        }
        printf("\n");
    }

    return v[n][m];  // Return the final optimal solution
}

int main() {
    double clk;
    clock_t starttime, endtime;
    int v[10][10], n, i, j, w[10], value[10], m, result;

    printf("Enter the number of items: ");
    scanf("%d", &n);

    printf("Enter the weights of %d items:\n", n);
    for (i = 1; i <= n; i++) {
        scanf("%d", &w[i]);
    }

    printf("Enter the values of %d items:\n", n);
    for (i = 1; i <= n; i++) {
        scanf("%d", &value[i]);
    }

    printf("Enter the capacity of the basket: ");
    scanf("%d", &m);

    // Initialize the table with 0
    for (i = 0; i <= n; i++) {
        for (j = 0; j <= m; j++) {
            v[i][j] = 0;
        }
    }

    // Start measuring time
    starttime = clock();

    // Call the knapsack function
    result = knap(n, w, value, m, v);

    // End time measurement
    endtime = clock();

    clk = (double)(endtime - starttime) / CLOCKS_PER_SEC;

    // Print the optimal solution and runtime
    printf("Optimal solution for the knapsack problem is %d\n", v[n][m]);
    printf("Execution time: %f seconds\n", clk);

    return 0;
}

INPUT:
Enter the number of items: 
4
Enter the weights of 4 items:
2 3 4 5
Enter the values of 4 items:
3 4 5 6
Enter the capacity of the basket:
5


11) #include <stdio.h>
#include <time.h>

struct edge {
    int u, v, cost;
};
typedef struct edge edge;

int find(int v, int parent[]) {
    while (parent[v] != v) {
        v = parent[v];
    }
    return v;
}

void union_ij(int i, int j, int parent[]) {
    if (i < j) {
        parent[j] = i;
    } else {
        parent[i] = j;
    }
}

void kruskal(int n, edge e[], int m) {
    int count, k, i, sum, u, v, j, t[10][2], p, parent[10];
    edge temp;
    count = 0;
    k = 0;
    sum = 0;

    // Sort edges by cost using bubble sort
    for (i = 0; i < m; i++) {
        for (j = 0; j < m - 1; j++) {
            if (e[j].cost > e[j + 1].cost) {
                temp = e[j];
                e[j] = e[j + 1];
                e[j + 1] = temp;
            }
        }
    }

    // Initialize parent array
    for (i = 0; i < n; i++) {
        parent[i] = i;
    }

    p = 0;

    // Kruskal's algorithm
    while (count != n - 1) {
        u = e[p].u;
        v = e[p].v;
        i = find(u, parent);
        j = find(v, parent);

        if (i != j) {
            t[k][0] = u;
            t[k][1] = v;
            k++;
            count++;
            sum += e[p].cost;
            union_ij(i, j, parent);
        }
        p++;
    }

    if (count == n - 1) {
        printf("Spanning tree exists\n");
        printf("The spanning tree is as follows:\n");
        for (i = 0; i < n - 1; i++) {
            printf("%d  %d\t\n", t[i][0], t[i][1]);
        }
        printf("\nThe cost of the spanning tree is %d\n", sum);
    } else {
        printf("\nSpanning tree does not exist\n");
    }
}

int main() {
    int n, m, a, b, i, cost;
    double clk;
    clock_t starttime, endtime;
    edge e[20];

    printf("Enter the number of vertices: ");
    scanf("%d", &n);

    printf("Enter the number of edges:\n");
    scanf("%d", &m);

    printf("Enter the edge list (u v cost):\n");
    for (i = 0; i < m; i++) {
        scanf("%d%d%d", &a, &b, &cost);
        e[i].u = a;
        e[i].v = b;
        e[i].cost = cost;
    }

    starttime = clock();
    kruskal(n, e, m);
    endtime = clock();

    clk = (double)(endtime - starttime) / CLOCKS_PER_SEC;
    printf("The time taken is %f seconds\n", clk);

    return 0;
}
INPUT:
Enter the number of vertices: 
4
Enter the number of edges:
5
Enter the edge list (u v cost):
1 2 1
1 3 4
2 3 2
3 4 3
2 4 5

12) #include <stdio.h>
#include <time.h>

#define MAX 10

// Function to choose the next vertex with the smallest distance
int choose(int dist[], int s[], int n) {
    int min = 100, j = 1, w;
    for (w = 1; w <= n; w++) {
        if ((dist[w] < min) && (s[w] == 0)) {
            min = dist[w];
            j = w;
        }
    }
    return j;
}

// Function to compute shortest paths using Dijkstra's algorithm
void spath(int v, int cost[][MAX], int dist[], int n) {
    int s[MAX], w, u, i, num;

    // Initialize the distance and set arrays
    for (i = 1; i <= n; i++) {
        s[i] = 0;
        dist[i] = cost[v][i];
    }
    s[v] = 1;  // Mark the source vertex as visited
    dist[v] = 0;  // Distance to itself is 0

    // Loop to update distances
    for (num = 2; num <= n; num++) {
        u = choose(dist, s, n);
        s[u] = 1;

        for (w = 1; w <= n; w++) {
            if ((dist[u] + cost[u][w] < dist[w]) && !s[w]) {
                dist[w] = dist[u] + cost[u][w];
            }
        }
    }
}

int main() {
    int i, j, cost[MAX][MAX], dist[MAX], n, v;
    double clk;
    clock_t starttime, endtime;

    printf("\nEnter number of vertices: ");
    scanf("%d", &n);

    printf("\nEnter the cost adjacency matrix:\n");
    for (i = 1; i <= n; i++) {
        for (j = 1; j <= n; j++) {
            scanf("%d", &cost[i][j]);
        }
    }

    printf("\nEnter the source vertex: ");
    scanf("%d", &v);

    // Record start time
    starttime = clock();
    spath(v, cost, dist, n);
    // Record end time
    endtime = clock();

    // Output the shortest distances
    printf("\nShortest distances from vertex %d:\n", v);
    for (i = 1; i <= n; i++) {
        printf("%d to %d = %d\n", v, i, dist[i]);
    }

    // Calculate and print the time taken
    clk = (double)(endtime - starttime) / CLOCKS_PER_SEC;
    printf("The time taken is %f seconds\n", clk);

    return 0;
}

INPUT:
Enter number of vertices: 
5
Enter the cost adjacency matrix:
0 6 999 1 999
6 0 5 2 2
999 5 0 2 5
1 2 2 0 1
999 2 5 1 0
Enter the source vertex: 
1

13) #include <stdio.h>
#include <math.h>

#define FALSE 0
#define TRUE 1

int x[20]; // Array to store the positions of queens

// Function to check if the queen can be placed in row `k` and column `i`
int place(int k, int i) {
    int j;
    for (j = 1; j < k; j++) {
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
    printf("\nThe solution to the N Queens problem is:\n");
    nqueens(1, n); // Start the process with the first queen
    return 0;
}

INPUT:
Enter the number of queens: 
4

14) #include <stdio.h>

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

