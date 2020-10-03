#include <bits/stdc++.h>
using namespace std;

#define rep(i, n) for (int i = 0; i < (int)n; i++)
#define repx(i, a, b) for (int i = (int)a; i < (int)b; i++)
#define ff first
#define ss second

const int MAXN = 1e5 + 1;

int N, a, C[MAXN];
vector<int> D[MAXN];
bool A[MAXN];
long long M[MAXN];

void solve(int l, int r, vector<int> &arr, vector<pair<int, int>> &v)
{
    if (l == r)
    {
        if (!v.empty())
        {
            cerr << arr[l] << ": ";
            for (auto &x : v) cerr << x.ff << ' ';
            cerr << '\n';
        }
        for (auto &x : v) if (__gcd(x.ff, arr[l]) == 1) M[x.ff] = x.ff * arr[l];
        return;
    }

    int m = (l + r) / 2;
    for (auto &x : v) for (int i : D[x.ff]) C[i] = 0;
    repx(k, m + 1, r + 1) for (int i : D[arr[k]]) C[i]++;

    cerr << l << ' ' << r << '\n';
    vector<pair<int, int>> v1, v2;
    for (auto &x : v)
    {
        int c = r - m;
        for (int i : D[x.ff]) c -= C[i] * (D[i].size() & 1 ? -1 : 1);
        if (c) v2.push_back(x);
        else v1.push_back(x);
        cerr << x.ff << ": " << c << "   ";
    }
    cerr << '\n';

    solve(l, m, arr, v1), solve(m + 1, r, arr, v2);
}

int main()
{
    repx(i, 1, MAXN + 1) for (int j = i; j < MAXN; j += i) D[j].push_back(i);

    cin >> N;

    int mx = 1;
    rep(_, N) { cin >> a; A[a] = 1, mx = max(mx, a); }

    long long ans = mx;
    vector<int> arr; vector<pair<int, int>> v;
    repx(i, 1, mx)
    {
        arr.clear(); v.clear();

        for (int j = i; j < MAXN; j += i) if (A[j])
            arr.push_back(j / i), v.emplace_back(j / i, v.size());

        cerr << arr.size() << '\n';
        for (int x : arr) cerr << x << ' ';
        cerr << '\n';

        if (!arr.empty()) solve(0, arr.size() - 1, arr, v);

        // for (int x : arr) cerr << x << ' ';
        // cerr << '\n';
        for (int x : arr) ans = max(ans, M[x]);
        cerr << ans << '\n';
    }

    cout << ans << '\n';

    int i1, i2;
    repx(i, 1, mx + 1) repx(j, 1, mx + 1) if (A[i] && A[j] && i * j / __gcd(i, j) > ans)
    {
        ans = i * j / __gcd(i, j);
        i1 = i, i2 = j;
    } 
    cerr << ans << ' ' << i1 << ' ' << i2 << '\n';
}