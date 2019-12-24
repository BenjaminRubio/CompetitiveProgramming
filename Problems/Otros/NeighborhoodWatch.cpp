#include <bits/stdc++.h>
using namespace std;

#define rep(i, n) for (int i = 0; i < (int)n; i++)

long long n, k;
vector<long long> w;

int main()
{
    cin >> n >> k;

    w.resize(k);
    rep(i, n) cin >> w[i];

    long long prev = 0LL;
    long long ans = n * (n + 1LL) / 2LL;
    for (long long i : w)
    {
        ans -= (i - prev - 1LL) * (i - prev) / 2LL;
        prev = i;
    }
    ans -= (n - prev) * (n - prev + 1LL) / 2LL;

    cout <<  ans << '\n';
}