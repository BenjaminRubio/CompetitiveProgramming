#include <bits/stdc++.h>
using namespace std;

#define rep(i, n) for (int i = 0; i < (int)n; i++)

int match(string &p, string &t)
{
    int n = p.size(), m = t.size(), L[n]; L[0] = 0;
    rep(j, n - 1)
    {
        int i = L[j];
        while (p[i] != p[j + 1] && i) i = L[i - 1];
        L[j + 1] = p[i] == p[j + 1] ? i + 1 : 0;
    }
    int i = 0;
    rep(j, m)
    {
        while (p[i] != t[j] && i) i = L[i - 1];
        if (p[i] == t[j] && ++i == n) return j - n + 1;
    }
    return -1;
}

int N;
string S, T;

int main()
{
    cin >> N >> S >> T;
    rep(i, N) T.push_back(T[i]);

    cout << match(S, T) << '\n';
}