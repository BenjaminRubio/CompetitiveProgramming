#include <bits/stdc++.h>
using namespace std;

#define rep(i, n) for (int i = 0; i < (int)n; i++)
#define repx(i, a, b) for (int i = (int)a; i < (int)b; i++)

int T;
string s;

int main()
{
    cin >> T;
    rep(_, T)
    {
        cin >> s;
        int n = s.size();

        vector<int> d1(n);
        for (int i = 0, l = 0, r = -1; i < n; i++)
        {
            int k = (i > r) ? 1 : min(d1[l + r - i], r - i + 1);
            while (0 <= i - k && i + k < n && s[i - k] == s[i + k]) k++;
            d1[i] = k--;
            if (i + k > r) l = i - k, r = i + k;
        }

        vector<int> d2(n);
        for (int i = 0, l = 0, r = -1; i < n; i++)
        {
            int k = (i > r) ? 0 : min(d2[l + r - i + 1], r - i + 1);
            while (0 <= i - k - 1 && i + k < n && s[i - k - 1] == s[i + k]) k++;
            d2[i] = k--;
            if (i + k > r) l = i - k - 1, r = i + k;
        }
        
        vector<bool> check(n / 2);
        bool aux = true;
        int M = 0, idl, idr;
        rep(i, n / 2)
        {
            if (s[i] != s[n - i - 1])
            {
                if (aux)
                {
                    M = i * 2;
                    idl = i;
                    idr = n - i;
                }
                aux = false;
            }
            check[i] = aux; 
        }
        if (aux) { cout << s << '\n'; continue; }

        rep(i, n)
        {
            if (d1[i])
            {
                if (d1[i] * 2 - 1 > M and ((i - d1[i] + 1) == 0 or (i + d1[i]) == n))
                {
                    M = d1[i] * 2 - 1;
                    if ((i - d1[i] + 1) == 0) idl = i + d1[i], idr = n;
                    else idl = 0, idr = i - d1[i] + 1;
                }
                int m = min(n - (i + d1[i]), i - d1[i] + 1);
                if (m and check[m - 1])
                {
                    if (2 * m + d1[i] * 2 - 1 > M)
                    {
                        M = 2 * m + d1[i] * 2 - 1;
                        if (i - d1[i] + 1 == m) idl = i + d1[i], idr = n - m;
                        else idl = m, idr = i - d1[i] + 1;
                    }
                }
            }
            if (d2[i])
            {
                if (d2[i] * 2 > M and ((i - d2[i]) == 0 or (i + d2[i]) == n))
                {
                    M = d2[i] * 2;
                    if ((i - d2[i]) == 0) idl = i + d2[i], idr = n;
                    else idl = 0, idr = i - d2[i];
                }
                int m = min(n - (i + d2[i]), i - d2[i]);
                if (m and check[m - 1])
                {
                    if (2 * m + d2[i] * 2 > M)
                    {
                        M = 2 * m + d2[i] * 2;
                        if (i - d2[i] == m) idl = i + d2[i], idr = n - m;
                        else idl = m, idr = i - d2[i];
                    }
                }
            }
        }

        rep(i, idl) cout << s[i];
        repx(i, idr, n) cout << s[i];
        cout << '\n';
    }
}