#include <bits/stdc++.h>
using namespace std;

using ul = unsigned long long;
using ll = long long;
using db = double;

using pi = pair<int, int>;
using pl = pair<ll, ll>;
using pd = pair<db, db>;

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

ll T, R, B, D;

int main()
{
    cin >> T;
    while (T--)
    {
        cin >> R >> B >> D;
        if (R > B) swap(R, B);

        if (B <= (R * (D + 1ll))) cout << "YES\n";
        else cout << "NO\n";
    }
}
