#include <bits/stdc++.h>
using namespace std;

#define rep(i, n) for (int i = 0; i < (int)n; i++)
#define repx(i, a, b) for (int i = (int)a; i < (int)b; i++)

int T, N;
vector<int> A;
map<int, stack<int>> M;

int main()
{
    cin >> T;
    while (T--)
    {
        cin >> N;
        M.clear();

        set<int> s;
        rep(i, N + 1) s.insert(i);

        A.resize(N);
        rep(i, N)
        {
            cin >> A[i];
            M[A[i]].push(i);
            s.erase(A[i]);
        }

        int c = 0;
        vector<int> ans;
        rep(i, N + 1)
        {
            while (M[i].size() > 1)
            {
                c++;
                A[M[i].top()] = *s.begin();
                s.erase(s.begin());
                ans.push_back(M[i].top() + 1); M[i].pop();
            }
        }

        if (!M[N].empty())
        {
            c++;
            A[M[N].top()] = *s.begin();
            ans.push_back(M[N].top() + 1); M[N].pop();
        }

        vector<bool> V(N, false);
        rep(l_, N)
        {
            int l = N - l_ - 1;
            if (l_)
            {
                l = -1;
                rep(i, N) if (!V[i] && A[i] == N - l_) l = i;

                if (l == -1) continue;
            }

            if (A[l] == l + 1) V[l] = 1;
            if (!V[l]) while (1)
            {
                V[l] = 1, c++;
                ans.push_back(l + 1);
                int aux = l;
                l = A[aux] - 1;
                A[aux] = aux + 1;
                if (l == -1 || V[l]) break;
            }
        }

        // rep(i, N) cerr << A[i] << ' ';
        // cerr << '\n';

        cout << c << '\n';
        for (int x : ans) cout << x << ' ';
        cout << '\n';
    }
}