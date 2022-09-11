#include <bits/stdc++.h>
using namespace std;

int N;
string S;

int main()
{
    cin >> N >> S;

    set<char> s;
    for (char c : S) s.insert(c);

    int total = s.size();

    map<char, int> M;
    int ans = N, cnt = 0, pos = 0;
    for (int i = 0; i < N; i++)
    {
        while (pos < N && cnt < total)
        {
            M[S[pos]]++;
            if (M[S[pos]] == 1) cnt++;
            pos++;
        }

        if (cnt == total) ans = min(ans, pos - i);

        M[S[i]]--;
        if (M[S[i]] == 0) cnt--;
    }

    cout << ans << '\n';
}