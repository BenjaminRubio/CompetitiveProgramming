#include <bits/stdc++.h>
using namespace std;

#define rep(i, n) for (int i = 0; i < (int)n; i++)

int n;
vector<string> all;
map<string, vector<string>> g;
map<string, bool> visited;
vector<string> ans;
string line, s;

void dfs(string v)
{
    visited[v] = true;
    for (string u : g[v]) if (!visited[u]) dfs(u);
    ans.push_back(v);
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin >> n;
    
    rep(i, n + 1)
    {
        getline(cin, line);
        if (!i) continue;

        vector<string> v;
        string aux = "";
        for (char c : line)
        {
            if (c == ':') continue;
            if (c == ' ') { v.push_back(aux); aux.clear(); }
            else aux += c;
        }
        v.push_back(aux);

        visited[v[0]] = false;
        if (g.find(v[0]) == g.end()) g[v[0]] = vector<string>();
        rep(j, v.size() - 1)
        {
            if (g.find(v[j + 1]) == g.end()) g[v[j + 1]] = vector<string>();
            g[v[j + 1]].push_back(v[0]);
        }
    }

    cin >> s;
    dfs(s);
    reverse(ans.begin(), ans.end());

    for (string e : ans) cout << e << '\n';
}