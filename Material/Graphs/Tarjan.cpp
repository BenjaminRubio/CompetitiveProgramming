#include "../Template.cpp"

vvi G;
vi D, L;

void dfs(int u, int p, int d)
{
    D[u] = L[u] = d;
    for(int v : G[u]) if (v != p)
    {
        if (D[v] == -1)
        {
            dfs(v, u, d + 1);
            if (L[v] > D[u]) {} // (u - v) cut edge
            L[u] = min(L[u], L[v]);
        }
        else L[u] = min(L[u], D[v]);
    }
}

int rc = 0;
void dfs(int u, int p, int d)
{
    D[u] = L[u] = d;
    for (int v : G[u]) if (v != p)
    {
        if (D[v] == -1)
        {
            dfs(v, u, d + 1);
            if ((p == -1 && ++rc == 2) || (p != -1 && L[v] >= d)) {} // u is AP
            L[u] = min(L[u], L[v]); 
        }
        else if (D[v] < d) L[u] = min(L[u], D[v]);
    }
}

stack<pii> S;
void dfs(int u, int p, int d)
{
    D[u] = L[u] = d;
    for(int v : G[u]) if (v != p)
    {
        if (D[v] == -1)
        {
            S.emplace(u, v); dfs(v, u, d + 1);
            if (p == -1 or L[v] >= d) while (1) // BCC found
            {
                pii e = S.top(); S.pop();
                if (e == make_pair(u, v)) break;
            }
            L[u] = min(L[u], L[v]); 
        }
        else if (D[v] < d) { S.emplace(u, v); L[u] = min(L[u], D[v]); }
    }
}
