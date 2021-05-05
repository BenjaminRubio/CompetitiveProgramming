#include <bits/stdc++.h>
using namespace std;

#define rep(i, n) for (int i = 0; i < (int)n; i++)

int X[4], Y[4];
int X1[2], Y1[2], X2[3], Y2[3];

bool in(int x, int y)
{
    return x >= X1[0] && x <= X1[1] && y >= Y1[0] && y <= Y1[1];
}

bool in_(int x, int y)
{
    return x + y >= X2[0] + Y2[1] && x + y <= X2[1] + Y2[2] && 
           x - y >= X2[0] - Y2[1] && x - y <= X2[1] - Y2[0];
}

int main()
{
    rep(i, 4) cin >> X[i] >> Y[i];
    sort(X, X + 4); sort(Y, Y + 4);

    X1[0] = X[0], X1[1] = X[2];
    Y1[0] = Y[0], Y1[1] = Y[2];

    rep(i, 4) cin >> X[i] >> Y[i];
    sort(X, X + 4); sort(Y, Y + 4);

    X2[0] = X[0], X2[1] = X[1], X2[2] = X[3];
    Y2[0] = Y[0], Y2[1] = Y[1], Y2[2] = Y[3];

    bool ans = in(X2[0], Y2[1]) || in(X2[1], Y2[0]) || in(X2[1], Y2[2]) || in(X2[2], Y2[1]);
    ans = ans || in_(X1[0], Y1[0]) || in_(X1[0], Y1[1]) || in_(X1[1], Y1[0]) || in_(X1[1], Y1[1]);
    ans = ans || in(X2[1], Y2[1]) || in_((X1[0] + X1[1]) / 2, (Y1[0] + Y1[1]) / 2);

    cout << (ans ? "YES" : "NO") << '\n';
}
