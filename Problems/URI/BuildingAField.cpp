#include <bits/stdc++.h>
using namespace std;

#define rep(i, n) for (int i = 0; i < (int)n; i++)

int n, x;
set<int> accums;

int main()
{
    cin >> n;

    int sum = 0;
    rep(i, n)
    {
        cin >> x;
        accums.insert(sum + x);
        sum += x;
    }

    if (sum % 2)
    {
        cout << "N\n";
        return 0;
    }
    
    int c = 0;
    for (int i : accums)
    {
        if (accums.count(i + sum / 2))
            c++;
    }

    if (c >= 2)
        cout << "Y\n";
    else
        cout << "N\n";
}