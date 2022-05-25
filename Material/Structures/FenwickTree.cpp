#include "../Template.cpp"

// 1 - indexed / inclusive - inclusive

// Queries puntuales y Updates por rango
// xor
// Queries por rango y Updates puntuales
struct FT
{
    vi t;
    FT(int N) { t.resize(N + 1, 0); }
    int query(int i)
    {
        int ans = 0;
        for (; i; i -= i & (-i)) ans += t[i];
        return ans;
    }
    int query(int i, int j) { return query(j) - query(i - 1); }
    void update(int i, int v)
    {
        int s = query(i, i); // Sets
        for (; i < t.size(); i += i & (-i)) t[i] += v - s;
    }
    void update(int i, int j, int v) { update(i, v); update(j + 1, -v); }
};
