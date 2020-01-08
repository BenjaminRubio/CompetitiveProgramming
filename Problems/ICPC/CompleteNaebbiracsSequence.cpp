#include <bits/stdc++.h>
using namespace std;

#define rep(i, n) for (int i = 0; i < (int)n; i++)

int K, N, x;
vector<int> c;

int main()
{
    while (cin >> K >> N)
    {
        c.assign(K, 0);
        rep(i, N)
        {
            cin >> x;
            c[x - 1]++;
        }

        vector<int> s;
        rep(i, K) if (find(s.begin(), s.end(), c[i]) == s.end()) s.push_back(c[i]);
        sort(s.begin(), s.end());

        if ((N % K != 0 && N % K != 1 && N % K != K - 1) || s.size() > 3 || s.size() < 2 || s[s.size() - 1] - s[0] > 2)
        {
            cout << "*\n";
            continue;
        }

        if (s.size() == 2)
        {
            int c1 = 0, c2 = 0, i1, i2;
            rep(i, K)
            {
                if (c[i] == s[0])
                {
                    c1++;
                    i1 = i;
                }
                else
                {
                    c2++;
                    i2 = i;
                }
            }

            if (c1 == 1)
                cout << '+' << i1 + 1 << '\n';
            else
                cout << '-' << i2 + 1 << '\n';
        }
        else
        {
            int i1, i2;
            rep(i, K)
            {
                if (c[i] == s[0])
                    i1 = i;
                if (c[i] == s[2])
                    i2 = i;
            }

            cout << '-' << i2 + 1 << " +" << i1 + 1 << '\n';
        }
    }
}