#include "../Template.cpp"

int match(string &p, string &t)
{
    int n = sz(p), m = sz(t), L[n]; L[0] = 0;
    rep(j, n - 1)
    {
        int i = L[j]; while (p[i] != p[j + 1] && i) i = L[i - 1];
        L[j + 1] = (p[i] == p[j + 1] ? i + 1 : 0);
    }
    int ans = 0, i = 0; rep(j, m)
    {
        while (p[i] != t[j] && i) i = L[i - 1];
        if (p[i] == t[j] && ++i == n) i = L[n - 1], ans++;
    }
    return ans;
}
