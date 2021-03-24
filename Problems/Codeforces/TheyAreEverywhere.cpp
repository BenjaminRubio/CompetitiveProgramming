#include <bits/stdc++.h>
using namespace std;

int N;
string S;
map<char, int> M;

int main()
{
    cin >> N >> S;

    set<char> s;
    for (char c : S) s.insert(c);

    int i = 0, j = -1, aux = 0, ans = INT_MAX;
    while (++j < N)
    {
        M[S[j]]++;
        if (M[S[j]] == 1) aux++;
        while (M[S[i]] > 1) M[S[i]]--, i++;

        if (aux == s.size()) ans = min(ans, j - i + 1);
    }

    cout << ans << '\n';
}