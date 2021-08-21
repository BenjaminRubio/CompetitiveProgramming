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

int N; ll x;
string n1, n2, s;
map<string, int> M;
map<int, string> M_;
vector<vector<pair<int, double>>> G;
vector<double> V, C;

double cost(int s, int t, double c)
{
    V[s] = 1;
    if (s == t) return c;
    for (auto v : G[s]) if (!V[v.ff])
    {
        double aux = c;
        if (v.ss > 0) aux *= v.ss;
        else aux /= -v.ss;
        if ((aux = cost(v.ff, t, aux)) > 0) return aux;
    }
    return -1;
}

int main()
{
    ios::sync_with_stdio(0); cin.tie(0);

    while (cin >> N && N)
    {
        M.clear(), M_.clear();

        rep(i, N) { cin >> n1; M[n1] = i; M_[i] = n1; }

        G.assign(N, {});
        rep(_, N - 1)
        {
            cin >> n1 >> s >> x >> n2;
            G[M[n1]].eb(M[n2], -x);
            G[M[n2]].eb(M[n1], x);
        }

        C.resize(N);
        rep(t, N)
        {
            bool flag = 1;
            rep(s, N) 
            {
                V.assign(N, 0);
                C[s] = cost(s, t, 1);
                if (C[s] < 0.9999) flag = 0;
            }

            if (flag) break;
        }

        vector<pair<ll, int>> E;
        rep(i, N) E.eb(round(C[i]), i);
        
        sort(E.begin(), E.end());

        rep(i, N) cout << E[i].ff << M_[E[i].ss] << (i < N - 1 ? " = ": "");
        cout << '\n';
    }
}
