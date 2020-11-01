#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define rep(i, n) for (int i = 0; i < (int)n; i++)

const int MAX = 1000001;

struct Trie
{
	int N[MAX][26] = {0}, c = 0;
	Trie() {}
    void clear() { memset(N[0], 0, sizeof N[0]); c = 0; }
	void add(string x, int a = 1)
    {
		int p = 0; for (char l : x)
        {
			int t = l - 'a';
			if (!N[p][t])
            {
                N[p][t] = ++c;
                memset(N[c], 0, sizeof N[c]);
            }
			p = N[p][t];
		}
	}
};

int N, M; ll ans;
string s;
vector<ll> C;

int main()
{
    ios::sync_with_stdio(0); cin.tie(0);

    Trie P, S;
    while (cin >> N >> M && N)
    {
        P.clear(); S.clear();
        rep(_, N)
        {
            cin >> s;
            P.add(s);
        }
        rep(_, M)
        {
            cin >> s;
            reverse(s.begin(), s.end());
            S.add(s);
        }

        ans = (ll)P.c * (ll)S.c;
        C.assign(26, 0);
        rep(p, P.c) if (p) rep(t, 26) if (P.N[p][t]) C[t]++;
        rep(p, S.c) if (p) rep(t, 26) if (S.N[p][t]) ans -= C[t];

        cout << ans << '\n';
    }
}