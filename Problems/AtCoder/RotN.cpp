#include <bits/stdc++.h>
using namespace std;

int n;
string s;

int main()
{
    cin >> n >> s;
    for (char c : s)
    {
        cout << char(((c - 'A') + n) % 26 + 'A');
    }
    cout << '\n';
}