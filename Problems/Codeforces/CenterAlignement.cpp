#include <bits/stdc++.h>
using namespace std;

#define rep(i, n) for (int i = 0; i < (int)n; i++)

string line;
vector<string> lines;

int main()
{
    int size = 0;
    while (getline(cin, line))
    {
        size = max(size, (int)line.size());
        lines.push_back(line);
    }

    rep(_, size + 2) cout << '*';
    cout << '\n';

    int i = 0;
    for (string line : lines)
    {
        cout << '*';

        int spaces = size - line.size();
        int spacel = spaces / 2 + (spaces % 2 == 1 && i % 2 == 1);

        rep(_, spacel) cout << ' ';
        cout << line;
        rep(_, spaces - spacel) cout << ' ';
        cout << "*\n";

        if (spaces % 2 == 1) i++;
    }

    rep(_, size + 2) cout << '*';
    cout << '\n';
}