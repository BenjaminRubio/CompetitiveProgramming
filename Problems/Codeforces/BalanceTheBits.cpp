#include <bits/stdc++.h>
using namespace std;

#define rep(i, n) for (int i = 0; i < (int)n; i++)

int T, N;
string S;

int main()
{
    cin >> T;
    while (T--)
    {
        cin >> N >> S;

        vector<char> ans1(N); bool flag = 1;
        rep(i, N) if (S[i] == '0') ans1[i] = (flag ? ')' : '('), flag ^= 1;
        if (S[0] == '0' || S[N - 1] == '0' || !flag) { cout << "NO\n"; continue; }
        ans1[0] = '(', ans1[N - 1] = ')'; flag = 0;
        rep(i, N) if (i != 0 && i != N - 1 && S[i] == '1') ans1[i] = (flag ? ')' : '('), flag ^= 1;

        vector<char> ans2 = ans1;
        rep(i, N) if (S[i] == '0') ans2[i] = (ans1[i] == '(' ? ')' : '(');

        bool ok = 1; int on = 0;
        rep(i, N)
        {
            if (ans2[i] == '(') on++;
            if (ans2[i] == ')') on--;
            if (on < 0) ok = 0;
        }
        if (on != 0) ok = 0;

        if (!ok) cout << "NO\n";
        else
        {
            cout << "YES\n";
            rep(i, N) cout << ans1[i]; cout << '\n';
            rep(i, N) cout << ans2[i]; cout << '\n';
        }
    }
}