#include <bits/stdc++.h>
using namespace std;

#define rep(i, n) for (int i = 0; i < (int)n; i++)

int N, p;
vector<int> arr, ans;
set<int> aux;

int main()
{
    while (cin >> N)
    {
        if (N == 0) break;

        arr.resize(N);
        bool pos = true;
        rep(i, N)
        {
            cin >> p;
            if (aux.find(p - 1) != aux.end()) pos = false;
            aux.insert(p - 1);
            arr[i] = p - 1;
        }

        if (!pos)
        {
            cout << "No solution\n";
            aux.clear();
            arr.clear();
            continue;
        }

        int M = 0;
        rep(i, N - 1)
        {
            int j = i;
            while (j >= 0 and arr[j + 1] < arr[j])
            {
                ans.push_back(j + 1);
                M++;
                swap(arr[j + 1], arr[j]);
                j--;
            }
        }

        if (M) cout << M << ' ';
        else cout << "0\n";
        rep(i, ans.size() - 1) cout << ans[i] << ' ';
        if (!ans.empty())cout << ans[ans.size() - 1] << '\n';

        aux.clear();
        arr.clear();
        ans.clear();
    }
}