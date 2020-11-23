#include <bits/stdc++.h>
using namespace std;

#define rep(i, n) for (int i = 0; i < (int)n; i++)

int T, N, K;
string A, B;
vector<int> CA, CB;

int main()
{
    cin >> T;
    while (T--)
    {
        cin >> N >> K >> A >> B;

        CA.assign(26, 0); CB.assign(26, 0);
        for (char c : A) CA[c - 'a']++;
        for (char c : B) CB[c - 'a']++;

        int c1 = 0, c2 = 0; bool flag = 1;
        rep(i, 26)
        {
            c1 += CA[i], c2 += CB[i];
            if (c1 < c2) flag = 0;
        }

        rep(i, 26) CA[i] %= K, CB[i] %= K;
        rep(i, 26) if (CA[i] != CB[i]) flag = 0;

        if (flag) cout << "Yes\n";
        else cout << "No\n";
    }
}