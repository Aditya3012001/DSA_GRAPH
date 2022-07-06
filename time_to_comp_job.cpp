#include <bits/stdc++.h>
using namespace std;

vector<int> g[100000 + 10];
bool vis[100000 + 10]; // vis is maintained to prevent from cycling in graph
int indegree[100000 + 10];
int n;

void add_edge(int u, int v)
{
    g[u].push_back(v);
    indegree[v]++;
}

void fun()
{
    queue<int> q;
    int job[n];
    for (int i = 0; i < n; i++)
    {
        if (indegree[i] == 0)
        {
            q.push(i);
            job[i] = 0;
        }
    }

    while (!q.empty())
    {
        int u = q.front();
        for (auto v : g[u])
        {
            indegree[v]--;
            if (indegree[v] == 0)
            {
                q.push(v);
                job[v] = job[u] + 1;
            }
        }
    }
}