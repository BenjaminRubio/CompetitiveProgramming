#include <bits/stdc++.h>
using namespace std;

int Q, l1, r1, l2, r2;

int main()
{
    cin >> Q;
    while (Q--)
    {
        cin >> l1 >> r1 >> l2 >> r2;
        cout << l1 << ' ' << (l1 != l2 ? l2 : r2) << '\n';
    }
}