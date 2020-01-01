#include <bits/stdc++.h>
using namespace std;

map<char, int> duration = {{'W', 64}, {'H', 32}, {'Q', 16}, {'E', 8}, {'S', 4}, {'T', 2}, {'X', 1}};
string composition;

int main()
{
    while (cin >> composition)
    {
        if (composition == "*")
            break;

        int sum = 0;
        int ans = 0;
        for (char c : composition)
        {
            if (c == '/')
            {
                if (sum == 64)
                    ans++;
                sum = 0;
            }
            else
            {
                sum += duration[c];
            }
        }

        cout << ans << '\n';
    }
}