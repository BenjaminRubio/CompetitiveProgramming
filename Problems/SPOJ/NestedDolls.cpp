#include <bits/stdc++.h>
using namespace std;

#define rep(i, n) for (int i = 0; i < (int)n; i++)

struct Doll
{
    int w, h;
    Doll() {}
    bool operator<(const Doll &d) const
    {
        return w > d.w || (w == d.w && h < d.h);
    }
};

int T, M;
vector<Doll> d;

int main()
{
    cin >> T;
    while (T--)
    {
        cin >> M;

        d.resize(M);
        rep(i, M) cin >> d[i].w >> d[i].h;

        sort(d.begin(), d.end());

        multiset<int> s;
        rep(i, M)
        {
            int h = d[i].h;
            
            auto l = s.lower_bound(h + 1);
            if (l != s.end()) { s.erase(l); }
            s.insert(h);
        }

        cout << s.size() << '\n';
    }
}