#include <stdio.h>
#include <stdint.h>
#include <limits.h>

#define V 30 // Number of vertices in the graph

// Function to find the vertex with the minimum distance value
int minDistance(uint8_t dist[], int sptSet[]) {
    int min = UINT8_MAX, min_index;

    for (int v = 0; v < V; v++) {
        if (sptSet[v] == 0 && dist[v] <= min) {
            min = dist[v];
            min_index = v;
        }
    }

    return min_index;
}

// Function to print the constructed distance array
void printPath(uint8_t parent[], int j) {
    if (parent[j] == -1)
        return;

    printPath(parent, parent[j]);

    printf(" -> %d", j);
}

// A utility function to print the constructed distance array
int printSolution(uint8_t dist[], uint8_t parent[], int start, int end) {
    printf("Shortest Path from %d to %d is: %d", start, end, dist[end]);
    printf("\nPath: %d", start);
    // Debug print statements
    for (int i = 0; i < V; i++) {
        printf("dist[%d] = %d, parent[%d] = %d\n", i, dist[i], i, parent[i]);
    }
    printPath(parent, end);
    printf("\n");
}

// Function that implements Dijkstra's single-source shortest path algorithm
void dijkstra(uint8_t graph[V][V], int start, int end) {
    uint8_t dist[V]; // The output array dist[i] holds the shortest distance from start to i
    int sptSet[V];  // sptSet[i] will be true if vertex i is included in the shortest path tree or the shortest distance from start to i is finalized
    uint8_t parent[V]; // Parent array to store the shortest path tree

    // Initialize all distances as INFINITE and sptSet[] as false
    for (int i = 0; i < V; i++) {
        dist[i] = UINT8_MAX;
        sptSet[i] = 0;
        parent[i] = -1;
    }

    // Distance of start vertex from itself is always 0
    dist[start] = 0;

    // Find shortest path for all vertices
    for (int count = 0; count < V - 1; count++) {
        // Pick the minimum distance vertex from the set of vertices not yet processed.
        int u = minDistance(dist, sptSet);

        // Mark the picked vertex as processed
        sptSet[u] = 1;

        // Update dist value of the adjacent vertices of the picked vertex.
        for (int v = 0; v < V; v++) {
            if (!sptSet[v] && graph[u][v] && dist[u] != UINT8_MAX &&
                dist[u] + graph[u][v] < dist[v]) {
                dist[v] = dist[u] + graph[u][v];
                parent[v] = u;
            }
        }
    }

    // Print the constructed distance array
    printSolution(dist, parent, start, end);
}

