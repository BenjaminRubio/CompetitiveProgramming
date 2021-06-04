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

int T;
string S;

int main()
{
    ios::sync_with_stdio(0); cin.tie(0);

    cin >> T;
    while (T--)
    {
        cin >> S;
        
        int N = S.size(), j = 0;
        rep(i, N - 1)
        {
            if (S[i] == S[i + 1] && S[i] == '1') break;
            j++;
        }

        bool flag = 1;
        while (j < N - 1)
        {
            if (S[j] == S[j + 1] && S[j] == '0') flag = 0;
            j++;
        }

        cout << (flag ? "YES" : "NO") << '\n';
    }
}
