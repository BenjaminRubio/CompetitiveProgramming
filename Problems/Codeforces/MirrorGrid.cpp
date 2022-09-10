#include <bits/stdc++.h>
using namespace std;

int T, N;
vector<string> A;

pair<int, int> rotate(int i, int j)
{
    return {j, N - i - 1};
}

int main()
{
    cin >> T;
    while (T--)
    {
        cin >> N;

        A.resize(N);
        for (int i = 0; i < N; i++) cin >> A[i];
        
        int ans = 0;
        for (int i = 0; i < N; i++) for (int j = 0; j < N; j++)
        {
            int x = i, y = j, s = 0, times = 4;
            while (times--)
            {
                s += (A[x][y] - '0');
                tie(x, y) = rotate(x, y);
            }
            ans += min(s, 4 - s);
        }

        cout << ans / 4 << '\n';
    }
}
