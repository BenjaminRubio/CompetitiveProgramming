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

int T, N, M;
vector<char> A;

int main()
{
    ios::sync_with_stdio(0); cin.tie(0);

    cin >> T;
    while (T--)
    {
        cin >> N >> M;

        A.resize(N);
        rep(i, N) cin >> A[i];

        bool flag = 1; int it = 0;
        while (flag && it < M)
        {
            vector<char> B = A;
            flag = 0;
            rep(i, N) if (A[i] == '0')
            {
                int cnt = 0;
                if (i && A[i - 1] == '1') cnt++;
                if (i < N - 1 && A[i + 1] == '1') cnt++;
                if (cnt == 1) B[i] = '1', flag = 1;
            }

            swap(A, B); it++;
        }

        rep(i, N) cout << A[i];
        cout << '\n';
    }
}
