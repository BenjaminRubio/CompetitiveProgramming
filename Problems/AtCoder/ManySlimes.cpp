#include <bits/stdc++.h>
using namespace std;
    
#define rep(i, n) for (int i = 0; i < (int)n; i++)
    
int N, X;
multiset<int, greater<int>> s;
queue<int> aux1;
vector<int> cur;
    
int main()
{
    cin >> N;
    
    rep(i, 1 << N)
    {
        cin >> X;
        s.insert(X);
    }
    
    cur.push_back(*(s.begin()));
    s.erase(s.begin());
    
    rep(i, N)
    {
        for (int c : cur)
        {
            auto it = s.upper_bound(c);

            if (it != s.end())
            {
                aux1.push(*it);
                s.erase(it);
                goto next;
            }
    
            cout << "No\n";
            return 0;
    
            next:
            continue;
        }
    
        while (!aux1.empty())
        {
            cur.push_back(aux1.front());
            aux1.pop();
        }
    }
    
    cout << "Yes\n";
}