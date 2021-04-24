
// vector implementation
struct SA
{
    int sz, l; vi L, Lk, S, C, T;
    vector<vi> N, Ilk;

    SA(string s, int n) : L(2 * n), Lk(2 * n), C(2 * n), N(2 * n, vi(26, -1))
    {
        l = L[0] = 0, Lk[0] = -1, sz = 1; int p;
        for (char c : s) p = extend(c - 'A');
        Ilk.resize(sz); S.assign(sz, -1);
        rep(i, sz) if (i) Ilk[Lk[i]].pb(i);
        T.assign(sz, 0); while (p != -1) T[p] = 1, p = Lk[p];
    }
    int extend(char c)
    {
        int cur = sz++, p = l; C[cur] = 0, L[cur] = L[l] + 1;
        while (p != -1 && N[p][c] == -1) N[p][c] = cur, p = Lk[p];
        if (p == -1) { Lk[cur] = 0, l = cur; return cur; }
        int q = N[p][c];
        if (L[p] + 1 == L[q]) { Lk[cur] = q, l = cur; return cur; }
        int w = sz++; C[w] = 1, L[w] = L[p] + 1, Lk[w] = Lk[q], N[w] = N[q];
        while (p != -1 && N[p][c] == q) N[p][c] = w, p = Lk[p];
        Lk[q] = Lk[cur] = w, l = cur; return cur;
    }
    int size(int p)
    {
        if (S[p] != -1) return S[p];
        for (int i : Ilk[p]) S[p] += size(i);
        return S[p] += (1 - C[p]) + 1;
    }
};

// 101 vector implementation
struct SA
{
    int sz, l; vi L, Lk;
    vector<vi> N, Ilk;

    SA(string s, int n) : L(2 * n), Lk(2 * n), N(2 * n, vi(26, -1))
    {
        l = L[0] = 0, Lk[0] = -1, sz = 1; int p;
        for (char c : s) p = extend(c - 'A');
    }
    int extend(char c)
    {
        int cur = sz++, p = l; L[cur] = L[l] + 1;
        while (p != -1 && N[p][c] == -1) N[p][c] = cur, p = Lk[p];
        if (p == -1) { Lk[cur] = 0, l = cur; return cur; }
        int q = N[p][c];
        if (L[p] + 1 == L[q]) { Lk[cur] = q, l = cur; return cur; }
        int w = sz++; L[w] = L[p] + 1, Lk[w] = Lk[q], N[w] = N[q];
        while (p != -1 && N[p][c] == q) N[p][c] = w, p = Lk[p];
        Lk[q] = Lk[cur] = w, l = cur; return cur;
    }
};

// 101 map implementation
struct SA
{
    int sz, l; vi L, Lk;
    vector<map<char, int>> N;

    SA(string s, int n) : L(2 * n), Lk(2 * n), N(2 * n)
    {
        l = L[0] = 0, Lk[0] = -1, sz = 1;
        for (char c : s) extend(c);
    }
    void extend(char c)
    {
        int cur = sz++, p = l; L[cur] = L[l] + 1;
        while (p != -1 && !N[p].count(c)) N[p][c] = cur, p = Lk[p];
        if (p == -1) { Lk[cur] = 0, l = cur; return; }
        int q = N[p][c];
        if (L[p] + 1 == L[q]) { Lk[cur] = q, l = cur; return; }
        int w = sz++; L[w] = L[p] + 1, Lk[w] = Lk[q], N[w] = N[q];
        while (p != -1 && N[p][c] == q) N[p][c] = w, p = Lk[p];
        Lk[q] = Lk[cur] = w, l = cur;
    }
};