#include <bits/stdc++.h>
using namespace std;

int A, B;

int cons_to_price(int c)
{
    int price = 0;
    if (c)
        price += min(100, c) * 2;
    c = max(0, c - 100);
    if (c)
        price += min(9900, c) * 3;
    c = max(0, c - 9900);
    if (c)
        price += min(990000, c) * 5;
    c = max(0, c - 990000);
    if (c)
        price += c * 7;
    return price;
}

int price_to_cons(int p)
{
    int cons = 0;
    if (p)
        cons += min(100, p / 2);
    p = max(0, p - 100 * 2);
    if (p)
        cons += min(9900, p / 3);
    p = max(0, p - 9900 * 3);
    if (p)
        cons += min(990000, p / 5);
    p = max(0, p - 990000 * 5);
    if (p)
        cons += p / 7;
    return cons;
}

int main()
{
    while (cin >> A >> B)
    {
        if (A == 0 && B == 0)
            break;

        int total_cons = price_to_cons(A);

        int l = 0;
        int r = total_cons;
        while (l < r)
        {
            int m = (l + r) / 2;
            int delta = cons_to_price(total_cons - m) - cons_to_price(m);
            if (delta <= B)
                r = m;
            else
                l = m + 1;
        }

        cout << min(cons_to_price(total_cons - l), cons_to_price(l)) << '\n';
    }
}