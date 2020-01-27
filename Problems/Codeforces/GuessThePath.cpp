#include <bits/stdc++.h>
using namespace std;

#define rep(i, n) for (int i = 0; i < (int)n; i++)

int n, m, t, r, c;

string make_path(vector<int> &D, vector<int> &L)
{
    string p = "";

    rep(k, L.size())
    {
        rep(_, D[k]) p += 'D';
        rep(_, L[k]) p += 'L';
    }
    rep(_, D[D.size() - 1]) p += 'D';

    return p;
}

int main()
{
    cin >> n >> m;

    vector<int> D = {n / 2, n - n / 2};
    vector<int> L = {m};
    rep(i, 10)
    {
        string p = make_path(D, L);
        cout << p << endl;

        cin >> t;
        rep(i, t)
        {

        }
    }
}
