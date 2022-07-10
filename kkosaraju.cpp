#include<bits/stdc++.h>
using namespace std;

//  three step algorithm
// topological sort
// reverse the graph
// dfs from there


// to get scc we should know the order of starting dfs
// this order can be obtained by topological sort
// finish time of vertex is greater than finish time of vertex connecting to other scc
// transpose the graph so that dfs doesnt go in the other scc
// finish to of vertex connecting to ohter scc is imp

// 0-1 -> 3
// \2/

// finish time of 1 is always more
// should start dfs first
// on transposed graph


// no. of scc in transpose graph is same


bool vis[100000];
stack<int> st;
vector<int> g[100000];
vector<int> gt[100000];
int total_vertices;


void topological(int u){
    vis[u]=true;
    for(auto v:g[u]){
        if(!vis[v]){
            topological(v);
        }
    }
    st.push(u);
}


void dfs(int u){

}
void transpose(){
    for(int i=0;i<total_vertices;i++){
        for(auto v:g[i]){
            g[v].push_back(i);
        }
    }
}



void kosaraju(){
    while(!st.empty()){
        int u=st.top();
        st.pop();
        if(!vis[u]){
            dfs(u);
        }
    }
}


int main(){

}