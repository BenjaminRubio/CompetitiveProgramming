#include <bits/stdc++.h>
using namespace std;

#define rep(i, n) for (int i = 0; i < (int)n; i++)
#define repx(i, a, b) for (int i = (int)a; i < (int)b; i++)

int n, k;
char type;
map<char, long long> m = {{'S', 0LL}, {'E', 1LL}, {'T', 2LL}};
vector<long long> bits;
map<long long, long long> c;

int main()
{
    cin >> n >> k;

    bits.resize(n);
    rep(i, n)
    {
        long long b = 0;
        rep(j, k)
        {
            cin >> type;
            b |= (m[type] << (2 * j));
        }
        if (c.find(b) != c.end())
            c[b]++;
        else
            c[b] = 1;
        bits[i] = b;
    }

    long long ans = 0;
    rep(i, n) repx(j, i + 1, n)
    {
        long long b = 0;
        rep(t, k)
        {
            if ((3LL & (bits[i] >> (2 * t))) == (3LL & (bits[j] >> (2 * t))))
                b |= ((3LL & (bits[i] >> (2 * t))) << (2 * t));
            else if ((3LL & (bits[i] >> (2 * t))) == 0LL && (3LL & (bits[j] >> (2 * t))) == 1LL)
                b |= (2LL << (2 * t));
            else if ((3LL & (bits[i] >> (2 * t))) == 0LL && (3LL & (bits[j] >> (2 * t))) == 2LL)
                b |= (1LL << (2 * t));
            else if ((3LL & (bits[i] >> (2 * t))) == 1LL && (3LL & (bits[j] >> (2 * t))) == 2LL)
                b |= (0LL << (2 * t));
            else if ((3LL & (bits[i] >> (2 * t))) == 1LL && (3LL & (bits[j] >> (2 * t))) == 0LL)
                b |= (2LL << (2 * t));
            else if ((3LL & (bits[i] >> (2 * t))) == 2LL && (3LL & (bits[j] >> (2 * t))) == 1LL)
                b |= (0LL << (2 * t));
            else if ((3LL & (bits[i] >> (2 * t))) == 2LL && (3LL & (bits[j] >> (2 * t))) == 0LL)
                b |= (1LL << (2 * t));
        }

        if (bits[i] == b)
            ans += c[b] - 2LL;
        else
            ans += c[b];
    }

    cout << ans / 3LL << '\n';
}