#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> par;
#define rep(i, n) for (int i = 0; i < (int)n; i++)
#define ff first
#define ss second

int N = 30010, T = 600, t, d; char x;
vector<int> A;

int main()
{
    A.assign(N, 0);

    queue<par> q;
    priority_queue<int, vector<int>, greater<int>> off;

    rep(i, N) off.push(i + 1);

    while (cin >> t >> x)
    {
        while (!q.empty() && q.front().ff <= t)
        {
            if (A[q.front().ss] == q.front().ff)
                A[q.front().ss] = 0, off.push(q.front().ss);
            q.pop();
        }
        if (x == '+')
        {
            cout << off.top()  << '\n';
            A[off.top()] = t + T;
            q.emplace(t + T, off.top()), off.pop();
        }
        else
        {
            cin >> d;

            if (A[d])
            {
                cout << "+\n";
                A[d] = t + T;
                q.emplace(t + T, d);
            }
            else cout << "-\n";
        }
    }
}