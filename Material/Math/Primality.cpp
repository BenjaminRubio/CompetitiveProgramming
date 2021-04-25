#include <Modular.cpp>

bool prime(ul n)
{
    if (n < 2 || n % 6 % 4 != 1) return n - 2 < 2;
    ul A[] = {2, 325, 9375, 28178, 450775, 9780504, 1795265022};
    ul s = __builtin_ctzll(n - 1), d = n >> s;
    for (int a : A)
    {
        ul p = modPow(a, d, n), i = s;
        while (p != 1 && p != n - 1 && a % n && i--) p = modMul(p, p, n);
        if (p != n - 1 && i != s) return 0;
    }
    return 1;
}
