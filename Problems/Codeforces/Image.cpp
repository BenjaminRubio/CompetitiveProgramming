#include <bits/stdc++.h>
using namespace std;

int T, N;
 
int main()
{
    cin >> T;
    while (T--)
    {
        set<char> s; char c;
        for (int i = 0; i < 4; i++) { cin >> c; s.insert(c); }
        cout << s.size() - 1 << '\n';
    }
}