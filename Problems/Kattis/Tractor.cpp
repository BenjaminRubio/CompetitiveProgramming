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

int N, A, B;

int main()
{
    cin >> N;

    rep(_, N)
    {
        cin >> A >> B;

        int sum = 1 , t = 1, c = 1; 
        while (c <= A + B)
        {
            if (c <= A && c <= B) sum += t * 2; 
            else if (c > A && c <= B) sum += t * 2 - (c - A);
            else if (c <= A && c >= B) sum += t * 2 - (c - B);
            else sum += t * 2 - (c - B) - (c - A);
            t *= 2, c += t; 
        }
        
        cout << sum << '\n';
    }
}