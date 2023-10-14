
#include <limits.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include "DIJKSTRA.h"




int minDistance(int dist[], bool sptSet[],int V)
{
	
	int min = INT_MAX, min_index,v;

	for ( v = 0; v < V; v++)
		if (sptSet[v] == false && dist[v] <= min)
			min = dist[v], min_index = v;

	return min_index;
}


void printSolution(int dist[],int V)
{
	int i;
	printf("Vertex \t\t Distance from Source\n");
	for ( i = 0; i < V; i++)
		printf("%d \t\t\t\t %d\n", i, dist[i]);
}


int dijkstra()
{
	
	int V; // Size of the square matrix
    printf("Enter the size of the cost matrix: ");
    scanf("%d", &V);

 
    int graph[V][V],i,j;

    printf("Enter the elements of the cost matrix:\n");
    for ( i = 0; i < V; i++) {
        for ( j = 0; j < V; j++) {
            printf("Enter element at position (%d, %d): ", i, j);
            scanf("%d", &graph[i][j]);
        }
    }
	
	int src=0;
	
	int dist[V],count; 
	
	bool sptSet[V]; 
	for ( i = 0; i < V; i++)
		dist[i] = INT_MAX, sptSet[i] = false;

	dist[src] = 0;


	for ( count = 0; count < V - 1; count++) {
		
		int u = minDistance(dist, sptSet,V),v;

		
		sptSet[u] = true;

		
		for ( v = 0; v < V; v++)

		
			if (!sptSet[v] && graph[u][v]
				&& dist[u] != INT_MAX
				&& dist[u] + graph[u][v] < dist[v])
				dist[v] = dist[u] + graph[u][v];
	}

	printSolution(dist,V);
}



