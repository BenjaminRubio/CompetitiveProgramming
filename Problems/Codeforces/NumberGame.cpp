#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define rep(i, n) for (ll i = 0; i < (ll)n; i++)

ll T, N;

pair<ll, ll> trial_division(ll n) {
	ll factors = 0;
    int e = 1;
	for (ll d = 2; d * d <= n; d++)
        while (n % d == 0) { factors += (d % 2); n /= d; e *= 2 * (d == 2); }
	if (n > 1 && n % 2 == 1) { factors++; n = 1; }
	return {factors, e};
}

int main()
{
    cin >> T;
    while (T--)
    {
        cin >> N;

        if (N == 1) { cout << "FastestFinger\n"; continue; } 
        if (N == 2) { cout << "Ashishgup\n"; continue; } 
        if (N % 2) { cout << "Ashishgup\n"; continue; } 

        pair<ll, ll> f = trial_division(N);
        if (f.second == 2) 
        {
            if (f.first > 1) { cout << "Ashishgup\n"; continue; }
            else { cout << "FastestFinger\n"; continue; } 
        }
        if (f.first) cout << "Ashishgup\n";
        else cout << "FastestFinger\n";
    }
}