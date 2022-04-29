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

using vvp = vector<vp>;
using vvi = vector<vi>;
using vvl = vector<vl>;
using vvd = vector<vd>;

#define rep(i, n) for (int i = 0; i < (int)n; i++)
#define repx(i, a, b) for (int i = (int)a; i < (int)b; i++)
#define all(x) begin(x), end(x)
#define eb emplace_back
#define pb push_back
#define mp make_pair
#define ff first
#define ss second

int W, H, N, x_1, y_1, x_2, y_2;
vp A, B, C, D;

int main()
{
    ios::sync_with_stdio(0); cin.tie(0);

    cin >> W >> H >> N;
    rep(i, N)
    {
        cin >> x_1 >> y_1 >> x_2 >> y_2;

        if ((x_1 != 0 && x_1 != W && y_1 != 0 && y_1 != H) || (x_2 != 0 && x_2 != W && y_2 != 0 && y_2 != H))
            continue;

        if (x_1 == 0 && y_1 < H) A.eb(y_1, i);
        if (y_1 == H && x_1 < W) B.eb(x_1, i);
        if (x_1 == W && y_1 > 0) C.eb(H - y_1, i);
        if (y_1 == 0 && x_1 > 0) D.eb(W - x_1, i);

        if (x_2 == 0 && y_2 < H) A.eb(y_2, i);
        if (y_2 == H && x_2 < W) B.eb(x_2, i);
        if (x_2 == W && y_2 > 0) C.eb(H - y_2, i);
        if (y_2 == 0 && x_2 > 0) D.eb(W - x_2, i);
    }

    sort(A.begin(), A.end());
    sort(B.begin(), B.end());
    sort(C.begin(), C.end());
    sort(D.begin(), D.end());

    vi V;
    for (auto &e : A) V.pb(e.ss);
    for (auto &e : B) V.pb(e.ss);
    for (auto &e : C) V.pb(e.ss);
    for (auto &e : D) V.pb(e.ss);

    stack<int> s;
    vi S(N, 0);
    for (int i : V)
    {
        if (S[i])
        {
            if (s.empty() || s.top() != i)
            {
                cout << "N\n";
                return 0;
            }
            s.pop();
        }
        else { s.push(i); S[i] = 1; }
    }

    cout << "Y\n";
}
