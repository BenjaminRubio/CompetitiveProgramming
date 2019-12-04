#include <bits/stdc++.h>
using namespace std;

int n;
char sep;
vector<int> v;

int main()
{
    while (cin >> n)
    {
        cin >> sep;
        v.push_back(n);
    }

    v[1] = 12;
    v[2] = 2;

    int i = 0;
    while (true)
    {
        int action = v[i];
        if (action == 1)
            v[v[i + 3]] = v[v[i + 1]] + v[v[i + 2]];
        if (action == 2)
            v[v[i + 3]] = v[v[i + 1]] * v[v[i + 2]];
        if (action == 99)
            break;
        if (action != 1 && action != 2 && action != 99)
            cerr << "Error\n";
        i += 4;
    }

    cout << v[0] << '\n';
}