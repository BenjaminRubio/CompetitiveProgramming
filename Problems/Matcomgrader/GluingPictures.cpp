#include <bits/stdc++.h>
using namespace std;

#define rep(i, n) for (int i = 0; i < (int)n; i++)
#define repx(i, a, b) for (int i = (int)a; i < (int)b; i++)
#define rep_(i, n) for (int i = (int)n - 1; i >= 0; i--)

struct SA
{
    int n; vector<int> C, R, R_, sa, sa_;
    inline int gr(int i) { return i < n ? R[i] : 0; }
    void csort(int maxv, int k)
    {
        C.assign(maxv + 1, 0);
        rep(i, n) C[gr(i + k)]++;
        repx(i, 1, maxv + 1) C[i] += C[i - 1];
        rep_(i, n) sa_[--C[gr(sa[i] + k)]] = sa[i];
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
    SA(vector<int>& s) { n = s.size(); getSA(s); }
};

int N;
string C, S;

int main()
{
    cin >> C >> N; int nn = C.size();

    set<char> s; vector<int> aux;
    for (char c : C) s.insert(c), aux.push_back(c);

    SA sa(aux);

    rep(_, N)
    {
        cin >> S; int n = S.size();

        bool flag = 1;
        for (char c : S) if (!s.count(c)) flag = 0;

        if (!flag) { cout << -1 << '\n'; continue; }

        int l = 0, r = nn, off = 0, i = 0, ans = 1;
        while (i < n)
        {
            int l1 = l, r1 = r;
            while (l1 < r1)
            {
                int m1 = (l1 + r1) / 2;
                int v = sa.sa[m1] + off < nn ? C[sa.sa[m1] + off] : 0;
                if (v >= S[i]) r1 = m1;
                else l1 = m1 + 1;
            }
            int l2 = l, r2 = r;
            while (l2 < r2)
            {
                int m2 = (l2 + r2) / 2;
                int v = sa.sa[m2] + off < nn ? C[sa.sa[m2] + off] : 0;
                if (v > S[i]) r2 = m2;
                else l2 = m2 + 1;
            }
            if (l2 == l1) l = 0, r = nn, off = 0, ans++;
            else l = l1, r = l2, off++, i++;
        }

        cout << ans << '\n';
    }
}