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

const int INF = 1e9;

int N, K, aux;

int V[510], p[510];

int main()
{
    ios::sync_with_stdio(0); cin.tie(0);

    cin >> N >> K;
    memset(V, 0, sizeof V);
    memset(p, -1, sizeof p);

    queue<int> q; q.push(N); V[N] = 1;
    while (!q.empty())
    {
        int l = q.front(); q.pop();
        int o = N - l;
        for (int k = K, c = K; k >= -K; k -= 2, c--)
        {
            if (c <= l && (K - c) <= o)
            {
                if (!V[l - k])
                {
                    q.push(l - k);
                    V[l - k] = 1;
                    p[l - k] = l;
                }
            }
        }
    }
    
    if (!V[0]) { cout << -1 << endl; return 0; }

    stack<int> L;
    int l = 0;
    while (l != -1) { L.push(l); l = p[l]; }

    queue<int> F, O;
    rep(i, N) F.push(i);

    int ans = 0;
    while (L.size() > 1)
    {
        l = L.top(); L.pop();
        int k = L.top() - l;

        int a = (K + k) / 2;
        int b = (K - k) / 2;

        cout << "? ";
        rep(_, a)
        {
            cout << O.front() + 1 << ' ';
            F.push(O.front()); O.pop();
        }
        rep(_, b)
        {
            cout << F.front() + 1 << ' ';
            O.push(F.front()); F.pop();
        }
        cout << endl;

        cin >> aux; ans ^= aux;
    }

    cout << "! " << ans << endl;
}
