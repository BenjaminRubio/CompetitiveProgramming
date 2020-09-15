#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define rep(i, n) for (ll i = 0; i < (ll)n; i++)

ll T, N;
vector<ll> A, V, V_;

int main()
{
    cin >> T;
    while (T--)
    {
        V.clear(); V_.clear();
        cin >> N;

        A.resize(N);
        multiset<pair<ll, ll>> S;
        rep(i, N)
        {
            cin >> A[i];
            if (A[i] >= 0) V.push_back(A[i]);
            else V_.push_back(-A[i]);
            S.emplace(abs(A[i]), A[i] >= 0);
        }

        sort(V.begin(), V.end());
        sort(V_.begin(), V_.end());

        int i1 = V.size() - 1, i2 = V_.size() - 1;
        ll ans = LLONG_MIN;
        
        if (i1 > 3) ans = max(ans, V[i1] * V[i1 - 1] * V[i1 - 2] * V[i1 - 3] * V[i1 - 4]);
        if (i1 > 1 && i2 > 0) ans = max(ans, V[i1] * V[i1 - 1] * V[i1 - 2] * V_[i2] * V_[i2 - 1]);
        if (i1 > -1 && i2 > 2) ans = max(ans, V[i1] * V_[i2] * V_[i2 - 1] * V_[i2 - 2] * V_[i2 - 3]);

        ll ans_ = 1, i = 0;
        while (i < 5)
        {
            pair<ll, ll> aux = *S.begin();
            ans_ *= aux.first * (aux.second ? 1 : -1);
            S.erase(S.find(aux));
            i++;
        }

        cout << max(ans, ans_) << '\n';
    }
}