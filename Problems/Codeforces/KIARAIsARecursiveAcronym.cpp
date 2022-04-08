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
vector<string> S;

int main()
{
    ios::sync_with_stdio(0); cin.tie(0);

    cin >> N;
    S.resize(N); rep(i, N) cin >> S[i];

    set<char> s;
    rep(i, N) s.insert(S[i][0]);

    bool pos = 0;
    rep(i, N)
    {
        bool aux = 1;
        for (char c : S[i]) if (!s.count(c)) aux = 0;

        pos = pos | aux;
    }

    if (pos) cout << "Y\n";
    else cout << "N\n";
}
