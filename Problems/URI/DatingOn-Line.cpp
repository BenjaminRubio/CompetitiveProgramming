#include <bits/stdc++.h>
using namespace std;

#define rep(i, n) for (int i = 0; i < (int)n; i++)
typedef vector<int> vi;

const double PI = 3.14159265358979323846;
int n;
vi s;

double get_triang_area(int s1, int s2)
{
    double ang = 2.0 * PI / (double)n;
    double h = (double)s1 * sin(ang);
    return (double)s2 * h / 2.0;
}

int main()
{
    cout.setf(ios::fixed);
    cout.precision(3);

    cin >> n;

    s.resize(n);
    rep(i, n) cin >> s[i];
    sort(s.begin(), s.end());

    double area = 0;
    rep(i, n - 2)
        area += get_triang_area(s[i], s[i + 2]);
    area += get_triang_area(s[0], s[1]);
    area += get_triang_area(s[n - 2], s[n - 1]);

    cout << area << '\n';
}