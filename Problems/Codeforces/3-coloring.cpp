#include <bits/stdc++.h>
using namespace std;

#define rep(i, n) for (int i = 0; i < (int)n; i++)

int A, N, x, y;
vector<vector<int>> M;

int main()
{
    cin >> N;

    stack<pair<int, int>> V1, V2;
    rep(i, N) rep(j, N)
    {
        if (((i + j) & 1) == 0) V1.emplace(i, j);
        if (((i + j) & 1) == 1) V2.emplace(i, j);
    }
    
    rep(_, N * N)
    {
        cin >> A;

        if (A == 1 && !V2.empty())
        {
            tie(x, y) = V2.top(); V2.pop();
            cout << 2 << ' ' << x + 1 << ' ' << y + 1 << endl;
        }
        else if (A != 1 && !V1.empty())
        {
            tie(x, y) = V1.top(); V1.pop();
            cout << 1 << ' ' << x + 1 << ' ' << y + 1 << endl;
        }
        else if (A == 1 && V2.empty())
        {
            tie(x, y) = V1.top(); V1.pop();
            cout << 3 << ' ' << x + 1 << ' ' << y + 1 << endl;
        }
        else if (A != 1 && V1.empty())
        {
            tie(x, y) = V2.top(); V2.pop();
            if (A == 2) cout << 3 << ' ' << x + 1 << ' ' << y + 1 << endl;
            if (A == 3) cout << 2 << ' ' << x + 1 << ' ' << y + 1 << endl;
        }
    }
}