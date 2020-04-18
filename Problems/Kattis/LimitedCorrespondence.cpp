#include <bits/stdc++.h>
using namespace std;

#define rep(i, n) for (int i = 0; i < (int)n; i++)

int N;
string a, b;
vector<string> A, B;
vector<bool> D;

void solve(int i)
{
    
}

int main()
{
    while (cin >> N)
    {
        rep(i, N)
        {
            cin >> a >> b;
            A.push_back(a); B.push_back(b);
        }

        a.clear(); b.clear();
        solve(0);
        
    }
}