#include <bits/stdc++.h>
using namespace std;

int T;
string s;
vector<char> c = {'a', 'b', 'c'};

bool check(int i)
{
    if (i == s.size())
        return true;
    char last = 'x';
    if (i > 0)
        last = s[i - 1];
    if (s[i] == '?')
    {
        for (char ch : c)
        {
            if (ch != last)
            {
                s[i] = ch;
                if (check(i + 1))
                    return true;
            }
        }
        return false;
    }
    else if (s[i] == last)
        return false;
    return check(i + 1);
}

int main()
{
    cin >> T;
    while (T--)
    {
        cin >> s;
        if (check(0))
            cout << s << '\n';
        else
            cout << -1 << '\n';
    }
}