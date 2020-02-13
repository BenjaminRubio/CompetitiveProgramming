#include <bits/stdc++.h>
using namespace std;

#define rep(i, n) for (int i = 0; i < (int)n; i++)
#define ff first
#define ss second

int n, m, k;
vector<pair<int, string>> movs;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> n >> m >> k;

    if (k > 2 * n * (m - 1) + 2 * m * (n - 1))
    {
        cout << "NO\n";
        return 0;
    }

    int moves = k;
    int h = max(0, n - 1);
    int v = max(0, m - 1);
    while (moves)
    {
        if (h > 0)
        {
            if (m - 1) movs.push_back({min(moves, m - 1), " R\n"});
            if (m - 1 and moves > m - 1)
                movs.push_back({min(moves - m + 1, m - 1), " L\n"});
            if (moves > 2 * (m - 1))
                movs.push_back({1, " D\n"});
            h--; moves = max(0, moves - 2 * m + 1);
            continue;
        }
        if (h == 0)
        {
            if (m - 1) movs.push_back({min(moves, m - 1), " R\n"});
            h--; moves = max(0, moves - m + 1);
            continue;
        }
        if (v > 0)
        {
            if (n - 1) movs.push_back({min(moves, n - 1), " U\n"});
            if (n - 1 and moves > n - 1)
                movs.push_back({min(moves - n + 1, n - 1), " D\n"});
            if (moves > 2 * (n - 1))
                movs.push_back({1, " L\n"});
            v--; moves = max(0, moves - 2 * n + 1);
            continue;
        }
        if (v == 0)
        {
            if (n - 1) movs.push_back({min(moves, n - 1), " U\n"});
            v--; moves = max(0, moves - n + 1);
            continue;
        }
    }

    cout << "YES\n";
    cout << movs.size() << '\n';
    for (auto e : movs) cout << e.ff << e.ss;
}