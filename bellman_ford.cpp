#include<bits/stdc++.h>
using namespace std;

// it is like a dp solution
// path of length n is made from length n-1

// works for negative weights 
// works well for distributed systems
// time complexity o(ve)

vector<pair<int,int>> g[1000];
void bellman_ford(){
    // relax all edges n-1 times
    int n;
    int dist[n+1];

    for(int i=0;i<n;i++){
        for(int u=0;u<n;u++){
            for(auto x:g[u]){
                int v=x.first;
                int w=x.second;
                if(dist[v]>dist[u]+w){
                    dist[v]=dist[u]+w;
                }
            }
        }
    }
    // do one more iteration to check for neegative weights
    

}