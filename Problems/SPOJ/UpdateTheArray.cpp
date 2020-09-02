#include <bits/stdc++.h>
using namespace std;


class ST
{
    vector<int> t;
    int n;

public:
    ST(vector<int> &arr)
    {
        n = arr.size();
        t.resize(n * 2);
        copy(arr.begin(), arr.end(), t.begin() + n);
        for (int i = n - 1; i > 0; --i)
            t[i] = t[i << 1] + t[i << 1 | 1];
    }
    void update(int p, const int &value)
    {
        for (t[p += n] += value; p >>= 1; )
            t[p] = t[p << 1] + t[p << 1 | 1];
    }
    int query(int l, int r)
    {
        int ansl = 0, ansr = 0;
        for (l += n, r += n; l < r; l >>= 1, r >>= 1)
        {
            if (l & 1) ansl += t[l++];
            if (r & 1) ansr += t[--r];
        }
        return ansl + ansr;
    }
};

#define rep(i, n) for (int i = 0; i < (int)n; i++)

int T, N, U, Q, l, r, v;
vector<int> D;

int main()
{
    cin >> T;
    while (T--)
    {
        cin >> N >> U;

        D.resize(N + 1);
        ST st(D);
        rep(_, U)
        {
            cin >> l >> r >> v;
            st.update(l, v), st.update(r + 1, -v);
        }

        cin >> Q;
        rep(_, Q)
        {
            cin >> l;
            cout << st.query(0, l + 1) << '\n';
        }
    }
}