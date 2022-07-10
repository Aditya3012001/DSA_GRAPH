#include<bits/stdc++.h>
using namespace std;

// shortest distance between every pair of vertices
// all pairs shortest path problem

/*
 The idea is to one by one pick all vertices 
 and updates all shortest paths which include 
 the picked vertex as an intermediate vertex 
 in the shortest path. When we pick vertex number k
  as an intermediate vertex, we already have considered
   vertices {0, 1, 2, .. k-1} as intermediate vertices.
    For every pair (i, j)
*/

void flyod_warshall(){
    int v;
    int inf;
    int dist[v][v];
    for(int i=0;i<v;i++){
        for(int j=0;j<v;j++){
            for(int k=0;k<v;k++){
                if(dist[i][k]!=inf&&dist[k][j]!=inf&&
                   dist[i][j]>dist[i][k]+dist[k][j]){

                   }
            }
        }
    }
}