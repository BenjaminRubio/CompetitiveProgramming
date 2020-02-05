#include <bits/stdc++.h>
using namespace std;

#define rep(i, n) for (int i = 0; i < (int)n; i++)

struct PROD
{
    int v;
    PROD() { v = 1; }
    PROD(int x) { v = x; }
    PROD(const PROD &a, const PROD &b) { v = a.v * b.v; }
};

template <class node>
class ST
{
    vector<node> t;
    int n;

public:
    ST(vector<node> &arr)
    {
        n = arr.size();
        t.resize(n * 2);
        copy(arr.begin(), arr.end(), t.begin() + n);
        for (int i = n - 1; i > 0; --i)
            t[i] = node(t[i << 1], t[i << 1 | 1]);
    }

    void set_point(int p, const node &value)
    {
        for (t[p += n] = value; p > 1; p >>= 1)
            t[p >> 1] = node(t[p], t[p ^ 1]);
    }

    node query(int l, int r)
    {
        node ansl, ansr;
        for (l += n, r += n; l < r; l >>= 1, r >>= 1)
        {
            if (l & 1)
                ansl = node(ansl, t[l++]);
            if (r & 1)
                ansr = node(t[--r], ansr);
        }
        return node(ansl, ansr);
    }
};

int N, K, X, I, J;
vector<PROD> arr;
char t;

int main()
{
    while (cin >> N >> K)
    {
        arr.resize(N);
        rep(i, N)
        {
            cin >> X;
            if (X > 0) arr[i] = {1};
            if (X < 0) arr[i] = {-1};
            if (X == 0) arr[i] = {0};
        }

        ST<PROD> st(arr);

        rep(_, K)
        {
            cin >> t;
            if (t == 'C')
            {
                cin >> I >> X;
                if (X > 0) st.set_point(I - 1, 1);
                if (X < 0) st.set_point(I - 1, -1);
                if (X == 0) st.set_point(I - 1, 0);
            }
            else
            {
                cin >> I >> J;
                int r = st.query(I - 1, J).v;
                if (r > 0) cout << '+';
                if (r < 0) cout << '-';
                if (r == 0) cout << '0';
            }
        }
        cout << '\n';
    }
}