int main() {
    uint8_t graph[V][V] = {
        // Your graph goes here
        {0,1,0,0,0    ,0,0,0,0,0   ,0,0,0,0,0    ,0,0,0,0,0,    0,0,0,0,0,    0,0,0,0,0},//0
                    {1,0,1,0,0     ,0,0,0,0,0   ,0,0,0,0,0    ,0,0,0,0,0    ,0,0,0,0,0,    0,0,0,0,1},//1
                    {0,1,0,2,0     ,0,0,0,2,0   ,0,0,0,0,0    ,0,0,0,0,0    ,0,0,0,0,0,    0,0,0,0,0},//2
                    {0,0,2,0,2     ,0,0,0,0,0   ,0,0,0,0,0    ,0,0,0,0,0    ,0,0,0,0,0,    0,0,0,7,0},//3
                    {0,0,0,2,0,    1,5,0,0,0  ,0,0,0,0,0    ,0,0,0,0,0    ,0,0,0,0,0,    0,0,0,0,0},//4
                    {0,0,0,0,1,     0,0,0,0,0    ,0,0,0,0,0    ,0,0,0,0,0    ,0,0,0,0,0,    0,0,0,0,0},//5
                    {0,0,0,0,5,     0,0,4,0,0    ,0,0,0,0,0    ,0,0,0,0,0    ,0,0,0,0,0,    0,0,0,0,0},//6
                    {0,0,0,0,0,     0,4,0,1,0    ,0,0,0,0,0    ,0,0,0,0,0    ,0,0,0,0,0,    0,0,0,0,0},//7
                    {0,0,3,0,0,     0,0,1,0,1    ,0,0,3,0,0  ,0,0,0,0,0    ,0,0,0,0,0,    0,0,0,0,0},//9
                    {0,0,0,0,0,     0,0,0,0,1    ,0,0,0,0,0    ,0,0,0,0,0    ,0,0,0,0,0,    0,0,0,0,0},//10
                    {0,0,0,0,0,     0,0,0,0,1    ,0,0,0,0,0    ,0,0,0,0,0    ,0,0,0,0,0,    0,0,0,0,0},//11
                    {0,0,0,0,0,     0,0,0,3,0  ,0,0,0,6,0    ,0,0,0,0,6    ,0,0,0,0,0,    0,0,0,0,0},//12
                    {0,0,0,0,0,     0,0,0,0,0   ,0,0,6,0,5     ,0,0,0,0,0    ,0,0,0,0,0,    0,0,0,0,0},//13
                    {0,0,0,0,0,     0,0,0,0,0   ,0,0,0,5,0     ,1,3,0,0,0  ,0,0,0,0,0,    0,0,0,0,0},//14
                    {0,0,0,0,0,     0,0,0,0,0  ,0,0,0,0,1     ,0,0,0,0,0    ,0,0,0,0,0,    0,0,0,0,0},//15
                    {0,0,0,0,0,     0,0,0,0,0   ,0,0,0,0,3   ,0,0,1,6,0  ,0,0,0,0,0,    0,0,0,0,0},//16
                    {0,0,0,0,0,     0,0,0,0,0   ,0,0,0,0,0     ,0,1,0,0,0    ,0,0,0,0,0,    0,0,0,0,0},//17
                    {0,0,0,0,0,     0,0,0,0,0   ,0,0,0,0,0     ,0,6,0,0,6  ,0,0,0,0,0,    0,0,0,0,0},//18
                    {0,0,0,0,0,     0,0,0,0,0  ,0,0,6,0,0     ,0,0,0,6,0    ,3,0,0,0,0,  0,0,0,0,0},//19
                    {0,0,0,0,0,     0,0,0,0,0   ,0,0,0,0,0     ,0,0,0,0,3  ,0,1,0,0,1,    0,0,0,0,3},//20
                    {0,0,0,0,0,     0,0,0,0,0  ,0,0,0,0,0     ,0,0,0,0,0    ,1,0,1,1,0,    0,0,0,0,0},//21
                    {0,0,0,0,0,     0,0,0,0,0  ,0,0,0,0,0     ,0,0,0,0,0    ,0,1,0,0,0,    0,0,0,0,0},//22
                    {0,0,0,0,0,     0,0,0,0,0  ,0,0,0,0,0     ,0,0,0,0,0    ,0,1,0,0,0,    0,0,0,0,0},//23
                    {0,0,0,0,0,     0,0,0,0,0  ,0,0,0,0,0     ,0,0,0,0,0    ,1,0,0,0,0,    3,0,0,0,0},//24
                    {0,0,0,0,0,     0,0,0,0,0  ,0,0,0,0,0     ,0,0,0,0,0    ,0,0,0,0,3,    0,4,0,0,0},//25
                    {0,0,0,0,0,     0,0,0,0,0   ,0,0,0,0,0     ,0,0,0,0,0    ,0,0,0,0,0,    4,0,1,3,0},//26
                    {0,0,0,0,0,     0,0,0,0,0  ,0,0,0,0,0     ,0,0,0,0,0    ,0,0,0,0,0,    0,1,0,0,0},//27
                    {0,0,0,1,0,     0,0,0,0,0  ,0,0,0,0,0     ,0,0,0,0,0    ,0,0,0,0,0,    0,3,0,0,2},//28
                    {0,1,0,0,0,     0,0,0,0,0  ,0,0,0,0,0     ,0,0,0,0,0    ,3,0,0,0,0,  0,0,0,2,0}
    };

    int start = 0; // Specify the start node
    int end = 23;  // Specify the end node

    dijkstra(graph, start, end);

    return 0;
}
