#include <bits/stdc++.h>
using namespace std;

#define rep(i, n) for (int i = 0; i < (int)n; i++)

int N;

int main()
{
    cin >> N;

    vector<int> binary;
    while (N) binary.push_back(N & 1), N >>= 1;

    reverse(binary.begin(), binary.end());

    int ans = 0;
    rep(i, binary.size()) if (binary[i]) ans += (1 << i);

    cout << ans << '\n';
}