#include <bits/stdc++.h>
using namespace std;

#define rep(i, n) for (int i = 0; i < (int)n; i++)

string S;

int main()
{
    cin >> S;

    int N = S.size();

    cout << 3 << '\n';
    cout << 'R' << ' ' << N - 1 << '\n';
    cout << 'L' << ' ' << N << '\n';
    cout << 'L' << ' ' << 2 << '\n';
}