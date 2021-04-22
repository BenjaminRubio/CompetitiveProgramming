#include <bits/stdc++.h>
using namespace std;

vector<int> P;

vector<int> factor(int x)
{
    vector<int> ans;
    for (int d : P)
    {
        if (d * d > x) break;
        while (x % d == 0)
        {
            ans.push_back(d);
            if ((x /= d) == 1) return ans;
        }
    }
    if (x > 1) ans.push_back(x);
    return ans;
}