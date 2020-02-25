#include <bits/stdc++.h>
using namespace std;
    
#define rep(i, n) for (int i = 0; i < (int)n; i++)
#define repx(i, a, b) for (int i = (int)a; i < (int)b; i++)
    
int T, n;
vector<int> b;
vector<bool> done;
    
int main()
{
    cin >> T;
    rep(_, T)
    {
        cin >> n;
    
        b.resize(n);
        rep(i, n) cin >> b[i];
    
        done.assign(2 * n + 1, false);
        rep(i, n) done[b[i]] = true;
    
        vector<int> ans;
        bool pos = false;
        rep(i, n)
        {
            ans.push_back(b[i]);
            pos = false;
            repx(j, b[i] + 1, 2 * n + 1) if (!done[j])
            {
                ans.push_back(j);
                done[j] = true;
                pos = true;
                break;
            }
    
            if (!pos) break;
        }
    
        if (!pos) cout << -1 << '\n';
        else
        {
            rep(i, 2 * n) cout << ans[i] << ' ';
            cout << '\n';
        }
    }
}