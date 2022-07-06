#include <bits/stdc++.h>
using namespace std;
vector<int> g[100000 + 10];
bool vis[100000 + 10];

void add_edge(int u, int v)
{
    g[u].push_back(v);
}

void bfs(int u)
{
    queue<int> q;
    q.push(u);
    memset(vis, false, sizeof(vis));
    while (!q.empty())
    {
        int u = q.front();
        q.pop();
        vis[u] = true;
        for (auto v : g[u])
        {
            if (!vis[v])
            {
                q.push(v);
            }
        }
    }
}
int main()
{
}