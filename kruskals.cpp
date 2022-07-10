#include<bits/stdc++.h>
using namespace std;


// select minimum cost edge and make sure it doesnt form a cycle
int find_parent(int u,int parent[]){
    if(parent[u]==u)return u;
    return  find_parent(parent[u],parent);
}

int union_find(int u,int v,int parent[]){

}

bool cmp(vector<int> a,vector<int> b){
    return a[2]<b[2];
}
int kruskal(int n,vector<vector<int>> edges){
    int parent[n+1];
    for(int i=1;i<-n;i++)parent[i]=i;
    int cost=0;

    for(int i=0;i<edges.size();i++){
        int u=edges[i][0];
        int v=edges[i][1];

        int pu=find_parent(u,parent);
        int pv=find_parent(v,parent);


        if(pu!=pv){
            // no cycle and can be included
            cost+=edges[i][2];
            parent[pv]=pu;
        }
    }
    return cost;
}