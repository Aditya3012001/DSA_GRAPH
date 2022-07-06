#include <bits/stdc++.h>
using namespace std;

int snakesAndLadders(vector<vector<int>> &board)
{
    int n = board.size();

    vector<int> v(n * n, 0);

    queue<int> q;
    q.push(0);

    int dist = 0;

    while (!q.empty())
    {
        int s = q.size();

        while (s--)
        {
            int x = q.front();
            q.pop();
            // cout<<endl<<x<<" ";

            if (v[x] == 1)
                continue;

            v[x] = 1;

            if (x == n * n - 1)
                return dist;
            // cout<<endl;
            for (int i = x + 1; i <= min(x + 6, n * n - 1); i++)
            {

                int a = i / n;
                int b = i % n;
                if (a % 2 == 1)
                    b = n - 1 - b;
                a = n - 1 - a;

                // cout<<i<<" -> "<<board[a][b]<<" | ";
                if (board[a][b] == -1)
                    q.push(i);
                else
                    q.push(board[a][b] - 1);
            }
        }
        dist++;
    }
    return -1;
}