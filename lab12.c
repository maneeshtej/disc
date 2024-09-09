#include <stdio.h>
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

// INPUT:
// Enter number of vertices: 
// 5
// Enter the cost adjacency matrix:
// 0 6 999 1 999
// 6 0 5 2 2
// 999 5 0 2 5
// 1 2 2 0 1
// 999 2 5 1 0
// Enter the source vertex: 
// 1
