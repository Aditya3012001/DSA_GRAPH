#include <bits/stdc++.h>
using namespace std;

// it np hard problem
// have polynomial solution for dag
<<<<<<< HEAD
=======
// tpoplogical sort and then relax the edges
>>>>>>> fifth

bool vis[100000];
stack<int> st;
vector<int> g[100000];
vector<int> gt[100000];
<<<<<<< HEAD
int total_vertices;
=======
int dist[100000];
int total_vertices;
int ninf;
>>>>>>> fifth

void topological(int u)
{
    vis[u] = true;
    for (auto v : g[u])
    {
        if (!vis[v])
        {
            topological(v);
        }
    }
    st.push(u);
<<<<<<< HEAD
=======
}

void longest(){
    while(!st.empty()){
        int u=st.top();
        st.pop();
        if(dist[u]==ninf)continue;

        for(auto v:g[u]){
            // update distance for all of them
            int w;
            if(dist[v]<dist[u]+w){
                dist[v]=dist[u]+w;
            }
        }
    }
>>>>>>> fifth
}