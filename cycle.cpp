#include <bits/stdc++.h>
using namespace std;

vector<int> g[100000 + 10];
bool vis[100000 + 10];
int dist[100000 + 10];
int par[100000 + 10];
int color[100000 + 10];
bool recstack[100000 + 10];

void add_edge(int u, int v)
{
    g[u].push_back(v);
}

// find cycle in undirected graph is easy

bool detect_cycle_directed(int u)
{
    // this doesnt work because order of visiting vertices might change
    // ex 2->1->0
    // we visit 0 first
    // when we go through 2 it will return true but should return false;
    // hence maintain recursion stack as well
    vis[u] = true;
    bool ans = false;
    for (auto v : g[u])
    {
        if (vis[u])
            return true;
        if (detect_cycle_directed(v))
            return true;
    }
    return false;
}

bool correct_cycle_directed(int u)
{
    // this problem can be solved using only one array as well
    // color[x]==1 return true;
    // color[x]==0 go for next vis
    // permanently mark color[u]=2
    vis[u] = true;
    recstack[u] = true;

    for (auto v : g[u])
    {
        if (vis[v] && recstack[v])
            return true;
        if (!vis[v] && correct_cycle_undirected(v))
            return true;
    }
    recstack[u] = false;
    return false;
}

bool undirected(int u, int par)
{
    vis[u] = true;
    for (auto v : g[u])
    {
        if (vis[v] && v != par)
        {
            // this means back edge is present
            return true;
        }
        if (!vis[v] && undirected(v, u))
            return true;
    }
    return false;
}

// bfs algo for cycle detection of directed graph=== khans algo for topological sort
// for undirected graph maintain parent[] vector

bool iscycle()
{
    int n;
    for (int i = 0; i < n; i++)
    {
        if (!vis[i])
        {
            if (undirected(i, -1))
                return true;
        }
    }
    return false;
}
