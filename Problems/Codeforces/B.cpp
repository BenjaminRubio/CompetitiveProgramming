#include <bits/stdc++.h>
using namespace std;

#define rep(i, n) for (int i = 0; i < (int)n; i++)

int t, n;
bool pos;
vector<int> arr;
vector<bool> l, r;

int main()
{
    cin >> t;
    while (t--)
    {
        cin >> n;
        arr.reserve(n);
        rep(i, n) cin >> arr[i];

        l.resize(n);
        pos = true;
        rep(i, n)
        {
            if (pos and arr[i] >= i)
                l[i] = true;
            else
                l[i] = false;
            if (arr[i] < i) pos = false;
        }

        r.resize(n);
        pos = true;
        rep(i, n)
        {
            if (pos and arr[n - i - 1] >= i)
                r[n - i - 1] = true;
            else
                r[n - i - 1] = false;
            if (arr[n - i - 1] < i) pos = false;
        }

        bool done = false;
        rep(i, n) if (l[i] and r[i])
        {
            cout << "Yes\n";
            done = true;
            break;
        }

        if (!done) cout << "No\n";
    }
}