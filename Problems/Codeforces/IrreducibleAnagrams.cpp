#include <bits/stdc++.h>
using namespace std;

#define rep(i, n) for (int i = 0; i < (int)n; i++)
#define repx(i, a, b) for (int i = (int)a; i < (int)b; i++)

typedef long long ll;

template<class t> class SparseTable {
    int n;
    vector<ll> memo, *arr;    
public:
    SparseTable(vector<ll>& _arr) {
        arr = &_arr;
        n = arr->size();
        int maxlog = 31 - __builtin_clz(n);
        memo.assign(n * (maxlog + 1), -1);
    }
    ll dp(int i, int e) { 
        ll& ans = memo[e * n + i];
        if (ans != -1) return ans;
        if (e == 0) return ans = (*arr)[i];
        return ans = t::merge(dp(i, e-1), dp(i+(1<<(e-1)), e-1));
    }
    ll query(int l, int r) {
        ll ans = t::neutro;
        int d = r-l+1;
        for (int e = 0; d; e++, d>>=1) {
            if (d & 1) {
                ans = t::merge(ans, dp(l, e));
                l += 1 << e;
            }
        }
        return ans;
    }
};
struct OR {
    static const ll neutro = 0LL;
    static ll merge(ll x, ll y) { return x | y; }
};

string s;
int q, l, r;
vector<ll> a;

int main()
{
    cin >> s >> q;

    int n = s.size();

    a.resize(n);
    rep(i, n) a[i] = (1LL << int(s[i] - 'a'));

    SparseTable<OR> st(a);

    rep(_, q)
    {
        cin >> l >> r;
        l--; r--;

        if (l == r)
            cout << "Yes\n";
        else if (a[l] != a[r])
            cout << "Yes\n";
        else cout << "No\n";
    }
}