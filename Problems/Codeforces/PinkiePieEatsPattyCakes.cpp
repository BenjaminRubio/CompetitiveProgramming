#include <bits/stdc++.h>
using namespace std;

#define rep(i, n) for (int i = 0; i < (int)n; i++)

int T, N, t;
map<int, int> M;

int main()
{
    cin >> T;
    while (T--)
    {
        M.clear();

        cin >> N;
        rep(i, N) { cin >> t; M[t]++; }

        vector<int> s;
        for (auto &p : M) s.emplace_back(p.second);

        sort(s.rbegin(), s.rend());

        int l = 0, r = N;
        while (l < r)
        {
            int m = (l + r) / 2 + 1;

            vector<int> C;
            rep(_, N % m) C.push_back(N / m + 1);
            rep(_, N - (N % m)) C.push_back(N / m);

            bool flag = true; int i = 0;
            for (int p : s)
            {
                if (i >= C.size() || p > C[i]) { flag = false; break; }
                if (p < C[i]) C.push_back(C[i] - p);
                i++;
            };

            if (!flag) r = m - 1;
            else l = m;
        }

        cout << l - 1 << '\n';
    }
}