#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define fastio()                  \
    ios_base::sync_with_stdio(0); \
    cin.tie(0);                   \
    cout.tie(0);

vector<pair<int, ll>> g[200000 + 10];
bool vis[200000 + 10];
ll dist[200000 + 10];
int n, m;

void add_edge(int u, int v, int w)
{
    g[u].push_back({v, w});
}
void initialise()
{
    for (int i = 1; i <= n; i++)
    {
        dist[i] = 1e18;
        vis[i] = false;
    }
}
void dijkastras()
{
    initialise();
    dist[1] = 0;
    priority_queue<pair<ll, ll>, vector<pair<ll, ll>>, greater<pair<ll, ll>>> pq;
    pq.push({0, 1});
    while (!pq.empty())
    {
        int u = pq.top().second;
        pq.pop();
        if (vis[u])
            continue;
        vis[u] = true;

        for (auto x : g[u])
        {
            int v = x.first;
            ll w = x.second;
            if (!vis[v] && dist[v] > dist[u] + w)
            {
                dist[v] = dist[u] + w;
                pq.push({dist[v], v});
            }
        }
    }
}
int main()
{
    fastio();
    cin >> n >> m;
    for (int i = 0; i < m; i++)
    {
        int a, b, c;
        cin >> a >> b >> c;
        add_edge(a, b, c);
    }
    dijkastras();
    for (int i = 1; i <= n; i++)
        cout << dist[i] << " ";
}