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
