#include <bits/stdc++.h>
using namespace std;

// compare all words
// create the graph
// print the topological sort of it

vector<char> g[26];

void topological_sort()
{
}
void fun(vector<string> v)
{
    for (int i = 0; i < v.size() - 1; i++)
    {
        string word1 = v[i];
        string word2 = v[i + 1];
        for (int j = 0; j < min(word1.size(), word2.size()); j++)
        {
            if (word1[j] != word2[j])
            {
                // create edge
                g[word1[j]].push_back(word2[j]);
            }
        }
    }
}