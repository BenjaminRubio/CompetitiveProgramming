#include <bits/stdc++.h>
using namespace std;

#define rep(i, n) for (int i = 0; i < (int)n; i++)

int n;
vector<int> arr;
vector<int> b(31, 0);
int b_ = 0;

int main()
{
    cin >> n;

    arr.resize(n);
    rep(i, n) cin >> arr[i];

    rep(i, n) rep(j, 31) if ((1 << j) & arr[i])
    {
        b[j]++;
        if (b[j] == 2) b_ |= (1 << j);
    }

    int M = -1, aux;
    rep(i, n)
    {
        int c = (arr[i] | b_) - b_; 

        if (c > M)
        {
            M = c;
            aux = i;
        }
    }

    cout << arr[aux] << ' ';
    rep(i, n) if (i != aux) cout << arr[i] << ' ';
    cout << '\n';
}