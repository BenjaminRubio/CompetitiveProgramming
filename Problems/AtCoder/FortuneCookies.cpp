#include <bits/stdc++.h>
using namespace std;

#define rep(i, n) for (int i = 0; i < (int)n; i++)

int A[4];

int main()
{
    rep(i, 4) cin >> A[i];

    if ((A[0] == A[1] + A[2] + A[3]) || (A[1] == A[0] + A[2] + A[3]) ||
        (A[2] == A[0] + A[1] + A[3]) || (A[3] == A[0] + A[1] + A[2])) cout << "Yes\n";
    else if ((A[0] + A[1] == A[2] + A[3]) || (A[0] + A[2] == A[1] + A[3]) ||
             (A[1] + A[2] == A[0] + A[3])) cout << "Yes\n";
    else cout << "No\n";
}