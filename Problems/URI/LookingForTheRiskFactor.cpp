#include <bits/stdc++.h>
using namespace std;

typedef vector<int> vi;
typedef vector<int>::iterator iter;

#define rep(i, n) for (int i = 0; i < (int)n; i++)
#define repx(i, a, b) for (int i = a; i < (int)b; i++)

class WaveTree
{
    vector<vector<int>> r0;
    int n, s;
    vector<int> arrCopy;

    void build(iter b, iter e, int l, int r, int u)
    {
        if (l == r)
            return;
        int m = (l + r) / 2;
        r0[u].reserve(e - b + 1);
        r0[u].push_back(0);
        for (iter it = b; it != e; ++it)
            r0[u].push_back(r0[u].back() + (*it <= m));
        iter p = stable_partition(b, e, [=](int i) { return i <= m; });
        build(b, p, l, m, u * 2);
        build(p, e, m + 1, r, u * 2 + 1);
    }

    int q, w;
    int range(int a, int b, int l, int r, int u)
    {
        if (r < q or w < l)
            return 0;
        if (q <= l and r <= w)
            return b - a;
        int m = (l + r) / 2, za = r0[u][a], zb = r0[u][b];
        return range(za, zb, l, m, u * 2) +
               range(a - za, b - zb, m + 1, r, u * 2 + 1);
    }

public:
    WaveTree(vector<int> arr, int sigma)
    {
        n = arr.size();
        s = sigma;
        r0.resize(s * 2);
        arrCopy = arr;
        build(arr.begin(), arr.end(), 0, s - 1, 1);
    }

    int range(int x, int y, int a, int b)
    {
        if (y < x or b <= a)
            return 0;
        q = x;
        w = y;
        return range(a, b, 0, s - 1, 1);
    }
};

const int MAX_NUM = 1e5;
int q, n, k;
vi max_prime;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    max_prime.assign(MAX_NUM + 1, 0);
    repx(i, 2, MAX_NUM + 1) if (max_prime[i] == 0) for (int j = i; j <= MAX_NUM; j += i)
        max_prime[j] = i;

    WaveTree wt(max_prime, MAX_NUM + 1);

    cin >> q;
    rep(i, q)
    {
        cin >> n >> k;

        if (k >= n)
        {
            cout << n - 1 << '\n';
            continue;
        }

        int ans = wt.range(0, k, 2, n + 1);

        cout << ans << '\n';
    }
}
