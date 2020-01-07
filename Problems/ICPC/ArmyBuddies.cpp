#include <bits/stdc++.h>
using namespace std;

#define rep(i, n) for (int i = 0; i < (int)n; i++)

int S, B, L, R;
vector<int> l, r;

int main()
{
    while (cin >> S >> B)
    {
        if (S == 0)
            break;

        l.resize(S + 2);
        r.resize(S + 2);
        rep(i, S + 1) l[i] = i - 1;
        rep(i, S + 1) r[i] = i + 1;

        rep(i, B)
        {
            cin >> L >> R;
            
            if (l[L] <= 0)
                cout << "* ";
            else
            {
                cout << l[L] << ' ';
                r[l[L]] = r[R];
            }
            if (r[R] >= S + 1)
                cout << "*\n";
            else
            {
                cout << r[R] << '\n';
                l[r[R]] = l[L];
            }
        }
        cout << "-\n";
    }
}