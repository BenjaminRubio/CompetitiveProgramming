#include <bits/stdc++.h>
using namespace std;

#define rep(i, n) for (int i = 0; i < (int)n; i++)
#define repx(i, a, b) for (int i = (int)a; i < (int)b; i++)

int n, b;
vector<int> numbers;
set<int> diffs;

int main()
{
    while (cin >> n >> b)
    {
        if (n == 0 && b == 0)
            break;

        numbers.resize(b);
        rep(i, b) cin >> numbers[i];

        rep(i, b) repx(j, i + 1, b)
            diffs.insert(abs(numbers[i] - numbers[j]));

        if (diffs.size() == n)
            cout << "Y\n";
        else
            cout << "N\n";

        diffs.clear();
    }
}