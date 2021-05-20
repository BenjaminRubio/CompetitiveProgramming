#include <bits/stdc++.h>
using namespace std;

using ul = unsigned long long;
using ll = long long;
using db = double;

using pii = pair<int, int>;
using pll = pair<ll, ll>;
using pdd = pair<db, db>;

using vp = vector<pii>;
using vi = vector<int>;
using vl = vector<ll>;
using vd = vector<db>;

#define rep(i, n) for (int i = 0; i < (int)n; i++)
#define repx(i, a, b) for (int i = (int)a; i < (int)b; i++)
#define all(x) begin(x), end(x)
#define eb emplace_back
#define pb push_back
#define mp make_pair
#define ff first
#define ss second

int N;

void test_case(int test)
{
    int i = 0, stat;
    while (i < N - 1)
    {
        cout << "M " << i + 1 << ' ' << N << endl;
        int p; cin >> p; p--;

        if (p > i)
        {
            cout << "S " << i + 1 << ' ' << p + 1 << endl;
            cin >> stat;
        }
        i++;
    }

    cout << "D" << endl;
    cin >> stat;
}

int main()
{
    ios::sync_with_stdio(0); cin.tie(0);

    int num_tests; cin >> num_tests >> N;
    rep(test, num_tests)
    {
        test_case(test);
    }
}
