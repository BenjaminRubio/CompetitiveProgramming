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

string A, B;

int main()
{
    ios::sync_with_stdio(0); cin.tie(0);

    getline(cin, A); getline(cin, B);

    set<char> ans;

    int j = 0, i = 0;
    while (j < A.size())
    {
        while (B[i] != A[j]) ans.insert(B[i]), i++;
        i++, j++;
    }
    while (i < B.size()) ans.insert(B[i]), i++;

    for (char c : ans) cout << c;
    cout << '\n';
}
