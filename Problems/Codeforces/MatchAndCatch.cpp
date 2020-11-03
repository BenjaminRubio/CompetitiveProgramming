#include <bits/stdc++.h>
using namespace std;

#define rep(i, n) for (int i = 0; i < (int)n; i++)
#define repx(i, a, b) for (int i = (int)a; i < (int)b; i++)

struct SA
{
    int n; vector<int> C, R, R_, sa, sa_, lcp;
    inline int gr(int i) { return i < n ? R[i] : 0; }
    void csort(int maxv, int k)
    {
        C.assign(maxv + 1, 0);
        rep(i, n) C[gr(i + k)]++;
        repx(i, 1, maxv + 1) C[i] += C[i - 1];
        for (int i = (int)n - 1; i >= 0; i--) sa_[--C[gr(sa[i] + k)]] = sa[i];
        sa.swap(sa_);
    }
    void getSA(vector<int>& s)
    {
        R = R_ = sa = sa_ = vector<int>(n); rep(i, n) sa[i] = i;
        sort(sa.begin(), sa.end(), [&s](int i, int j) { return s[i] < s[j]; });
        int r = R[sa[0]] = 1;
        repx(i, 1, n) R[sa[i]] = (s[sa[i]] != s[sa[i - 1]]) ? ++r : r;
        for (int h = 1; h < n && r < n; h <<= 1)
        {
            csort(r, h); csort(r, 0); r = R_[sa[0]] = 1;
            repx(i, 1, n)
            {
                if (R[sa[i]] != R[sa[i - 1]] || gr(sa[i] + h) != gr(sa[i - 1] + h)) r++;
                R_[sa[i]] = r;
            } R.swap(R_);
        }
    }
    void getLCP(vector<int>& s)
    {
        lcp.assign(n, 0); int k = 0;
        rep(i, n)
        {
            int r = R[i] - 1;
            if (r == n - 1) { k = 0; continue; }
            int j = sa[r + 1];
            while (i + k < n && j + k < n and s[i + k] == s[j + k]) k++;
            lcp[r] = k; if (k) k--;
        }
    }
    SA(vector<int>& s) { n = s.size(); getSA(s); getLCP(s); }
};

string S1, S2;

int main()
{
    cin >> S1 >> S2;

    vector<int> aux;
    for (char c : S1) aux.push_back(c - 'a' + 3); aux.push_back(1);
    for (char c : S2) aux.push_back(c - 'a' + 3); aux.push_back(2);

    SA sa(aux); int N = S1.size() + S2.size() + 2, ans = INT_MAX;
    rep(i, N - 1) if (i)
    {
        int a = (sa.sa[i] > S1.size() ? 2 : 1);
        int b = (sa.sa[i + 1] > S1.size() ? 2 : 1);
        if (a != b)
        {
            int x = sa.lcp[i - 1], y = sa.lcp[i], z = sa.lcp[i + 1];
            if (y > max(x, z)) ans = min(ans, max(x, z) + 1);
        }
    }

    if (ans == INT_MAX) cout << -1 << '\n';
    else cout << ans << '\n';
}