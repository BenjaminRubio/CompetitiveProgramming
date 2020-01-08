#include <bits/stdc++.h>
using namespace std;

#define rep(i, n) for (int i = 0; i < (int)n; i++)
#define repx(i, a, b) for (int i = (int)a; i < (int)b; i++)

int N, R, Q, l, r;
vector<int> p;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int test = 0;
    while (cin >> N)
    {
        if (N == 0)
            break;

        test++;
        p.resize(N);
        rep(i, N) p[i] = i + 1;

        cin >> R;
        rep(i, R)
        {
            vector<int> p_;
            rep(i, N) p_.push_back(p[i]);

            cin >> l >> r;
            repx(j, l - 1, r)
                p_[j] = p[r - (j - l + 1) - 1];

            swap(p, p_);
        }

        cout << "Genome " << test << '\n';

        cin >> Q;
        rep(i, Q)
        {
            cin >> l;
            rep(i, N) if (p[i] == l) cout << i + 1 << '\n';
        }
    }
}