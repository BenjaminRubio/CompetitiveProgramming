#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;

#define rep(i, n) for (int i = 0; i < (int)n; i++)
#define repx(i, a, b) for (int i = (int)a; i < (int)b; i++)

int N, x;
int p1[14], p2[14];
vector<int> aux1, aux2;
int memo1[9][1 << 18];
int memo2[9][1 << 18];

int count1(int t, int b)
{
    if (t >= (int)aux1.size() / 3)
        return 0;

    if (memo1[t][b] != -1)
        return memo1[t][b];

    int ans = 0;
    rep(i, aux1.size()) if (!(b & (1 << i)))
    {
        repx(j, i + 1, aux1.size()) if (!(b & (1 << j)))
        {
            bool broke = false;
            repx(k, j + 1, aux1.size()) if (!(b & (1 << k)))
            {
                if (aux1[i] + aux1[j] > aux1[k] &&
                    aux1[j] + aux1[k] > aux1[i])
                {
                    ans = max(ans, 1 + count1(t + 1, b | (1 << i) | (1 << j) | (1 << k)));
                    broke = true;
                    break;
                }
            }
            if (broke)
                break;
        }
    }

    return memo1[t][b] = ans;
}

int count2(int t, int b)
{
    if (t >= (int)aux2.size() / 3)
        return 0;

    if (memo2[t][b] != -1)
        return memo2[t][b];

    int ans = 0;
    rep(i, aux2.size()) if (!(b & (1 << i)))
    {
        repx(j, i + 1, aux2.size()) if (!(b & (1 << j)))
        {
            bool broke = false;
            repx(k, j + 1, aux2.size()) if (!(b & (1 << k)))
            {
                if (aux2[i] + aux2[j] > aux2[k] &&
                    aux2[j] + aux2[k] > aux2[i])
                {
                    ans = max(ans, 1 + count2(t + 1, b | (1 << i) | (1 << j) | (1 << k)));
                    broke = true;
                    break;
                }
            }
            if (broke)
                break;
        }
    }

    return memo2[t][b] = ans;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    while (cin >> N)
    {
        if (N == 0)
            break;

        memset(p1, 0, sizeof p1);
        memset(p2, 0, sizeof p2);
        rep(i, N)
        {
            cin >> x;
            if (i % 2 == 0)
                p1[x]++;
            else
                p2[x]++;
        }

        int a1 = 0, a2 = 0;
        repx(i, 1, 14) if (p1[i] > 2)
        {
            a1 += p1[i] / 3;
            p1[i] %= 3;
        }
        repx(i, 1, 14) if (p2[i] > 2)
        {
            a2 += p2[i] / 3;
            p2[i] %= 3;
        }

        if (a1 != a2)
        {
            if (a1 > a2)
                cout << 1 << '\n';
            else if (a2 > a1)
                cout << 2 << '\n';
            continue;
        }

        repx(i, 1, 14) while (p1[i])
        {
            aux1.push_back(i);
            p1[i]--;
        }
        repx(i, 1, 14) while (p2[i])
        {
            aux2.push_back(i);
            p2[i]--;
        }

        memset(memo1, -1, sizeof memo1);
        memset(memo2, -1, sizeof memo2);
        int b1 = count1(0, 0);
        int b2 = count2(0, 0);
        aux1.clear();
        aux2.clear();

        if (b1 > b2)
            cout << 1 << '\n';
        else if (b2 > b1)
            cout << 2 << '\n';
        else
            cout << 0 << '\n';
    }
}