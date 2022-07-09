#include<bits/stdc++.h>
using namespace std;


// graph is a set of vertices and edges 
// for spanning tree we take all the vertices and a subset of edges
// size of that subset is v-1
// tree should not have a cycle

// total number of spanning trees
// eC(v-1) - number of cycles  

// greedy algos for spanning trees 
// prims and kruskal

// prims : always select the minimum edge which is connected 
vector<pair<int,int>> g[1000];
void prims(int v,int src){
    int dist[v+1];
    bool vis[v+1];
    int parent[v+1];

    priority_queue<pair<int,int>,vector<pair<int,int>,greater<pair<int,int>>>>  pq;

    pq.push({0,src});

    while(!pq.empty()){
        // do this for only n-1 times 
        int u=pq.top().second;
        pq.pop();
        vis[u]=true;


        // relax the edges

        for(auto x:g[u]){
            int v=x.first;
            int w=x.second;

            if(!vis[v]&&dist[v]>w){
                // dist[v]>w for situation when vertix is in pq but a min edge weight connecting to it joins
                dist[v]=w;
                pq.push({w,v});
                parent[v]=u;
            }
        }
    }
}