#include <bits/stdc++.h>
using namespace std;

#define rep(i, n) for (int i = 0; i < (int)n; i++)
#define ff first
#define ss second

int N, M, i, h; char t;
vector<int> H;
set<pair<int, int>> L, R;

int main()
{
    ios::sync_with_stdio(0); cin.tie(0);

    cin >> N >> M;

    H.resize(N);
    rep(i, N) cin >> H[i];

    int l = -1;
    rep(i, N) if (H[i] > l)
        R.emplace(i, H[i]), l = H[i];
    R.emplace(N, 0);

    l = -1;
    rep(i, N) if (H[N - i - 1] > l)
        L.emplace(i, H[N - i - 1]), l = H[N - i - 1];
    L.emplace(N, 0);

    rep(_, M)
    {
        cin >> t;
        if (t == 'U')
        {
            cin >> i >> h; i--;

            bool fr = 0, fl = 0;

            queue<pair<int, int>> q;

            auto itr = --R.lower_bound({i + 1, -1});
            if (itr->ss < h) fr = 1;
            if (itr->ff < i) itr++;
            while (itr->ff < N && itr->ss < h) q.push(*itr), itr++;
            while (!q.empty()) R.erase(q.front()), q.pop();

            auto itl = --L.lower_bound({N - i, -1});
            if (itl->ss < h) fl = 1;
            if (itl->ff < N - i - 1) itl++;
            while (itl->ff < N && itl->ss < h) q.push(*itl), itl++;
            while (!q.empty()) L.erase(q.front()), q.pop();

            if (fr) R.emplace(i, h);
            if (fl) L.emplace(N - i - 1, h);
        }
        else
        {
            cin >> i; i--;
            auto r = *R.lower_bound({i + (t == 'R'), -1});
            auto l = *L.lower_bound({N - i - 1 + (t == 'L'), -1});

            if (r.ss > l.ss || (r.ss == l.ss && t == 'R'))
                cout << r.ff + 1 << '\n';
            else if (l.ss > r.ss || (r.ss == l.ss && t == 'L'))
                cout << N - l.ff << '\n';
        }
    }
}