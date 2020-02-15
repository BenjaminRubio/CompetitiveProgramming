#include <bits/stdc++.h>
using namespace std;

#define rep(i, n) for (int i = 0; i < (int)n; i++)

struct Interval
{
    int l, r; char id;
    Interval() {}
    Interval(int l, int r, char id) : l(l), r(r), id(id) {}
    bool operator<(Interval &i)
    {
        return l < i.l or (l == i.l and r > i.r);
    }
};

int N, s, e;
char ch;
vector<Interval> I;

int main()
{
    cin >> N;

    rep(i, N)
    {
        cin >> ch >> s >> e;
        I.emplace_back(s, e, ch);
    }

    sort(I.begin(), I.end());

    int ans = 0;
    bool d = 0, j = 0;
    Interval last_d, last_j;
    for (Interval i : I)
    {
        if (i.id == 'D' and j) ans = max(ans, min(i.r, last_j.r) - i.l);
        if (i.id == 'J' and d) ans = max(ans, min(i.r, last_d.r) - i.l);
        if (i.id == 'D')
        {
            if (!d) d = 1, last_d = i;
            else if (i.r > last_d.r) last_d = i;
        }
        if (i.id == 'J')
        {
            if (!j) j = 1, last_j = i;
            else if (i.r > last_j.r) last_j = i;
        }
    }

    cout << ans << '\n';
}