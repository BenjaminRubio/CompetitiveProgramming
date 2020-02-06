#include <bits/stdc++.h>
using namespace std;

string s, u, d, l, r;

bool up(int i)
{
    if (u[i] == 'm') return false;

    if (u[i] == 's') u[i] = 'p';
    else if (u[i] == 'r') u[i] = 'q';
    else
    {
        if (u[i] == 'p') u[i] = 's';
        else u[i] = 'r';
        return up(i - 1);
    }
    return true;
}

bool dw(int i)
{
    if (d[i] == 'm') return false;

    if (d[i] == 'p') d[i] = 's';
    else if (d[i] == 'q') d[i] = 'r';
    else
    {
        if (d[i] == 's') d[i] = 'p';
        else d[i] = 'q';
        return dw(i - 1);
    }
    return true;
}

bool lf(int i)
{
    if (l[i] == 'm') return false;

    if (l[i] == 'q') l[i] = 'p';
    else if (l[i] == 'r') l[i] = 's';
    else
    {
        if (l[i] == 'p') l[i] = 'q';
        else l[i] = 'r';
        return lf(i - 1);
    }
    return true;
}

bool rg(int i)
{
    if (r[i] == 'm') return false;

    if (r[i] == 'p') r[i] = 'q';
    else if (r[i] == 's') r[i] = 'r';
    else
    {
        if (r[i] == 'q') r[i] = 'p';
        else r[i] = 's';
        return rg(i - 1);
    }
    return true;
}

int N;

int main()
{
    cin >> N;

    while (N--)
    {
        cin >> s;
        l = s; r = s; u = s; d = s;

        bool up_ = up(s.size() - 1);
        bool dw_ = dw(s.size() - 1);
        bool lf_ = lf(s.size() - 1);
        bool rg_ = rg(s.size() - 1);

        if (up_) cout << u << ' ';
        else cout << "<none> ";
        if (dw_) cout << d << ' ';
        else cout << "<none> ";
        if (lf_) cout << l << ' ';
        else cout << "<none> ";
        if (rg_) cout << r;
        else cout << "<none>";
        cout << '\n';
    }
}