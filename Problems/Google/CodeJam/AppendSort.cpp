#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define rep(i, n) for (ll i = 0; i < (ll)n; i++)

ll N;
vector<string> X;

bool lesss(string a, string b)
{
    if (a.size() != b.size()) return (a.size() < b.size());
    else return a < b;
}

string add(string x)
{
    string a = x;

    int i = a.size() - 1;
    while (a[i] == '9') a[i] = '0', i--;
    a[i] += 1;

    return a;
}

void test_case()
{
    cin >> N;

    X.resize(N);
    rep(i, N) cin >> X[i];

    ll ans = 0;
    rep(i, N - 1)
    {
        string sa = X[i], sb = X[i + 1];

        if (lesss(sa, sb)) continue;
        if (sa.size() == sb.size()) { X[i + 1] = sb + '0', ans++; continue; }
        
        ll d = sa.size() - sb.size();
        string sb1 = sb, sb2 = sb;
        rep(_, d) sb1 += '9', sb2 += '0';

        string sap = sa.substr(0, sa.size() - d);
        if ((sa == sb1) || lesss(sb, sap)) { X[i + 1] = sb2 + '0', ans += d + 1; continue; }
        if (lesss(sap, sb)) { X[i + 1] =  sb2, ans += d; continue; }
        if (sap == sb) { X[i + 1] = add(sa), ans += d; continue; }
    }

    cout << ans << '\n';
}

int main()
{
    ll TT; cin >> TT;
    rep(tt, TT)
    {
        cout << "Case #" << tt + 1 << ": ";
        test_case();
    }
}