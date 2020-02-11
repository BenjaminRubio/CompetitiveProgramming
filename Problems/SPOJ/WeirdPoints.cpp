#include <bits/stdc++.h>
using namespace std;

#define rep(i, n) for (int i = 0; i< (int)n; i++)
#define ff first
#define ss second

struct FenwickTree
{
    vector<int> FT;
    FenwickTree(int N)
    {
        FT.resize(N + 1, 0);
    }

    int query(int i)
    {
        int ans = 0;
        for (; i; i -= i & (-i)) ans += FT[i];
        return ans;
    }

    int query(int i, int j)
    {
        return query(j) - query(i - 1);
    }

    void update(int i, int v)
    {
        for (; i < FT.size(); i += i & (-i)) FT[i] += v;
    }
};

int T, N, K, x, y;
vector<pair<int, int>> coords;
set<int> Y;
map<int, int> mY;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> T;
    rep(t, T)
    {
        Y.clear(); mY.clear();

        cin >> N >> K;

        coords.resize(N);
        rep(i, N)
        {
            cin >> x >> y;
            coords[i].ff = x;
            coords[i].ss = y;
            Y.insert(y);
        }

        sort(coords.begin(), coords.end());

        int id = 0;
        for (int y : Y) mY[y] = id++;

        int ans = 0;
        FenwickTree ft(id);
        for (auto c : coords)
        {
            if (abs(N - 1 - 2 * ft.query(1, mY[c.ss] + 1)) >= K) ans++;
            ft.update(mY[c.ss] + 1, 1);
        }

        cout << ans << '\n';
    }
}