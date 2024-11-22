#include <stdio.h>
#include <limits.h>

#define INF INT_MAX

// Dijkstra's Algorithm
void dijkstra(int graph[5][5], int V, int src) {
    int dist[V]; 
    int visited[V];

    for (int i = 0; i < V; i++) {
        dist[i] = INF;
        visited[i] = 0;
    }
    dist[src] = 0;

    for (int i = 0; i < V - 1; i++) {
        int min = INF, minIndex;

        for (int v = 0; v < V; v++) {
            if (!visited[v] && dist[v] <= min) {
                min = dist[v];
                minIndex = v;
            }
        }

        visited[minIndex] = 1;

        for (int v = 0; v < V; v++) {
            if (!visited[v] && graph[minIndex][v] != 0 && dist[minIndex] != INF && dist[minIndex] + graph[minIndex][v] < dist[v]) {
                dist[v] = dist[minIndex] + graph[minIndex][v];
            }
        }
    }

    printf("Dijkstra's Algorithm:\n");
    for (int i = 0; i < V; i++) {
        printf("Vertex %d -> Distance %d\n", i, dist[i]);
    }
}

// Bellman-Ford Algorithm
void bellmanFord(int edges[8][3], int V, int E, int src) {
    int dist[V];

    for (int i = 0; i < V; i++) {
        dist[i] = INF;
    }
    dist[src] = 0;

    for (int i = 0; i < V - 1; i++) {
        for (int j = 0; j < E; j++) {
            int u = edges[j][0];
            int v = edges[j][1];
            int weight = edges[j][2];

            if (dist[u] != INF && dist[u] + weight < dist[v]) {
                dist[v] = dist[u] + weight;
            }
        }
    }

    // Check for negative weight cycle
    for (int j = 0; j < E; j++) {
        int u = edges[j][0];
        int v = edges[j][1];
        int weight = edges[j][2];

        if (dist[u] != INF && dist[u] + weight < dist[v]) {
            printf("Graph contains negative weight cycle\n");
            return;
        }
    }

    printf("Bellman-Ford Algorithm:\n");
    for (int i = 0; i < V; i++) {
        printf("Vertex %d -> Distance %d\n", i, dist[i]);
    }
}

int main() {
    int V = 5; 

    int graph[5][5] = {
        {0, 6, 0, 7, 0},
        {0, 0, 5, 8, -4},
        {0, -2, 0, 0, 0},
        {0, 0, -3, 0, 9},
        {2, 0, 7, 0, 0}
    };

    int edges[8][3] = {
        {0, 1, 6}, {0, 3, 7}, {1, 2, 5}, {1, 3, 8},
        {1, 4, -4}, {3, 2, -3}, {4, 0, 2}, {4, 2, 7}
    };
    int E = 8; 

    int src = 0; 

    dijkstra(graph, V, src);

    printf("\n");

    bellmanFord(edges, V, E, src);

    return 0;
}
