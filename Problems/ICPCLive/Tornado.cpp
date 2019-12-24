#include <bits/stdc++.h>
using namespace std;

int N, x;

int main()
{
    while(cin >> N)
    {
        if (N == 0)
            break;

        int ans = 0;
        int gap = 0;
        int firstgap = -1;
        for (int i = 0; i < N; i++)
        {
            cin >> x;
            if (x == 0)
                gap++;
            else
            {
                if (firstgap == -1)
                    firstgap = gap;
                else
                    ans += gap / 2;
                gap = 0;
            }
        }
        if (firstgap != -1)
            ans += (firstgap + gap) / 2;
        else
            ans += gap / 2 + N % 2;

        cout << ans << '\n';
    }
}