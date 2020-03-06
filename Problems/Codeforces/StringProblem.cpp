#include <bits/stdc++.h>
using namespace std;

#define rep(i, n) for (int i = 0; i < (int)n; i++)

const int INF = 1e9;

int n, w;
string s, t;
char x, y;
vector<vector<int>> D;

void floydWarshall ()
{
    rep(k, 26) rep(i, 26) rep(j, 26) if (D[i][k] < INF && D[k][j] < INF)
        D[i][j] = min(D[i][j], D[i][k] + D[k][j]);
}

int main()
{
    cin.sync_with_stdio(0); cin.tie();
    cin.exceptions(cin.failbit);

    cin >> s >> t;
    cin >> n;

    D.assign(26, vector<int>(26, INF));
    rep(i, 26) D[i][i] = 0;
    rep(_, n)
    {
        cin >> x >> y >> w;
        D[x - 'a'][y - 'a'] = min(D[x - 'a'][y - 'a'], w);
    }

    floydWarshall();

    long long ans = 0;
    string ans_string;

    if (s.size() != t.size())
    {
        cout << -1 << '\n';
        return 0;
    }

    rep(i, s.size())
    {
        int aux = INF;
        int id;
        rep(j, 26)
        {
            int pos = D[s[i] - 'a'][j] + D[t[i] - 'a'][j];
            if (pos < aux)
            {
                aux = pos;
                id = j;
            }
        }
        if (aux == INF)
        {
            cout << -1 << '\n';
            return 0;
        }
        ans += aux;
        ans_string += char(id + 'a');
    }

    cout << ans << '\n';
    cout << ans_string << '\n';
}