#include <bits/stdc++.h>
using namespace std;

#define rep(i, n) for (int i = 0; i < (int)n; i++)
#define repx(i, a, b) for (int i = (int)a; i < (int)b; i++)

string s;
vector<int> m_, s_;

int main()
{
    ios::sync_with_stdio(0); cin.tie(0);

    cin >> s;
    int n = s.size();

    m_.resize(n); s_.resize(n);
    rep(i, n)
    {
        int c = INT_MAX, p = 0;
        repx(j, i, n)
        {
            if (s[j] == '(') p++;
            else p--;
            c = min(c, p);
        }
        m_[i] = c;
        s_[i] = p;
    }

    int m = INT_MAX, pm = 0;
    rep(i, n)
    {
        int M = INT_MAX, pM = 0;
        repx(j, i, n)
        {
            if (s[j] == ')') pM++;
            else pM--;
            M = min(pM, M);

            if (m >= 0 and M + pm >= 0 and
                (j == n - 1 or m_[j + 1] + pm + pM >= 0) and
                ((j == n - 1) ? (pm + pM) : (s_[j + 1] + pm + pM)) == 0)
            {
                cout << "possible\n";
                return 0;
            }
        }

        if (s[i] == '(') pm++;
        else pm--;
        m = min(m, pm);
    }

    if (m >= 0 and pm == 0) cout << "possible\n";
    else cout << "impossible\n";
}