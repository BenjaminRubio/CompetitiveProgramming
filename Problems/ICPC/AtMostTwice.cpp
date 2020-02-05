#include <bits/stdc++.h>
using namespace std;

#define rep(i, n) for (int i = 0; i < (int)n; i++)
#define repx(i, a, b) for (int i = (int)a; i < (int)b; i++)
#define rep_(i, n) for (int i = (int)n - 1; i >= 0; i--)

string num;
vector<vector<int>> cnt;

int main()
{
    while (cin >> num)
    {
        int n = num.size();

        cnt.assign(n, vector<int>(10, 0));

        bool bad = false;
        int s = n;
        rep(i, n)  
        {
            repx(j, i, n) cnt[j][num[i] - '0']++;
            if (!bad and cnt[i][num[i] - '0'] == 3)
                bad = true;
            if (!bad) s--;
        }

        if (!bad)
        {
            cout << num << '\n';
            continue;
        }

        repx(i, s - 1, n)
        {
            if (num[n - i - 1] != '0')
            {
                int aux = num[n - i - 1] - '0';
                rep_(k, aux) if (i == n - 1 or cnt[n - i - 2][k] < 2)
                {
                    vector<int> cnt_(10, 0);
                    if (i != n - 1) rep(j, 10) cnt_[j] = cnt[n - i - 2][j];
                    cnt_[k]++;

                    vector<int> c;
                    rep_(j, 10)
                    {
                        if (cnt_[j] < 2) c.push_back(j);
                        if (cnt_[j] < 1) c.push_back(j);
                        cnt_[j] = 2;

                        if (c.size() >= i)
                        {
                            string ans = num.substr(0, n - i - 1);
                            if (i != n - 1 or k != 0) ans += k + '0';
                            rep(l, i) ans += c[l] + '0';
                            cout << ans << '\n';
                            goto next;
                        }
                    }
                }
            }
        }

        next:
        continue;

    }
}
