#include <bits/stdc++.h>
using namespace std;

#define ff first
#define ss second
#define rep(i, n) for (int i = 0; i < (int)n; i++)

const int Nmax = 2001;
const int Mmax = 2001;
const int NIL = -1;

struct Edge
{
    int nod;
    int urm;
};

Edge Graph[2 * Mmax];
int head[2 * Nmax];

int match[2 * Nmax];
bool vis[2 * Nmax];
bool use[Nmax];

int V1, V2, E;
int countEdges = 0;

void addEdge(int x, int y)
{
    Graph[countEdges] = {y, head[x]};
    head[x] = countEdges;
    countEdges++;
}

bool dfs(int nod)
{
    if (use[nod])
        return false;

    use[nod] = true;

    for (int p = head[nod]; p != NIL; p = Graph[p].urm)
    {
        int son = Graph[p].nod;

        if (!match[son])
        {
            match[nod] = son;
            match[son] = nod;

            return true;
        }
    }

    for (int p = head[nod]; p != NIL; p = Graph[p].urm)
    {
        int son = Graph[p].nod;

        if (dfs(match[son]))
        {
            match[nod] = son;
            match[son] = nod;

            return true;
        }
    }

    return false;
}

int Hopcroft_Karp()
{
    bool valid;

    do
    {
        valid = false;

        for (int i = 1; i <= V1; ++i)
            use[i] = false;

        for (int i = 1; i <= V1; ++i)
            if (!match[i])
                valid |= dfs(i);

    } while (valid);

    int matching = 0;

    for (int i = 1; i <= V1; ++i)
        if (match[i])
            matching++;

    return matching;
}

void mark(int nod, int side)
{
    if (side == 0) /// vertex from L
    {
        vis[nod] = 1;

        for (int p = head[nod]; p != NIL; p = Graph[p].urm)
        {
            int son = Graph[p].nod;

            if (!vis[son] && match[nod] != son) /// not a edge from the matching
                mark(son, side ^ 1);
        }
    }
    else
    {
        vis[nod] = 1;

        for (int p = head[nod]; p != NIL; p = Graph[p].urm)
        {
            int son = Graph[p].nod;

            if (!vis[son] && match[nod] == son) /// edge from the matching
                mark(son, side ^ 1);
        }
    }
}

string sep1, in, c1, c2;
map<string, int> mapping1, mapping2;
vector<pair<string, string>> e;

int main()
{
    int id1 = 0, id2 = 0;

    while (cin >> sep1 >> in)
    {
        c1 = c2 = "";
        if (in[in.size() - 2] != ')')
        {
            rep(i, in.size() - 1) c1 += in[i];
            if (mapping1.find(c1) == mapping1.end())
                mapping1[c1] = id1++;
        }

        else
        {
            bool first = true;
            rep(i, in.size() - 2)
            {
                if (first and in[i] == '(')
                {
                    first = false;
                    continue;
                }
                if (first)
                    c1 += in[i];
                else
                    c2 += in[i];
            }

            if (mapping1.find(c1) == mapping1.end())
                mapping1[c1] = id1++;
            if (mapping2.find(c2) == mapping2.end())
                mapping2[c2] = id2++;
            e.push_back({c1, c2});
        }

        cin >> sep1;
    }

    rep(i, e.size())
    {
        c1 = e[i].ff; c2 = e[i].ss;
        addEdge(mapping1[c1], mapping2[c2] + id1);
    }

    V1 = id1; V2 = id2;

    cout << Hopcroft_Karp() << '\n';
}