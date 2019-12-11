#include <bits/stdc++.h>
using namespace std;

#define rep(i, n) for (int i = 0; i < (int)n; i++)

int T, n;
vector<int> p, l;

int main()
{
    cin >> T;
    while (T--)
    {
        cin >> n;
        p.resize(n);
        l.resize(n);

        int last = -1;

        rep(i, n)
        {
            cin >> p[i];
            if (p[i] == last)
                l[i] = l[i - 1];
            else
                l[i] = i;
            last = p[i];
        }

        int M = l[ceil(n / 2)];
        
        if (M == 0)
        {
            cout << "0 0 0\n";
            continue;
        }

        int g = 0;
        while (g < M and l[g] == 0)
            g++;
        int p = g;
        while (p < M and (p - g <= g or l[p - 1] == l[p]))
            p++;
        int b = M - p;
        p = p - g;
        
        if (g < p and g < b and g and p and b)
            cout << g << ' ' << p << ' ' << b << '\n';
        else
            cout << "0 0 0\n";
    }
}