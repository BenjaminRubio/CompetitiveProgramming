#include <bits/stdc++.h>
using namespace std;

int n;
char sep;
vector<int> v, w;

int main()
{
    while (cin >> n)
    {
        cin >> sep;
        w.push_back(n);
    }

    for (int x = 0; x < 100; x++) for (int y = 0; y < 100; y++)
    {
        v = w;

        v[1] = x;
        v[2] = y;

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

        if (v[0] == 19690720)
        {
            cout << 100 * v[1] + v[2] << '\n';
            return 0;
        }
    }
}