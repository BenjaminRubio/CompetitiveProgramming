#include <bits/stdc++.h>
using namespace std;

int n;
vector<vector<int>> g;
vector<bool> visited;

// Recursive (set visited before)
void dfs(int u)
{
    visited[u] = true;
    for(int v : g[u]) if(!visited[v]) dfs(v);
}

// Iterative
void dfs(int root)
{
    stack<int> s;
    s.push(root);
    visited.assign(n, false);
    visited[root] = true;
    while (!s.empty())
    {
        int u = s.top(); s.pop();
        for (int v : g[u]) if (!visited[v])
        {
            visited[u] = true;
            s.push(v);
        }
    }
}