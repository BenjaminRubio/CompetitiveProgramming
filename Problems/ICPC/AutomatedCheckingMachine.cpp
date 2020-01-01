#include <bits/stdc++.h>
using namespace std;

#define rep(i, n) for (int i = 0; i < (int)n; i++)

bool v1[5], v2[5];

int main()
{
    while (cin >> v1[0])
    {
        rep(i, 4) cin >> v1[i + 1];
        rep(i, 5) cin >> v2[i];
        bool done = false;
        rep(i, 5)
        {
            if (v1[i] == v2[i])
            {
                cout << "N\n";
                done = true;
                break;
            }
        }
        if (!done)
            cout << "Y\n";
    }
}