#include <bits/stdc++.h>
using namespace std;

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

    int query_O1(int l, int r)
    {
        int e = 31 - __builtin_clz(r - l + 1);
        return t::merge(dp(l, e), dp(r - (1 << e) + 1, e));
    }

    int query_Ologn(int l, int r)
    {
        int ans = t::neutro;
        int d = r - l + 1;
        for (int e = 0; d; e++, d >>= 1) if (d & 1)
        {
            ans = t::merge(ans, dp(l, e));
            l += 1 << e;
        }
        return ans;
    }
};

struct OP
{
    static const int neutro = 0;
    static int merge(int x, int y) { return x + y; }
};