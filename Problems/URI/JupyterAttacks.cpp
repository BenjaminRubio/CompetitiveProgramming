#include <bits/stdc++.h>
using namespace std;

#define rep(i, n) for (int i = 0; i < (int)n; i++)
typedef long long ll;

template <class node>
class ST
{
    public:
    vector<node> t;
    int n;


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
        for (t[p += n] = value; p >>= 1; )
            t[p] = node(t[p << 1], t[p << 1 | 1]);
    }

    node query(int l, int r)
    {
        node ansl(0, 0), ansr(0, 0);
        for (l += n, r += n; l < r; l >>= 1, r >>= 1)
        {
            if (l & 1) ansl = node(ansl, t[l++]);
            if (r & 1) ansr = node(t[--r], ansr);
        }
        return node(ansl, ansr);
    }
};

int L, N, I, J;
ll B, P, V;
vector<ll> pot;
char t;

struct HASH
{
    ll v, s;
    HASH() : v(0), s(1) {}
    HASH(int v) : v(v), s(1) {}
    HASH(int v, int s) : v(v), s(s) {}
    HASH(const HASH &a, const HASH &b)
    {
        v = ((a.v * pot[b.s]) % P + b.v) % P;
        s = a.s + b.s;
    }
};

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    while (cin >> B >> P >> L >> N)
    {
        if (B == 0)
            break;

        pot.resize(L + 1);
        ll aux = 1;
        rep(i, L + 1) pot[i] = aux, aux = (aux * B) % P;

        vector<HASH> in(L);
        ST<HASH> st(in);

        rep(_, N)
        {
            cin >> t;
            if (t == 'E')
            {
                cin >> I >> V;
                st.set_point(I - 1, HASH(V));
            }
            else
            {
                cin >> I >> J;
                cout << st.query(I - 1, J).v << '\n';
            }
        }

        cout << "-\n";
    }
}