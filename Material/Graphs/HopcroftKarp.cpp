#include "../Template.cpp"

class Hopcroft
{
    vi U, dist;
    vvi g;
    int inf = 1e9;

    bool bfs() {
        queue<int> q;
        for (int u : U) if (match[u] == nil) dist[u] = 0, q.push(u);
        else dist[u] = inf;
        dist[nil] = inf;
        while (!q.empty())
        {
            int u = q.front(); q.pop();
            if (u != nil) for (int v : g[u]) if (dist[match[v]] == inf)
            {
                dist[match[v]] = dist[u] + 1;
                q.push(match[v]);
            }
        }
        return (dist[nil] != inf);
    }

    bool dfs(int u) {
        if (u == nil)
            return true;
        for (int v : g[u]) if (dist[match[v]] == dist[u]+1 and dfs(match[v]))
        {
            match[v] = u, match[u] = v;
            return true;
        }
        dist[u] = inf;
        return false;
    }

public:
    vi match;
    int nil, isPerfect, matchSize = 0;

    // gg is a bidirectional graph, UU has the nodes in the left partition
    Hopcroft(vector<vi> &gg, vi &UU) 
    {
        g = gg; U = UU; nil = g.size();
        match.assign(g.size() + 1, nil);
        dist.assign(g.size() + 1, inf);
        while (bfs()) for (int u : U) if (match[u] == nil and dfs(u))
            matchSize++;
        isPerfect = (matchSize == U.size() and g.size() == U.size() * 2);
    }
};
