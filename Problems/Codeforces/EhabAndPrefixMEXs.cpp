#include <bits/stdc++.h>
using namespace std;

#define rep(i, n) for (int i = 0; i < (int)n; i++)
#define repx(i, a, b) for (int i = (int)a; i < (int)b; i++)

int N;
vector<int> a, b, l;

int main()
{
    cin >> N;

    a.resize(N);
    set<int> s;
    rep(i, N) { cin >> a[i]; s.insert(a[i]); }

    priority_queue<int, vector<int>, greater<int>> q;
    rep(i, 2 * N) if (!s.count(i)) q.push(i);

    b.push_back(q.top()); q.pop();
    rep(i, N - 1)
    {
        if (a[i] != a[i + 1]) b.push_back(a[i]);
        else { b.push_back(q.top()); q.pop(); }
    }

    for (int x : b) cout << x << ' ';
    cout << '\n';
}