#include <bits/stdc++.h>
using namespace std;

#define rep(i, n) for (int i = 0; i < (int)n; i++)
typedef long long ll;

struct Interval
{
    ll l, r, c;
    Interval(ll l, ll r, ll c) : l(l), r(r), c(c) {}
    bool operator<(const Interval &p) const
    {
        return l < p.l or (l == p.l and r < p.r);
    }
};

ll L, C, N, P, X, A, B, S;
set<Interval> s;
vector<ll> cnt;
stack<Interval> se, si;

int main()
{
    while (cin >> L >> C >> N)
    {
        s.clear(); s.emplace(0, L - 1, 1);
        cnt.assign(C + 1, 0); cnt[1] = L;
        rep(_, N)
        {
            cin >> P >> X >> A >> B;

            S = cnt[P];
            ll M1 = (A + S * S) % L;
            ll M2 = (A + (S + B) * (S + B)) % L;
            if (M1 > M2) swap(M1, M2);

            Interval i(M1, M2, X);
            auto it = s.lower_bound(Interval(M1, 0, 0));
            if (it != s.begin()) it--;
            while (it != s.end())
            {
                if (it->l < i.l and it->r > i.r)
                {
                    Interval j1(it->l, i.l - 1, it->c);
                    Interval j2(i.r + 1, it->r, it->c);
                    se.push(*it); si.push(j1); si.push(j2);
                    cnt[it->c] -= (i.r - i.l + 1);
                    break;
                }
                else if (it->l < i.l and it->r >= i.l)
                {
                    Interval j(it->l, i.l - 1, it->c);
                    se.push(*it); si.push(j);
                    cnt[it->c] -= (it->r - i.l + 1);
                }
                else if (it->l >= i.l and it->r <= i.r)
                {
                    se.push(*it);
                    cnt[it->c] -= it->r - it->l + 1;
                }
                else if (it->l <= i.r and it->r > i.r)
                {
                    Interval j(i.r + 1, it->r, it->c);
                    se.push(*it); si.push(j);
                    cnt[it->c] -= i.r - it->l + 1;
                    break;
                }
                it++;
            }
            si.push(i);
            while (!se.empty()) { s.erase(se.top()); se.pop(); }
            while (!si.empty()) { s.insert(si.top()); si.pop(); }

            cnt[X] += M2 - M1 + 1;
        }

        ll ans = -1;
        rep(i, C) ans = max(ans, cnt[i + 1]);
        cout << ans << '\n';
    }
}