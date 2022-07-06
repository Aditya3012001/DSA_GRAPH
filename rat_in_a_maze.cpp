#include <bits/stdc++.h>
using namespace std;

vector<string> res;
bool vis[10 + 1][10 + 1];
void rec(int i, int j, string ans, vector<vector<int>> grid, int n)
{
    if (i >= n || j >= n || i < 0 || j < 0 || grid[i][j] == 0 || vis[i][j] == true)
        return;
    if (i == n - 1 && j == n - 1)
    {
        res.push_back(ans);
        return;
    }
    vis[i][j] = true;
    rec(i - 1, j, ans + 'U', grid, n);
    rec(i, j - 1, ans + 'L', grid, n);
    rec(i, j + 1, ans + 'R', grid, n);
    rec(i + 1, j, ans + 'D', grid, n);
    vis[i][j] = false; // remove it from recusrion stack
}
vector<string> findPath(vector<vector<int>> &m, int n)
{
    // Your code goes here
    res.clear();
    string ans = "";
    memset(vis, false, sizeof(vis));
    rec(0, 0, ans, m, n);
    return res;
}