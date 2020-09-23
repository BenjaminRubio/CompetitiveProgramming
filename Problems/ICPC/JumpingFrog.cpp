#include <bits/stdc++.h>
using namespace std;

#define rep(i, n) for (int i = 0; i < (int)n; i++)

int N;
string S;
vector<bool> A;

int main()
{
    cin >> N >> S;

    A.assign(N, 0);
    rep(i, N) A[i] = S[i] == 'R';

    vector<int> M(N, -1);
    rep(K, N) if 
}