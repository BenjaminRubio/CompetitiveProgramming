#include <bits/stdc++.h>
using namespace std;

int S; // Size of buckets (generally sqrt(N))

struct Query
{
    int l, r, id;
    Query(int l, int r, int id) : l(l), r(r), id(id) {}
    bool operator<(Query &q)
    {
        return l / S < q.l / S or (l / S == q.l / S and r < q.r);
    }
};
