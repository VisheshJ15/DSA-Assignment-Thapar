#include <stdio.h>
#define INF 999999

void dijkstra(int n, int graph[10][10], int src) {
    int dist[10], visited[10];
    int i, j, count, minDist, nextNode;

    // Initialize distances & visited array
    for (i = 0; i < n; i++) {
        dist[i] = graph[src][i];
        visited[i] = 0;
    }

    dist[src] = 0;        // Distance to source = 0
    visited[src] = 1;     // Mark source visited
    count = 1;

    // Find shortest paths for all nodes
    while (count < n) {
        minDist = INF;

        // Pick the nearest unvisited vertex
        for (i = 0; i < n; i++) {
            if (!visited[i] && dist[i] < minDist) {
                minDist = dist[i];
                nextNode = i;
            }
        }

        visited[nextNode] = 1;

        // Update distances of adjacent vertices
        for (i = 0; i < n; i++) {
            if (!visited[i]) {
                if (minDist + graph[nextNode][i] < dist[i]) {
                    dist[i] = minDist + graph[nextNode][i];
                }
            }
        }
        count++;
    }

    // Print shortest distances
    printf("\nShortest distances from source node %d:\n", src);
    for (i = 0; i < n; i++) {
        printf("To node %d = %d\n", i, dist[i]);
    }
}

int main() {
    int n, graph[10][10], src;
    printf("Enter number of vertices: ");
    scanf("%d", &n);

    printf("\nEnter adjacency matrix (enter %d for INF if no edge):\n", INF);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &graph[i][j]);
        }
    }

    printf("\nEnter source vertex: ");
    scanf("%d", &src);

    dijkstra(n, graph, src);
    return 0;
}