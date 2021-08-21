#include <bits/stdc++.h>
using namespace std;

using ul = unsigned long long;
using ll = long long;
using db = double;

using pii = pair<int, int>;
using pll = pair<ll, ll>;
using pdd = pair<db, db>;

using vp = vector<pii>;
using vi = vector<int>;
using vl = vector<ll>;
using vd = vector<db>;

#define rep(i, n) for (int i = 0; i < (int)n; i++)
#define repx(i, a, b) for (int i = (int)a; i < (int)b; i++)
#define all(x) begin(x), end(x)
#define eb emplace_back
#define pb push_back
#define mp make_pair
#define ff first
#define ss second

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
        for (; i < t.size(); i += i & (-i)) t[i] += v;
    }
    void update(int i, int j, int v) { update(i, v); update(j + 1, -v); }
};

int N;
vi H, L, R;

int main()
{
    ios::sync_with_stdio(0); cin.tie(0);

    cin >> N;

    H.resize(N); rep(i, N) cin >> H[i];

    L.resize(N); R.resize(N);
    stack<pii> S;
    rep(i, N)
    {
        while (!S.empty() && S.top().ff < H[i]) S.pop();
        L[i] = (S.empty() ? -1 : S.top().ss);
        S.emplace(H[i], i);
    }
    while (!S.empty()) S.pop();

    for (int i = N - 1; i >= 0; i--)
    {
        while (!S.empty() && S.top().ff < H[i]) S.pop();
        R[i] = (S.empty() ? -1 : S.top().ss);
        S.emplace(H[i], i);
    }
    while (!S.empty()) S.pop();
    
    FT ft(N);

    rep(i, N)
    {
        if (L[i] != -1)
        {
            int l = i - (i - L[i] - 1) / 2;
            ft.update(l + 1, i, 1);
        }
        else ft.update(1, i, 1);
        if (R[i] != -1)
        {
            int r = i + (R[i] - i - 1) / 2;
            ft.update(i + 2, r + 1, 1);
        }
        else ft.update(i + 2, N + 1, 1);
    }

    rep(i, N) cout << ft.query(i + 1) << (i < N - 1 ? " " : "");
    cout << '\n';
}
