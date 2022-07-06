#include <bits/stdc++.h>
using namespace std;

bool visited[100][100] = {false};
void dfs(vector<vector<int>> &image, int x, int y, int newc, int old, int n, int m)
{
    if (x >= n || y >= m || x < 0 || y < 0 || visited[x][y] || image[x][y] != old)
        return;
    visited[x][y] = true;
    image[x][y] = newc;

    dfs(image, x + 1, y, newc, old, n, m);
    dfs(image, x - 1, y, newc, old, n, m);
    dfs(image, x, y + 1, newc, old, n, m);
    dfs(image, x, y - 1, newc, old, n, m);
}
vector<vector<int>> floodFill(vector<vector<int>> &image, int sr, int sc, int newColor)
{
    int n = image.size(), m = image[0].size();
    dfs(image, sr, sc, newColor, image[sr][sc], n, m);
    return image;
}