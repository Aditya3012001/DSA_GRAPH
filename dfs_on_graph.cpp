#include <bits/stdc++.h>
using namespace std;

vector<int> g[100000 + 10];
bool vis[100000 + 10]; // vis is maintained to prevent from cycling in graph

void add_edge(int u, int v)
{
    g[u].push_back(v);
}

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
}