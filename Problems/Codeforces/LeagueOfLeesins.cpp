#include <bits/stdc++.h>
using namespace std;

#define rep(i, n) for (int i = 0; i < (int)n; i++)
#define repx(i, a, b) for (int i = (int)a; i < (int)b; i++)

typedef vector<int> vi;
typedef pair<int, int> par;
typedef vector<par> vp;
typedef long long ll;

int n, q1, q2, q3;
map<int, set<int>> counts;
vector<vector<int>> sets;

int main()
{
    cin >> n;

    rep(i, n) counts[i + 1] = {};

    sets.resize(n - 2);
    rep(i, n - 2)
    {
        cin >> q1 >> q2 >> q3;
        counts[q1].insert(i);
        counts[q2].insert(i);
        counts[q3].insert(i);
        sets[i] = {q1, q2, q3};
    }

    int curr, last;
    rep(i, n)
    {
        if (counts[i + 1].size() == 1)
        {
            curr = *(counts[i + 1].begin());
            last = i + 1;
            cout << i + 1 << '\n';
            break;
        }
    }

    set<int> aux;
    while (true)
    {
        if (counts[last].size() == 3)
        {
            int sum = 0;
            for (int q : sets[curr])
                sum += counts[q].size();

            if (sum == 6)
            {
                for (int q : sets[curr])
                    if (counts[q].size() == 2)
                        cout << q << '\n';
                for (int q : sets[curr])
                    if (counts[q].size() == 1)
                        cout << q << '\n';
                break;
            }

            if (sum == 8)
            {
                for (int q : sets[curr])
                {
                    if (q != last && counts[q].size() == 3)
                    {
                        aux.clear();
                        set_difference(counts[q].begin(), counts[q].end(), counts[last].begin(), counts[last].end(), inserter(aux, aux.end()));
                        cout << q << '\n';
                        last = q;
                        curr = *(aux.begin());
                        break;
                    }
                }
                continue;
            }

            for (int q : sets[curr])
            {
                if (q != last)
                {
                    aux.clear();
                    set_difference(counts[q].begin(), counts[q].end(), counts[last].begin(), counts[last].end(), inserter(aux, aux.end()));
                    if (aux.size() == 1)
                    {
                        last = q;
                        curr = *(aux.begin());
                        cout << q << '\n';
                        break;
                    }
                }
            }
        }

        if (counts[last].size() == 1)
        {
            for (int q : sets[curr])
            {
                if (counts[q].size() == 2)
                {
                    cout << q << '\n';
                    last = q;
                }
            }
            for (int q : sets[curr])
            {
                if (counts[q].size() == 3)
                {
                    aux.clear();
                    set_difference(counts[q].begin(), counts[q].end(), counts[last].begin(), counts[last].end(), inserter(aux, aux.end()));
                    cout << q << '\n';
                    last = q;
                    curr = *(aux.begin());
                }
            }
        }
    }
}