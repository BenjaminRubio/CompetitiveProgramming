#include <bits/stdc++.h>
using namespace std;

#define rep(i, n) for (int i = 0; i < (int)n; i++)
typedef long long ll;

int C;
string Sm, Si;

bool check(string &p)
{
    if (p[3] >= 'A')
    {
        if (p[4] < 'A') return false;

        for (char c : p) if (c == 'A' or c == 'C' or c == 'M' or c == 'I' or c == 'P')
            return false;
        return true;
    }
    else if (p[3] < 'A' and p[4] < 'A') return true;
    return false;
}

int ord(char c)
{
    int ans = c - 'A';
    if (c > 'A') ans--;
    if (c > 'C') ans--;
    if (c > 'I') ans--;
    if (c > 'M') ans--;
    if (c > 'P') ans--;
    return ans;
}

int get_ord(string &p)
{
    if (p[3] >= 'A')
    {
        ll ans = 0;
        ans += ord(p[0]) * 21 * 21 * 21 * 2100;
        ans += ord(p[1]) * 21 * 21 * 2100;
        ans += ord(p[2]) * 21 * 2100;
        ans += ord(p[3]) * 2100;
        ans += ord(p[4]) * 100;
        ans += stoi(p.substr(5, 2));
        ans += 26 * 26 * 260000;
        return ans;
    }
    else
    {
        ll ans = 0;
        ans += (p[0] - 'A') * 26 * 260000;
        ans += (p[1] - 'A') * 260000;
        ans += (p[2] - 'A') * 10000;
        ans += stoi(p.substr(3, 4));

        return ans;
    }
}

int main()
{
    while (cin >> Sm >> Si >> C)
    {
        if (Sm == "*") break;

        if (!check(Si))
        {
            cout << "N\n";
            continue;
        }

        int Om = get_ord(Sm);
        int Oi = get_ord(Si);

        if (Oi > Om and Oi <= Om + C) cout << "Y\n";
        else cout << "N\n";
    }
}
