#include "../Template.cpp"

struct DSU
{
    vi p; DSU(int N) : p(N, -1) {}
    int get(int x) { return p[x] < 0 ? x : p[x] = get(p[x]); } 
    bool sameSet(int a, int b) { return get(a) == get(b); }
    int size(int x) { return -p[get(x)]; }
    void unite(int x, int y)
    {
        if ((x = get(x)) == (y = get(y))) return;
        if (p[x] > p[y]) swap(x,y);
        p[x] += p[y], p[y] = x;
    }
};

// With ROLLBACK O(log(n)) ops

struct DSU
{
    vi p; DSU() {} DSU(int N) : p(N, -1) {}
    int get(int x) { return p[x] < 0 ? x : get(p[x]); }
    bool sameSet(int a, int b) { return get(a) == get(b); }
    int size(int x) { return -p[get(x)]; }
    vvi S;
    void unite(int x, int y)
    {
        if ((x = get(x)) == (y = get(y))) { S.pb({-1}); return; }
        if (p[x] > p[y]) swap(x, y);
        S.pb({x, y, p[x], p[y]});
        p[x] += p[y], p[y] = x;
    }
    void rollback()
    {
        auto a = S.back(); S.pop_back();
        if (a[0] != -1) p[a[0]] = a[2], p[a[1]] = a[3];
    }
};
