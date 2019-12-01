#include <bits/stdc++.h>
using namespace std;

int T, r, g, b;

int main()
{
    cin >> T;
    while (T--)
    {
        cin >> r >> g >> b;

        vector<int> nums = {r, g, b};
        sort(nums.begin(), nums.end());

        int ans = nums[0];
        if (nums[2] - nums[1] >= ans)
        {
            nums[2] -= ans;
            ans += nums[1];
            cout << ans << '\n';
        }
        else
        {
            int dif = nums[2] - nums[1];
            nums[2] -= dif;
            int dans = ans - dif;

            nums[1] -= dans - dans / 2;
            ans += nums[1];
            cout << ans << '\n';
        }
    }
}