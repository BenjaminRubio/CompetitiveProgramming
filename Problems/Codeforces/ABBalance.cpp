#include <bits/stdc++.h>
using namespace std;

int T;
string S;

int main()
{
    cin >> T;
    while (T--)
    {
        cin >> S;

        int N = S.size();
        for (int i = 0; i < N - 1; i++) cout << S[i];
        cout << S[0] << '\n';
    }
}
