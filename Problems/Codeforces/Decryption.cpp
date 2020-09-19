#include <bits/stdc++.h>
using namespace std;

#define rep(i, n) for (int i = 0; i < (int)n; i++)

vector<int> primes(int n)
{
	vector<int> factors;
	for (int d = 2; d*d <= n; d++)
    {
        int p = d;
        if (n % d == 0) factors.push_back(p);
		while (n % d == 0) if ((n /= d) == 1) return factors;
	}
	if (n > 1) factors.push_back(n);
	return factors;
}

vector<int> trial_division(int n)
{
	vector<int> factors;
	for (int d = 2; d*d <= n; d++)
    {
        int p = d;
		while (n % d == 0)
        {
			factors.push_back(p);
            p = p * d;
			if ((n /= d) == 1) return factors;
		}
	}
	if (n > 1) factors.push_back(n);
	return factors;
}

set<int> divisors(int n) 
{
    set<int> d;
    for (int i=1; i<= sqrt(n); i++) if (n%i == 0)
    {
        d.insert(i);
        if (n/i != i) d.insert(n / i); 
    }
    d.erase(1);
    return d;
}

int T, N;

int main()
{
    cin >> T;

    while (T--)
    {
        cin >> N;

        vector<int> o = primes(N);
        vector<int> p = trial_division(N);
        set<int> d = divisors(N);

        if (p.size() == 2 && __gcd(p[0], p[1]) == 1)
        {
            cout << p[0] << ' ' << p[1] << ' ' << N << '\n';
            cout << 1 << '\n';
            continue;
        }

        int s = p.size();

        map<int, int> dir;
        vector<int> ans;
        rep(i, s)
        {
            if (__gcd(p[i], p[((i - 1) % s + s) % s]) == 1) dir[ans.size()] = p[i];
            ans.push_back(p[i]); d.erase(p[i]);
            if (__gcd(p[(i + 1) % s], p[i]) == 1)
            {
                ans.push_back(p[i] * p[(i + 1) % s]);
                d.erase(p[i] * p[(i + 1) % s]);
            }
        }

        map<int, vector<int>> m;
        for (int pr : o)
        {
            queue<int> e;
            for (int d_ : d) if (__gcd(pr, d_) != 1)
            {
                m[pr].push_back(d_);
                e.push(d_);
            }
            while (!e.empty()) d.erase(e.front()), e.pop();
        }

        rep(i, ans.size()) 
        {
            cout << ans[i] << ' ';
            if (dir[i]) for (int x : m[dir[i]]) cout << x << ' ';
        }
        cout << '\n' << 0 << '\n';
    }
}