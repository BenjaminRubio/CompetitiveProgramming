#include <bits/stdc++.h>
using namespace std;

#define rep(i, n) for (int i = 0; i < (int)n; i++)

int T, N;
vector<int> a;
vector<int> L, R, LM, RM;

int main()
{
    cin >> T;
    while (T--)
    {
        cin >> N;
        
        a.resize(N);
        rep(i, N) cin >> a[i];

        int lM = -1, rM = -1;
        set<int> l, r;
        L.resize(N), R.resize(N); LM.resize(N), RM.resize(N);
        rep(i, N)
        {
            l.insert(a[i]); r.insert(a[N - i - 1]);
            lM = max(lM, a[i]); rM = max(rM, a[N - i - 1]);
            L[i] = l.size(); R[i] = r.size();
            LM[i] = lM; RM[i] = rM;
        }

        int k = 0;
        rep(i, N - 1)
            if (L[i] == i + 1 and R[N - i - 2] == N - i - 1 and
                LM[i] == i + 1 and RM[N - i - 2] == N - i - 1) k++;
        
        cout << k << '\n';
        rep(i, N - 1) if (L[i] == i + 1 and R[N - i - 2] == N - i - 1 and
                LM[i] == i + 1 and RM[N - i - 2] == N - i - 1)
        {
            cout << i + 1 << ' ' << N - i - 1 << '\n';
        }
    }
}