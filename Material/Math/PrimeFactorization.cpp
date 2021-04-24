
vi P;

vi factor(int x)
{
    vi ans;
    for (int d : P)
    {
        if (d * d > x) break;
        while (x % d == 0)
        {
            ans.pb(d);
            if ((x /= d) == 1) return ans;
        }
    }
    if (x > 1) ans.pb(x);
    return ans;
}