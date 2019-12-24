#include <iostream>
using namespace std;

#include "AdjacencyMatrix.h"

void initializeCitiesArray(string cities[]);
int minDistance(int dist[], bool sptSet[]);
void printSolution(int dist[], int n, string* cities);
void dijkstra(AdjacencyMatrix graph, string* cities);

int main()
{
    AdjacencyMatrix matrix;

    string cityArray[MAX_VERT];
    initializeCitiesArray(cityArray);

    dijkstra(matrix, cityArray);

    return 0;
}

void initializeCitiesArray(string cities[])
{
    //To hold the city names
    cities[0] = "SFO";
    cities[1] = "LAX";
    cities[2] = "LAS";
    cities[3] = "PHX";
    cities[4] = "DEN";
    cities[5] = "JFK";
}
int minDistance(int dist[], bool sptSet[]) 
{ 
   // Initialize min value 
   int min = INFINITY, min_index; 
   
   for (int v = 0; v < MAX_VERT; v++) 
     if (sptSet[v] == false && dist[v] <= min) 
         min = dist[v], min_index = v; 
   
   return min_index; 
} 
   
// A utility function to print the constructed distance array 
void printSolution(int dist[], int n, string* cities) 
{
    cout << "Here are the costs after using Dijkstra’s algorithm:\n";
    for (int i = 0; i < MAX_VERT; i++) 
    {
      cout << "Cost from SFO to " << cities[i] << " is $" << dist[i] << endl;
    }
} 

//Adopted from https://www.geeksforgeeks.org/dijkstras-shortest-path-algorithm-greedy-algo-7/

// Function that implements Dijkstra's single source shortest path algorithm 
// for a graph represented using adjacency matrix representation 
void dijkstra(AdjacencyMatrix graph, string* cities) 
{ 
   
     int dist[MAX_VERT];
     
     bool sptSet[MAX_VERT]; // sptSet[i] will be true if vertex i is included in shortest 
                     // path tree or shortest distance from src to i is finalized 
   
     // Initialize all distances as INFINITE and stpSet[] as false 
     for (int i = 0; i < MAX_VERT; i++) 
        dist[i] = INFINITY, sptSet[i] = false; 
   
     // Distance of source vertex from itself is always 0 
     dist[0] = 0; 
   
     // Find shortest path for all vertices 
     for (int count = 0; count < MAX_VERT-1; count++) 
     { 
       // Pick the minimum distance vertex from the set of vertices not 
       // yet processed. u is always equal to src in the first iteration. 
       int u = minDistance(dist, sptSet); 
   
       // Mark the picked vertex as processed 
       sptSet[u] = true; 
   
       // Update dist value of the adjacent vertices of the picked vertex. 
       for (int v = 0; v < MAX_VERT; v++) 
   
         // Update dist[v] only if is not in sptSet, there is an edge from  
         // u to v, and total weight of path from src to  v through u is  
         // smaller than current value of dist[v] 
         if (!sptSet[v] && graph.getWeight(u,v) && dist[u] != MAX_VERT  
                                       && dist[u]+graph.getWeight(u, v) < dist[v]) 
            dist[v] = dist[u] + graph.getWeight(u, v); 
     } 
   
     // print the constructed distance array 
     printSolution(dist, MAX_VERT, cities); 
}
