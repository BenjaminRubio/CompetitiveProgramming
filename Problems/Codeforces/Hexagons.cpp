#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define rep(i, n) for (int i = 0; i < (int)n; i++)

ll T, x, y, x_, y_, C[7], a, b, c, d;

int main()
{
    cin >> T;
    while (T--)
    {
        cin >> x_ >> y_;

        rep(i, 6) cin >> C[i + 1];

        ll ans;
        if (x_ <= 0 && y_ <= 0)
        {
            if (y_ == 0) ans = min((ll)abs(x_) * C[3], (ll)abs(x_) * (C[2] + C[4]));
            else if (x_ == 0) ans = min((ll)abs(y_) * C[5], (ll)abs(y_) * (C[6] + C[4]));
            else if (x_ == y_) ans = min((ll)abs(x_) * C[4], (ll)abs(x_) * (C[3] + C[5]));
            else if (x_ > y_)
            {
                a = C[5], b = C[4], c = C[6], d = C[3];
                x = abs(y_ - x_), y = abs(x_);
                ans = a * x + b * y;
                if (c + b < a) ans = c * x + b * (x + y);
                if (d + a < b) ans = d * y + a * (x + y);
            }
            else if (y_ > x_)
            {
                a = C[4], b = C[3], c = C[5], d = C[2];
                x = abs(y_), y = abs(x_ - y_);
                ans = a * x + b * y;
                if (c + b < a) ans = c * x + b * (x + y);
                if (d + a < b) ans = d * y + a * (x + y);
            }
        }
        else if (x_ >= 0 && y_ >= 0)
        {
            if (y_ == 0) ans = min((ll)abs(x_) * C[6], (ll)abs(x_) * (C[1] + C[5]));
            else if (x_ == 0) ans = min((ll)abs(y_) * C[2], (ll)abs(y_) * (C[1] + C[3]));
            else if (x_ == y_) ans = min((ll)abs(x_) * C[1], (ll)abs(x_) * (C[2] + C[6]));
            else if (x_ > y_)
            {
                a = C[1], b = C[6], c = C[2], d = C[5];
                x = abs(y_), y = abs(y_ - x_);
                ans = a * x + b * y;
                if (c + b < a) ans = c * x + b * (x + y);
                if (d + a < b) ans = d * y + a * (x + y);
            }
            else if (y_ > x_)
            {
                a = C[2], b = C[1], c = C[3], d = C[6];
                x = abs(y_ - x_), y = abs(x_);
                ans = a * x + b * y;
                if (c + b < a) ans = c * x + b * (x + y);
                if (d + a < b) ans = d * y + a * (x + y);
            }
        }
        else
        {
            if (x_ > 0)
            {
                a = C[5], b = C[6], c = C[4], d = C[1];
                x = abs(y_), y = abs(x_);
                ans = a * x + b * y;
                if (c + b < a) ans = c * x + b * (x + y);
                if (d + a < b) ans = d * y + a * (x + y);
            }
            else if (y_ > 0)
            {
                a = C[2], b = C[3], c = C[1], d = C[4];
                x = abs(y_), y = abs(x_);
                ans = a * x + b * y;
                if (c + b < a) ans = c * x + b * (x + y);
                if (d + a < b) ans = d * y + a * (x + y);
            }
        }

        cout << ans << '\n';
    }
}