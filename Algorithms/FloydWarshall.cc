#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

/* Max # of vertices */
#define V 50

/* for not connected nodes */
#define INF 9999999

/* Returns the all-pairs shortest path matrix using Floyd Warshall algorithm */
int ** floydWarshall (int graph[][V]) {
    /* dist = shortest path matrix. */
    int dist[V][V], i, j, k;

    /* Initialize the solution matrix same as input graph matrix. Or

       on shortest paths considering no intermediate vertex. */
    for (i = 0; i < V; i++)
        for (j = 0; j < V; j++)
            dist[i][j] = graph[i][j];

    /* Considering all numbers of intermediate vertices, from 0 to V. */
    for (k = 0; k < V; k++)
    {
        /* Source vertice index */
        for (i = 0; i < V; i++)
        {
            /* Destination vertex index */
            for (j = 0; j < V; j++)
            {
                /* Replace distance by a shorter one if available */
                if (dist[i][k] + dist[k][j] < dist[i][j])
                    dist[i][j] = dist[i][k] + dist[k][j];
            }
        }
    }
    return (dist);
}
