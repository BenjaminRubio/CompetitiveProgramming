#include <bits/stdc++.h>
using namespace std;

#define rep(i, n) for (int i = 0; i < (int)n; i++)

int T, N, s, e;

struct E
{
    int t, id;
    bool b;
    E(int t, int id, bool b) : t(t), id(id), b(b) {}
    bool operator<(const E &e) const
    {
        return t < e.t or (t == e.t and (b and !e.b or (b == e.b and id < e.id)));
    }
};

int main()
{
    cin >> T;
    rep(t, T)
    {
        cin >> N;

        set<E> S;
        rep(i, N)
        {
            cin >> s >> e;
            S.insert(E(s, i, 0));
            S.insert(E(e, i, 1));
        }

        vector<char> ans(N);
        queue<char> q; q.push('C'); q.push('J');
        bool pos = true;
        for (E e : S)
        {
            if (!e.b and q.empty()) { pos = false; break; }
            if (!e.b) { ans[e.id] = q.front(); q.pop(); }
            if (e.b) { q.push(ans[e.id]); }
        }

        cout << "Case #" << t + 1 << ": ";
        if (!pos) cout << "IMPOSSIBLE\n";
        else
        {
            rep(i, N) cout << ans[i];
            cout << '\n';
        }
    }
}