#include <bits/stdc++.h>
using namespace std;

bool isvalid(int x, int y, int n)
{
    if (x <= 0 || y <= 0 || x > n || y > n)
        return false;
    return true;
}
int minStepToReachTarget(vector<int> &kp, vector<int> &tp, int N)
{
    // Code here
    // acc to one base indexing
    // for minimum distance think of bfs only
    queue<pair<int, int>> q;
    q.push({kp[0], kp[1]});
    int ans = 0;
    vector<int> xx{1, 1, -1, -1, 2, 2, -2, -2};
    vector<int> yy{-2, 2, 2, -2, 1, -1, 1, -1};
    bool vis[N + 1][N + 1];
    memset(vis, false, sizeof(vis));

    while (!q.empty())
    {
        int cnt = q.size();
        while (cnt--)
        {
            int x = q.front().first;
            int y = q.front().second;
            q.pop();

            if (x == tp[0] && y == tp[1])
            {
                return ans;
            }

            // visit all the neighbours
            for (int i = 0; i < 8; i++)
            {
                int nx = x + xx[i];
                int ny = y + yy[i];
                if (isvalid(nx, ny, N))
                {
                    if (!vis[nx][ny])
                    {
                        q.push({nx, ny});
                        vis[nx][ny] = true;
                    }
                }
            }
        }
        ans++;
    }
    return ans;
}