#include <bits/stdc++.h>
using namespace std;

#define rep(i, n) for (int i = 0; i < (int)n; i++)

int N;
string S;
vector<pair<int, int>> P;

int main()
{
    cin >> S; N = S.size();

    stack<int> s;
    rep(i, N)
    {
        if (S[i] == '(') s.push(i);
        if (S[i] == ')') { P.emplace_back(s.top(), i); s.pop(); }
    }

    int M = P.size();

    set<string> ans;
    rep(b, (1 << M) - 1)
    {
        set<int> out;
        rep(i, M) if (!(b & (1 << i))) out.insert(P[i].first), out.insert(P[i].second);

        string aux;
        rep(i, N) if (!out.count(i)) aux += S[i];

        ans.insert(aux);
    }

    for (string aux : ans) cout << aux << '\n';
}