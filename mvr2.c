#include <stdio.h>
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
