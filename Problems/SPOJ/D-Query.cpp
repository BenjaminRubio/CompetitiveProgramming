#include <bits/stdc++.h>
using namespace std;

#define rep(i, n) for (int i = 0; i< (int)n; i++)

int sq(int x) { return sqrt(x); }

struct Query
{
    int l, r, id;
    Query(int l, int r, int id) : l(l), r(r), id(id) {}
    bool operator<(Query &q)
    {
        return sq(l) < sq(q.l) or (sq(l) == sq(q.l) and sq(r) < sq(q.r));
    }
};

int n, q, l, r;
int a[30010], ans[200010], c[1000010];
vector<Query> queries;

int main()
{
    scanf("%d", &n);
    rep(i, n) scanf("%d", &a[i]);

    scanf("%d", &q);
    rep(i, q)
    {
        scanf("%d %d", &l, &r);
        queries.emplace_back(l - 1, r - 1, i);
    }

    sort(queries.begin(), queries.end());

    l = 0, r = 0;
    int aux = 1;
    c[a[0]] = 1;
    for (Query e : queries)
    {
        while (e.r > r) r++, c[a[r]]++, aux += (c[a[r]] == 1);
        while (e.r < r) aux -= (c[a[r]] == 1), c[a[r]]--, r--;
        while (e.l > l) aux -= (c[a[l]] == 1), c[a[l]]--, l++;
        while (e.l < l) l--, c[a[l]]++, aux += (c[a[l]] == 1);
        ans[e.id] = aux;
    }

    rep(i, q) printf("%d\n", ans[i]);;
}