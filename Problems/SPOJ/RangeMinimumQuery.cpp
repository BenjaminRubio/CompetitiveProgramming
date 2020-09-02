#include <bits/stdc++.h>
using namespace std;

#define rep(i, n) for (int i = 0; i < (int)n; i++)

template <class t>
class ST
{
    int n;
    vector<int> memo, *arr;

public:
    ST(vector<int> &_arr)
    {
        arr = &_arr; n = arr->size();
        int maxlog = 31 - __builtin_clz(n);
        memo.assign(n * (maxlog + 1), -1);
    }
    int dp(int i, int e)
    {
        int &ans = memo[e * n + i];
        if (ans != -1) return ans;
        if (e == 0) return ans = (*arr)[i];
        return ans = t::merge(dp(i, e - 1), dp(i + (1 << (e - 1)), e - 1));
    }

    int query(int l, int r)
    {
        int e = 31 - __builtin_clz(r - l + 1);
        return t::merge(dp(l, e), dp(r - (1 << e) + 1, e));
    }
};

struct MIN
{
    static const int neutro = INT_MAX;
    static int merge(int x, int y) { return min(x, y); }
};

int N, Q, l, r;
vector<int> A;

int main()
{
    cin >> N;

    A.resize(N);
    rep(i, N) cin >> A[i];

    ST<MIN> st(A);

    cin >> Q;
    rep(_, Q)
    {
        cin >> l >> r;
        cout << st.query(l, r) << '\n';
    }
}