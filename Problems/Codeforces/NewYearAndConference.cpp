#include <bits/stdc++.h>
using namespace std;

#define rep(i, n) for (int i = 0; i < (int)n; i++)
#define mp make_pair
#define ff first
#define ss second

int N;
vector<pair<int, int>> S, E;

bool solve(vector<pair<int, int>> &A, vector<pair<int, int>> &B)
{
    vector<pair<pair<int, int>, int>> E;
    rep(i, N) E.emplace_back(mp(A[i].ff, 0), i), E.emplace_back(mp(A[i].ss, 1), i);

    sort(E.begin(), E.end());

    multiset<int> s, e; int cnt = 0;
    for (auto &x : E)
    {
        if (x.ff.ss == 0)
        {
            if (s.empty()) cnt++;
            else if (s.upper_bound(B[x.ss].ss) == s.end() && *e.begin() >= B[x.ss].ff)
                cnt++;
            s.insert(B[x.ss].ff); e.insert(B[x.ss].ss);
        }
        if (x.ff.ss == 1) s.erase(s.find(B[x.ss].ff)), e.erase(e.find(B[x.ss].ss));
    }

    return cnt == N;
}

int main()
{
    cin >> N;

    S.resize(N); E.resize(N);
    rep(i, N) cin >> S[i].ff >> S[i].ss >> E[i].ff >> E[i].ss;

    if (solve(S, E) && solve(E, S)) cout << "YES\n";
    else cout << "NO\n";
}