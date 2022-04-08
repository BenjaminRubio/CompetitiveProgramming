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

int N;
vi T, D;

int main()
{
    ios::sync_with_stdio(0); cin.tie(0);

    cin >> N;

    T.resize(N); D.resize(N);
    rep(i, N) cin >> T[i] >> D[i];

    vp V;
    rep(i, N) V.eb(D[i], i);

    sort(V.rbegin(), V.rend());

    int now = V[0].ff;
    for (auto &e : V)
    {
        now = min(now, e.ff);
        now -= T[e.ss];
        if (now < 0)
        {
            cout << "*\n";
            return 0;
        }
    }

    reverse(V.begin(), V.end());

    vi I(N, 1);
    int off = 0;
    rep(_, N)
    {
        vi P(N); int j = 0;
        rep(i, N - _) P[V[i].ss] = j++;

        // rep(i, N) cerr << P[i] << ' ';
        // cerr << '\n';

        vi M(N - _);

        int m = INT_MAX, now = 0;
        rep(i, N - _)
        {
            M[i] = m;
            now += T[V[i].ss];
            m = min(m, V[i].ff - (now + off));
        }

        // rep(i, N - _) cerr << M[i] << ' ';
        // cerr << '\n';

        rep(i, N) if (I[i] && M[P[i]] >= T[i])
        {
            I[i] = 0;
            vp V_;
            rep(j, N - _) if (V[j].ss != i) V_.pb(V[j]);
            swap(V, V_);
            cout << i + 1 << (_ < N - 1 ? " " : "");
            off += T[i];
            break;
        }
    }
    cout << '\n';
}
