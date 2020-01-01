#include <bits/stdc++.h>
using namespace std;

int N, C, S, c;

int main()
{
    cin >> N >> C >> S;

    int pos = 0;
    int ans = 0;
    while (C--)
    {
        if ((pos % N + N) % N == S - 1)
            ans++;
        cin >> c;
        pos += c;
    }
    if ((pos % N + N) % N == S - 1)
        ans++;

    cout << ans << '\n';
}