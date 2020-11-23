#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define rep(i, n) for (ll i = 0; i < (ll)n; i++)

ll T, D, K;

int main()
{
    cin >> T;
    while (T--)
    {
        cin >> D >> K;
        
        ll r = 0;
        while (2ll * (K * r) * (K * r) <= D * D) r++;
        r--;
        if ((K * r) * (K * r) + (K * (r + 1ll)) * (K * (r + 1ll)) <= D * D)
            cout << "Ashish\n";
        else cout << "Utkarsh\n";
    }
}