#include <bits/stdc++.h>
using namespace std;

// backtrcking algo for graph coloring
int c;
vector<int> g[1000];
int color[1000];
bool rec(int u)
{

    // try different colors for this vertex
    bool flag = true;
    for (int i = 0; i < c; i++)
    {
        for (auto v : g[u])
        {
            if (color[v] == i)
            {
                flag = false;
            }
        }
        if (flag)
        {
            color[u] = i;
            for (auto v : g[u])
            {
                if (rec(v))
                    return true;
            }
            color[u] = 0;
        }
    }
    return false;
}

// two color problem
// also a check for bipartite graph

// bfs solution and dfs solution

bool dfs(int u, int c)
{
    color[u] = c;

    // check all neighbouring vertex;
    bool ans = true;
    for (auto v : g[u])
    {
        if (color[v] == color[u])
            return false;
        if (color[v] == -1)
            ans = ans & dfs(v, c ^ 1);
    }
}
