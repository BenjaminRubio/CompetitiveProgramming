#include <bits/stdc++.h>
using namespace std;
    
#define rep(i, n) for (int i = 0; i < (int)n; i++)
#define ff first
#define ss second
    
const int MAXN = 200000;
vector<int> g[MAXN]; // graph
int depth[MAXN]; // bfs depth per node
int n, m, k, a, x, y;
vector<bool> S;
    
void bfs(int s) {
    memset(depth, -1, sizeof(int) * n); // init depth with -1
    queue<int> q; q.push(s); // init queue and add 's' (starting node)
    depth[s] = 0; // s will have depth 0
    while (!q.empty()) { // while there are nodes in the queue
        int u = q.front(); q.pop(); // extract the first node 'u' from the queue
        for (int v : g[u]) { // for each neighbor 'v' of 'u'
            if (depth[v] == -1) { // if 'v' has not been visited yet -> visit it
                depth[v] = depth[u] + 1;
                q.push(v);
            }
        }
    }
}
    
int main()
{
    cin >> n >> m >> k;
    
    S.assign(n, 0);
    rep(i, k)
    {
        cin >> a;
        S[a - 1] = 1;
    }
    
    bool done = false;
    rep(i, m)
    {
        cin >> x >> y; x--; y--;
        g[x].push_back(y);
        g[y].push_back(x);
        if (S[x] and S[y]) done = true;
    }
    
    bfs(0); // bfs2(n - 1);

    if (done)
    {
        cout << depth[n - 1] << '\n';
        return 0;
    }
    
    multiset<pair<int, int>> ms; 
    rep(i, n) if (S[i]) ms.insert({depth[i], i});

    int last = -1, aux = INT_MAX, id1, id2, id_;
    for (auto e : ms)
    {
        if (last != -1 and e.ff - last < aux)
        {
            id1 = e.ss; id2 = id_;
            aux = e.ff - last;
        }

        last = e.ff; id_ = e.ss;
    }
    
    g[id1].push_back(id2);
    g[id2].push_back(id1);
    bfs(0);
    
    cout << depth[n - 1] << '\n';
}