#include <bits/stdc++.h>
using namespace std;

#define rep(i, n) for (int i = 0; i < (int)n; i++)
#define repx(i, a, b) for (int i = (int)a; i < (int)b; i++)

template<class T>
class Hungarian
{
    T inf = numeric_limits<T>::max() / 2;
    bool maxi, swapped = false;
    vector<vector<T>> cost;
    vector<int> p, way;
    vector<T> u, v;
    int l, r, j0, j1, i0;

public:

    Hungarian(int left, int right, bool maximizing)
    {
        l = left, r = right, maxi = maximizing;
        if (swapped = l > r) swap(l, r);
        cost.assign(l + 1, vector<T>(r + 1, 0));
        u.assign(l + 1, 0); v.assign(r + 1, 0);
        p.assign(r + 1, 0); way.assign(r + 1, 0);
    }

    void add_edge(int l, int r, T w)
    {
        assert(l and r);  // indices start from 1 !!
        if (swapped) swap(l, r);
        cost[l][r] = maxi ? -w : w;
    }

    // execute after all edges were added
    void calculate()
    {
        repx(i, 1, l + 1)
        {
            vector<bool> used(r + 1, false);
            vector<T> minv(r + 1, inf);
            j0 = 0, p[0] = i;

            while (p[j0])
            {
                j1 = 0, i0 = p[j0], used[j0] = true;
                T delta = inf;
                repx(j, 1, r + 1) if (!used[j])
                {
                    T cur = cost[i0][j] - u[i0] - v[j];
                    if (cur < minv[j]) minv[j] = cur, way[j] = j0;
                    if (minv[j] < delta) delta = minv[j], j1 = j;
                }
                rep(j, r + 1)
                {
                    if (used[j]) u[p[j]] += delta, v[j] -= delta;
                    else minv[j] -= delta;
                }
                j0 = j1;
            }

            while (j0) p[j0] = p[way[j0]], j0 = way[j0];
        }
    }

    // execute after executing calculate()
    T answer() { return maxi ? v[0] : -v[0]; }

    bool are_matched(int l, int r)
    {
        if (swapped) swap(l, r);
        return p[r] == l;
    }
};

int N, sz, L, R;
vector<string> S;
vector<int> P, I;
int M[27];

void get_parity(int i)
{
    string s = S[i];
    vector<bool> V(sz, 0);

    int ans = 0;
    rep(j, sz) if (!V[j])
    {
        int k = j, cnt = 1; V[k] = 1;
        while (!V[M[S[i][k] - 'a']]) { k = M[S[i][k] - 'a']; V[k] = 1; cnt++; }
        ans += (cnt - 1) % 2;
    } ans %= 2;

    if (ans) R++;
    else L++;

    P[i] = ans;
    I[i] = (ans ? R : L);
}

int main()
{
    cin >> N;

    S.resize(N);
    rep(i, N) cin >> S[i];

    sz = S[0].size();
    rep(i, sz) M[S[0][i] - 'a'] = i;

    P.resize(N); I.resize(N);
    rep(i, N) get_parity(i);

    Hungarian<int> H(L, R, 1);

    rep(i, N) repx(j, i + 1, N)
    {
        int cnt = 0;
        rep(k, sz) if (S[i][k] != S[j][k]) cnt++;

        if (P[i] && cnt == 2) H.add_edge(I[j], I[i], 1);
        if (!P[i] && cnt == 2) H.add_edge(I[i], I[j], 1);
    }

    H.calculate();
    cout << max(H.answer(), N - H.answer()) << '\n';
}