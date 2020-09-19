#include <bits/stdc++.h>
using namespace std;

typedef unsigned int ui;
#define rep(i, n) for (int i = 0; i < (int)n; i++)

struct M
{
    ui m[65][65] = {0};
    M operator*(const M &o)
    {
        M ans;
        rep(i, 65) rep(j, 65) rep(k, 65)
            ans.m[i][k] = ans.m[i][k] + m[i][j] * o.m[j][k];
        return ans;
    }
};

int K;

int main()
{
    cin >> K; K++;

    M ans, A; ans.m[0][0] = 1;

    rep(i, 64) rep(j, 64)
    {
        int r = i / 8, c = i % 8, r_ = j / 8, c_ = j % 8;
        if (abs(r - r_) && abs(c - c_) && abs(r - r_) + abs(c - c_) == 3) A.m[i][j] = 1;
        A.m[i][64] = 1;
    } A.m[64][64] = 1;

    while (K)
    {
        if (K & 1) ans = ans * A;
        A = A * A, K >>= 1;
    }

    cout << ans.m[0][64] << '\n';
}