#include <bits/stdc++.h>
using namespace std;

int T, n;
vector<string> pins;
set<string> dif_pins;
vector<int> counts;

int main()
{
    cin >> T;
    while (T--)
    {
        cin >> n;
        dif_pins.clear();
        pins.resize(n);
        counts.assign(10, 0);
        int ans = 0;

        for (int i = 0; i < n; i++)
        {
            cin >> pins[i];
            counts[pins[i][0] - '0']++;
        }

        for (int i = 0; i < n; i++)
        {
            if (dif_pins.count(pins[i]) > 0)
            {
                ans++;
                for (int j = 0; j < 10; j++)
                {
                    if (counts[j] != 0)
                        continue;
                    pins[i][0] = char(j) + '0';
                    if (dif_pins.count(pins[i]) == 0)
                        break;
                }
            }
            dif_pins.insert(pins[i]);
        }

        cout << ans << '\n';
        for (int i = 0; i < n; i++)
            cout << pins[i] << '\n';
    }
}