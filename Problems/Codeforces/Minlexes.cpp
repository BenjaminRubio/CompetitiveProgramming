#include <bits/stdc++.h>
using namespace std;

#define rep(i, n) for (int i = 0; i < (int)n; i++)

string s, aux;

int main()
{
    cin >> s;

    int N = s.size();

    stack<char> p; p.push(-1);
    char l = -1; int c = 0; int d = 0;
    stack<string> ans; stack<int> ss;
    rep(i, N)
    {
        char n = s[N - i - 1];
        if (d == 0 && n == l && n > p.top())
        {
            aux.pop_back();
            if (!c) l = p.top(), p.pop();
            d = 1, c = 0;
        }
        else
        {
            aux.push_back(n);
            if (n != l) { c = 0; p.push(l); l = n; }
            else c++;
            d = 0;
        }

        ss.push(aux.size());
        if (aux.size() <= 10) ans.push(aux);
        else
        {
            string temp;
            temp.push_back(aux[0]);
            temp.push_back(aux[1]);
            rep(i, 3) temp.push_back('.');
            temp.push_back(aux[aux.size() - 5]);
            temp.push_back(aux[aux.size() - 4]);
            temp.push_back(aux[aux.size() - 3]);
            temp.push_back(aux[aux.size() - 2]);
            temp.push_back(aux[aux.size() - 1]);

            ans.push(temp);
        }
    }

    while (!ans.empty())
    {
        cout << ss.top() << ' '; ss.pop();
        string o = ans.top(); ans.pop();

        reverse(o.begin(), o.end());

        cout << o << '\n';
    }
}