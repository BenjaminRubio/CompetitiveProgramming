#include <bits/stdc++.h>
using namespace std;

#define rep(i, n) for (int i = 0; i < (int)n; i++)

int T, n;
vector<int> arr, arr1, arr2;

int main()
{
    cin >> T;
    rep(t, T)
    {
        cin >> n;

        arr.resize(2 * n);
        rep(i, 2 * n) cin >> arr[i];

        sort(arr.begin(), arr.end());

        int ans = abs(arr[n - 1] - arr[n]);

        cout << ans << '\n';
    }
}