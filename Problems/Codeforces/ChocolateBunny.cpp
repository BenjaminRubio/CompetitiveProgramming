#include <bits/stdc++.h>
using namespace std;

#define rep(i, n) for (int i = 0; i < (int)n; i++)

int N, i, j, a1, a2;
vector<int> A;
queue<int> Q;

int main()
{
    cin >> N;

    A.resize(N);
    rep(i, N) Q.push(i + 1);

    while (!Q.empty())
    {
        i = Q.front(); Q.pop();
        if (!Q.empty())
        {
            j = Q.front(); Q.pop();
            cout << "? " << i << ' ' << j << endl;
            cin >> a1;
            cout << "? " << j << ' ' << i << endl;
            cin >> a2;

            if (a1 > a2) { A[i - 1] = a1; Q.push(j); }
            if (a2 > a1) { A[j - 1] = a2; Q.push(i); }
        }
        else A[i - 1] = N;
    }

    cout << "! ";
    rep(i, N) cout << A[i] << ' ';
    cout << endl;
}