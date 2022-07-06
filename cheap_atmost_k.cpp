#include <bits/stdc++.h>
using namespace std;

int findCheapestPrice(int n, vector<vector<int>> &flights, int src, int dest, int k)
{
    // atmost k stops

    vector<int> dist(n, 1e7);
    vector<int> temp(n, 1e7);
    dist[src] = 0;
    temp[src] = 0;

    for (int i = 0; i <= k; i++)
    {
        for (auto x : flights)
        {
            int u = x[0];
            int v = x[1];
            int w = x[2];
            if (temp[v] > dist[u] + w)
            {
                temp[v] = dist[u] + w;
            }
        }
        for (int j = 0; j < n; j++)
        {

            dist[j] = temp[j];
        }
    }
    return dist[dest] == 1e7 ? -1 : dist[dest];
}