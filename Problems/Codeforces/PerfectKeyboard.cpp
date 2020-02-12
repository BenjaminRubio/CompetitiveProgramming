#include <bits/stdc++.h>
using namespace std;

#define rep(i, n) for (int i = 0; i < (int)n; i++)

int T, n;
string s;
vector<set<int>> ad;

int main()
{
    cin >> T;
    rep(t, T)
    {
        ad.clear();
        cin >> s;
        n = s.size();

        if (n == 1)
        {
            cout << "YES\n";
            rep(i, 26) cout << char(i + 'a');
            cout << '\n';
            continue;
        }

        ad.resize(26);
        rep(i, n)
        {
            if (i) ad[s[i] - 'a'].insert(s[i - 1] - 'a');
            if (i < n - 1) ad[s[i] - 'a'].insert(s[i + 1] - 'a');
        }

        bool good = true;
        int c = 0;
        int id;
        rep(i, 26)
        {
            if (ad[i].size() > 2) good = false;
            if (ad[i].size() == 1)
            {
                c++;
                id = i;
            }
        }

        if (!good or c != 2)
        {
            cout << "NO\n";
            continue;
        }

        string aux;
        aux += id + 'a';
        int last = id;
        id = *(ad[id].begin());
        while (true)
        {
            int new_id = last;
            aux += id + 'a';
            for (int i : ad[id]) if (i != last) { new_id = i; break; }
            if (new_id == last) break;
            last = id;
            id = new_id;
        }

        rep(i, 26)
        {
            bool in = false;
            rep(j, aux.size()) if (aux[j] == i + 'a') in  = true;
            if (!in) aux += i + 'a';
        }

        cout << "YES\n";
        cout << aux << '\n';
    }
}