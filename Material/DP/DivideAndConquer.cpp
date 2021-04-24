
ll cost(int i, int j) { return ; }

vl last, now;

void compute(int l, int r, int optl, int optr)
{
    if (l > r) return;

    int mid = (l + r) / 2;
    pair<ll, int> best = {cost(0, mid), -1};

    repx(k, max(1, optl), min(mid, optr) + 1)
        best = min(best, {last[k - 1] + cost(k, mid), k});

    now[mid] = best.ff;

    compute(l, mid - 1, optl, best.ss);
    compute(mid + 1, r, best.ss, optr);
}
