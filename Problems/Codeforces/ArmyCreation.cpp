#include <bits/stdc++.h>
using namespace std;

#define rep(i, n) for (int i = 0; i < (int)n; i++)

class WT
{
    int n, s;
    typedef vector<int>::iterator iter;
    vector<vector<int>> r0;
    vector<int> arrCopy;

    void build(iter b, iter e, int l, int r, int u)
    {
        if (l == r) return;
        int m = (l + r) / 2;
        r0[u].reserve(e - b + 1);
        r0[u].push_back(0);
        for (iter it = b; it != e; ++it)
            r0[u].push_back(r0[u].back() + (*it <= m));
        iter p = stable_partition(b, e, [=](int i) { return i <= m; });
        build(b, p, l, m, u * 2); build(p, e, m + 1, r, u * 2 + 1);
    }

    int q, w;
    int range(int a, int b, int l, int r, int u)
    {
        if (r < q or w < l) return 0;
        if (q <= l and r <= w) return b - a;
        int m = (l + r) / 2, za = r0[u][a], zb = r0[u][b];
        return range(za, zb, l, m, u * 2) + range(a - za, b - zb, m + 1, r, u * 2 + 1);
    }

public:
    WT(vector<int> arr, int sigma)
    {
        n = arr.size(); s = sigma; r0.resize(s * 2);
        arrCopy = arr;
        build(arr.begin(), arr.end(), 0, s - 1, 1);
    }

    int range(int x, int y, int a, int b)
    {
        if (y < x or b <= a) return 0;
        q = x, w = y;
        return range(a, b, 0, s - 1, 1);
    }
};

int N, K, A, Q, l, r;
vector<queue<int>> I;
vector<int> P;

int main()
{
    cin >> N >> K;

    I.assign(100001, {});
    P.assign(N, 0);
    rep(i, N)
    {
        cin >> A;
        I[A].push(i);
        if (I[A].size() == K + 1) { P[i] = I[A].front() + 1; I[A].pop(); }
    }

    WT wt(P, 100000);

    cin >> Q; int lst = 0;
    rep(_, Q)
    {
        cin >> l >> r;
        l = (l + lst) % N, r = (r + lst) % N;
        if (l > r) swap(l, r);
        lst = wt.range(0, l, l, r + 1);
        cout << lst << '\n';
    }
}