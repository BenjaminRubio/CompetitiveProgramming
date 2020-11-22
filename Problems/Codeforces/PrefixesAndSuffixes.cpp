#include <bits/stdc++.h>
using namespace std;

#define rep(i, n) for (int i = 0; i < (int)n; i++)

struct SA
{
    int sz, l; vector<int> L, Lk, S, C, T;
    vector<vector<int>> N, Ilk;

    SA(string s, int n) : L(2 * n), Lk(2 * n), C(2 * n), N(2 * n, vector<int>(26, -1))
    {
        l = L[0] = 0, Lk[0] = -1, sz = 1; int p;
        for (char c : s) p = extend(c - 'A');
        Ilk.resize(sz); S.assign(sz, -1);
        rep(i, sz) if (i) Ilk[Lk[i]].push_back(i);
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

string S;
vector<pair<int, int>> ans;

int main()
{
    cin >> S; SA sa(S, S.size());

    int p = 0, i = 0;
    for (char c : S)
    {
        p = sa.N[p][c - 'A'], i++;
        if (sa.T[p]) ans.emplace_back(i, sa.size(p));
    }

    cout << ans.size() << '\n';
    for (auto &e : ans) cout << e.first << ' ' << e.second << '\n';
}