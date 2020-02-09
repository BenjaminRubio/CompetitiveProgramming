#include <bits/stdc++.h>
using namespace std;

#define rep(i, n) for (int i = 0; i < (int)n; i++)

int T, n;
vector<int> arr;

int main()
{
    cin >> T;
    rep(t, T)
    {
        cin >> n;

        arr.resize(n);
        rep(i, n) cin >> arr[i];

        int ans = 0;
        int sum = 0;
        rep(i, n)
        {
            if (arr[i] == 0)
            {
                ans++;
                sum++;
            }
            else sum += arr[i];
        }

        if (sum == 0) ans++;

        cout << ans << '\n';
    }
}