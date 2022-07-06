#include <bits/stdc++.h>
using namespace std;

// it np hard problem
// have polynomial solution for dag

bool vis[100000];
stack<int> st;
vector<int> g[100000];
vector<int> gt[100000];
int total_vertices;

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
}