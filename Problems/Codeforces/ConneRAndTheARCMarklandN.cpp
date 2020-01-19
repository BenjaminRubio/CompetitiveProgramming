#include <bits/stdc++.h>
using namespace std;

#define rep(i, n) for (int i = 0; i < (int)n; i++)
#define repx(i, a, b) for (int i = (int)a; i < (int)b; i++)

int T, n, s, k, a;
vector<int> arr;

int main()
{
    cin >> T;

    while (T--)
    {
        cin >> n >> s >> k;
        s--;

        arr.assign(k, 0);

        rep(i, k) cin >> arr[i];
        rep(i, k) arr[i]--;

        bool in  = false;
        rep(i, k) if (arr[i] == s) in = true;

        if (!in)
        {
            cout << 0 << '\n';
            continue;
        }

        sort(arr.begin(), arr.end());

        int m = 1e9 + 1;

        if (arr[0] > 0)
        {
            if (arr[0] < s)
                m = min(m, s - arr[0] + 1);
            else
                m = min(m, arr[0] - s + 1);
        }

        if (arr[k - 1] < n - 1)
        {
            if (arr[k - 1] < s)
                m = min(m, s - arr[k - 1] + 1);
            else
                m = min(m, arr[k - 1] - s + 1);
        }

        rep(i, k)
        {
            if (arr[i] <= s && i > 0 && arr[i - 1] < arr[i] - 1)
                m = min(m, s - arr[i] + 1);
            if (arr[i] >= s && i < k - 1 && arr[i + 1] > arr[i] + 1)
                m = min(m, arr[i] - s + 1);
        }

        cout << m << '\n';
    }
}