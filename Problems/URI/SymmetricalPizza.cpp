#include <bits/stdc++.h>
using namespace std;

int main()
{
    int a, b;
    scanf( "%d.%d", &a, &b);
    int R = 100 * a + b;
    cout << 36000 / __gcd(36000, R) << '\n';
}