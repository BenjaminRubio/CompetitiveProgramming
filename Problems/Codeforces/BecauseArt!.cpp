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

#define PI acos(-1.0L)

typedef complex<double> C;
void fft(vector<C> &a)
{
    int n = a.size(), L = 31 - __builtin_clz(n);
    static vector<complex<long double>> R(2, 1);
    static vector<C> rt(2, 1);
    for (static int k = 2; k < n; k *= 2)
    {
        R.resize(n); rt.resize(n);
        auto x = polar(1.0L, PI / k);
        repx(i, k, 2 * k) rt[i] = R[i] = i & 1 ? R[i / 2] * x : R[i / 2];
    }
    vi rev(n);
    rep(i, n) rev[i] = (rev[i / 2] | (i & 1) << L) / 2;
    rep(i, n) if (i < rev[i]) swap(a[i], a[rev[i]]);
    for (int k = 1; k < n; k *= 2) for (int i = 0; i < n; i += 2 * k) rep(j, k)
    {
        auto x = (double *)&rt[j + k], y = (double *)&a[i + j + k];
        C z(x[0] * y[0] - x[1] * y[1], x[0] * y[1] + x[1] * y[0]);
        a[i + j + k] = a[i + j] - z, a[i + j] += z;
    }
}

vl convInt(const vl &a, const vl &b)
{
    if (a.empty() || b.empty()) return {};
    vl res(a.size() + b.size() - 1);
    int B = 32 - __builtin_clz(res.size()), n = 1 << B;
    vector<C> L(n), R(n), outs(n), outl(n);
    rep(i, a.size()) L[i] = C(0ll, a[i]);
    rep(i, b.size()) R[i] = C(0ll, b[i]);
    fft(L), fft(R);
    rep(i, n)
    {
        int j = -i & (n - 1);
        outl[j] = (L[i] + conj(L[j])) * R[i] / (2.0 * n);
        outs[j] = (L[i] - conj(L[j])) * R[i] / (2.0 * n) / 1i;
    }
    fft(outl), fft(outs);
    rep(i, res.size())
    {
        ll av = ll(real(outl[i]) + .5), cv = ll(imag(outs[i]) + .5);
        ll bv = ll(imag(outl[i]) + .5) + ll(real(outs[i]) + .5);
        res[i] = av + bv + cv;
    }
    return res;
}

int N;
vl A, B;

int main()
{
    ios::sync_with_stdio(0); cin.tie(0);

    cin >> N;

    A.resize(N), B.resize(N);
    rep(i, N) cin >> A[i];
    rep(i, N) cin >> B[i];

    sort(A.begin(), A.end());
    sort(B.begin(), B.end());

    vl ans1(N), ans2(N);

    int p = 0, l1 = 0, l2 = 0, r1 = N - 1, r2 = N - 1;
    while (l1 <= r1 && (A[l1] <= 0 && B[l2] <= 0 || A[r1] >= 0 && B[r2] >= 0))
    {
        if (A[l1] * B[l2] >= A[r1] * B[r2]) 
            ans1[p] = (p ? ans1[p - 1] : 0ll) + A[l1++] * B[l2++];
        else
            ans1[p] = (p ? ans1[p - 1] : 0ll) + A[r1--] * B[r2--];
        p++;
    }

    int s = 0;
    vl a, b;
    repx(i, l1, r1 + 1)
    {
        a.pb((A[i] >= 0 ? A[i] : -A[i]));
        if (A[i] < 0) s = -1;
        if (A[i] > 0) s = 1;
    }
    repx(i, l2, r2 + 1)
    {
        b.pb((B[i] >= 0 ? B[i] : -B[i]));
        if (B[i] < 0) s = 1;
        if (B[i] > 0) s = -1;
    }

    reverse(b.begin(), b.end());
    vl c = convInt(a, b);

    if (s == 1) repx(i, p, N) ans1[i] = (p ? ans1[p - 1] : 0ll) - c[(i - p)];
    else repx(i, p, N) ans1[i] = (p ? ans1[p - 1] : 0ll) - c[c.size() - 1 - (i - p)];

    p = 0, l1 = 0, l2 = 0, r1 = N - 1, r2 = N - 1;
    while (l1 <= r1 && (A[l1] <= 0 && B[r2] >= 0 || A[r1] >= 0 && B[l2] <= 0))
    {
        if (A[l1] * B[r2] <= A[r1] * B[l2]) 
            ans2[p] = (p ? ans2[p - 1] : 0ll) + A[l1++] * B[r2--];
        else
            ans2[p] = (p ? ans2[p - 1] : 0ll) + A[r1--] * B[l2++];
        p++;
    }

    s = 0;
    a.clear(), b.clear();
    repx(i, l1, r1 + 1)
    {
        a.pb((A[i] >= 0 ? A[i] : -A[i]));
        if (A[i] < 0) s = -1;
        if (A[i] > 0) s = 1;
    }
    repx(i, l2, r2 + 1)
    {
        b.pb((B[i] >= 0 ? B[i] : -B[i]));
        if (B[i] < 0) s = -1;
        if (B[i] > 0) s = 1;
    }

    c = convInt(a, b);

    if (s == 1) repx(i, p, N) ans2[i] = (p ? ans2[p - 1] : 0ll) + c[(i - p)];
    else repx(i, p, N) ans2[i] = (p ? ans2[p - 1] : 0ll) + c[c.size() - 1 - (i - p)];

    rep(i, N) cout << ans2[i] << ' ' << ans1[i] << '\n';
}
