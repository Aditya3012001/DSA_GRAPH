#include <bits/stdc++.h>
using namespace std;

vector<int> g[100000 + 10];
bool vis[100000 + 10]; // vis is maintained to prevent from cycling in graph
// this also sort vertices according to their finish time
void add_edge(int u, int v)
{
    g[u].push_back(v);
}
stack<int> st;  // for topological sort
void dfs(int u)
{
    vis[u] = true;
    for (auto v : g[u])
    {
        if (!vis[v])
        {
            dfs(v);
        }
    }
    st.push(u);  // ensures that u is pushed only after all its neighbour are pushed in stackt
    // 1->0<-4 this case will not work without stack

}


// khans algorithm is also there to do it
// is count of visited nodes is not one that means there is a cycle
// indegree and outdegree

