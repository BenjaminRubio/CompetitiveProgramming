#include <bits/stdc++.h>
using namespace std;

using ll = long long;

#define rep(i, n) for (int i = 0; i < (int)n; i++)
#define pb push_back
#define ff first
#define ss second

int N;
string R, S, Q;
ll B = 1777771, M = 999727999, P = 325255434;
vector<ll> b, H, I;

ll get(int l, int r)
{
    ll h = (H[r] - H[l] + M) % M;
    return (1LL * h * I[l]) % M;
}

struct Suff
{
    int i = 0;
    Suff() {}
    Suff(int i) : i(i) {}
    int lcp(const Suff &s) const
    {
        if (i == 0 || s.i == 0) return 1;

        int l = 1, r = min(i, s.i) + 1;
        while (l < r)
        {
            int m = (l + r) / 2;
            if (get(i - m, i) != get(s.i - m, s.i)) r = m;
            else l = m + 1;
        }
        return l;
    }
    bool operator<(const Suff &s) const
    {
        int l = lcp(s);
        return l <= min(i, s.i) ? R[i - l] < R[s.i - l] : i < s.i;
    }
};

int main()
{
    ios::sync_with_stdio(0); cin.tie(0);

    I.resize(2e5 + 1); b.resize(2e5 + 1);
    I[0] = 1; rep(k, 2e5) I[k + 1] = (1LL * I[k] * P) % M;
    b[0] = 1; rep(k, 2e5) b[k + 1] = (b[k] * B) % M;

    cin >> S >> Q;
    N = S.size(); S += Q;

    stack<ll> ans; ans.push(0);
    set<Suff> s; R = S;
    H.assign(S.size(), 0); int l = 0; stack<set<Suff>::iterator> its;
    rep(i, S.size())
    {
        if (S[i] == '-') { ans.pop(); s.erase(its.top()); its.pop(); l--; }
        else
        {
            R[l] = S[i];
            H[l + 1] = (H[l] + b[l] * S[i]) % M;

            Suff ss(++l);
            its.push(s.insert(ss).ff);
            auto it = its.top();

            Suff sa, sb, sc, sd; int c = 0;
            if (it != s.begin()) sb = *(--it), c++;
            if (it != s.begin()) sa = *(--it), c++;
            rep(_, c) it++; c = 0;
            if (++it != s.end()) sc = *it, c++;
            if (it != s.end() && ++it != s.end()) sd = *it, c++;

            ll aux = ans.top();
            int ab = sa.lcp(sb), bc = sb.lcp(sc), cd = sc.lcp(sd), bs = sb.lcp(ss), cs = sc.lcp(ss);
            aux -= max(bc - ab, 0) + max(cd - bc, 0);
            aux += max(bs - ab, 0) + max(cs - bs, 0) + max(cd - cs, 0);
            ans.push(aux);
        }
        if (i >= N - 1) cout << ans.top() << '\n';
    }
}
