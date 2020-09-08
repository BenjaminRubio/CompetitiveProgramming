#include <bits/stdc++.h>
using namespace std;

#define rep(i, n) for (int i = 0; i < (int)n; i++)

template <class t>
class ST
{
    int n;
    vector<int> memo, *arr;

public:
    ST(vector<int> &_arr)
    {
        arr = &_arr; n = arr->size();
        int maxlog = 31 - __builtin_clz(n);
        memo.assign(n * (maxlog + 1), -1);
    }
    int dp(int i, int e)
    {
        int &ans = memo[e * n + i];
        if (ans != -1) return ans;
        if (e == 0) return ans = (*arr)[i];
        return ans = t::merge(dp(i, e - 1), dp(i + (1 << (e - 1)), e - 1));
    }

    int query(int l, int r)
    {
        int e = 31 - __builtin_clz(r - l + 1);
        return t::merge(dp(l, e), dp(r - (1 << e) + 1, e));
    }
};

struct MAX
{
    static const int neutro = INT_MIN;
    static int merge(int x, int y) { return max(x, y); }
};

struct MIN
{
    static const int neutro = INT_MAX;
    static int merge(int x, int y) { return min(x, y); }
};

int N, l, r, m;
vector<int> H, D;
vector<vector<int>> G;

void bfs(int s)
{
    queue<int> q; q.push(s);
    D.assign(N, -1); D[s] = 0;
    while (!q.empty())
    {
        int u = q.front(); q.pop();
        for (int v : G[u]) if (D[v] == -1)
        {
            D[v] = D[u] + 1;
            q.push(v);
        }
    }
}

int main()
{
    cin >> N;

    H.resize(N);
    rep(i, N) cin >> H[i];

    ST<MAX> stM(H); ST<MIN> stm(H);

    G.assign(N, {});
    rep(i, N)
    {
        if (i < N - 1) G[i].push_back(i + 1);

        if (1)
        {
            l = 0, r = i - 1;
            while (l < r)
            {
                m = (l + r) / 2;
                if (stm.query(m, i - 1) > H[i]) r = m;
                else l = m + 1;
            }

            if (l && stm.query(l, i - 1) > H[i])
            {
                G[l - 1].push_back(i);
            }

            l = 0, r = i - 1;
            while (l < r)
            {
                m = (l + r) / 2;
                if (stM.query(m, i - 1) < H[i]) r = m;
                else l = m + 1;
            }

            if (l && stM.query(l, i - 1) < H[i])
            {
                G[l - 1].push_back(i);
            }
        }

        if (1)
        {
            l = i + 1, r = N;
            while (l < r)
            {
                m = (l + r) / 2;
                if (stm.query(i + 1, m) <= H[i]) r = m;
                else l = m + 1;
            }

            if (l < N && stm.query(i + 1, l) <= H[i])
            {
                G[i].push_back(l);
            }

            l = i + 1, r = N;
            while (l < r)
            {
                m = (l + r) / 2;
                if (stM.query(i + 1, m) >= H[i]) r = m;
                else l = m + 1;
            }

            if (l < N && stM.query(i + 1, l) >= H[i])
            {
                G[i].push_back(l);
            }
        }
    }

    bfs(0);

    cout << D[N - 1] << '\n';
}