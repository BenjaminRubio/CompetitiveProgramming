#include <bits/stdc++.h>
using namespace std;

#define rep(i, n) for (int i = 0; i < (int)n; i++)
#define repx(i, a, b) for (int i = (int)a; i < (int)b; i++)
#define invrep(i, b, a) for (int i = b; i >= a; i--)

typedef vector<int> vi;

struct SuffixArray
{
    int n;
    vector<int> counts, rank, rank_tmp, sa, sa_tmp;
    vector<int> lcp;
    inline int get_rank(int i) { return i < n ? rank[i] : 0; }
    void counting_sort(int maxv, int k)
    {
        counts.assign(maxv + 1, 0);
        rep(i, n) counts[get_rank(i + k)]++;
        repx(i, 1, maxv + 1) counts[i] += counts[i - 1];
        invrep(i, n - 1, 0) sa_tmp[--counts[get_rank(sa[i] + k)]] = sa[i];
        sa.swap(sa_tmp);
    }
    void compute_sa(vector<int> &s)
    {
        rep(i, n) sa[i] = i;
        sort(sa.begin(), sa.end(), [&s](int i, int j) { return s[i] < s[j]; });
        int r = rank[sa[0]] = 1;
        repx(i, 1, n) rank[sa[i]] = (s[sa[i]] != s[sa[i - 1]]) ? ++r : r;
        for (int h = 1; h < n and r < n; h <<= 1)
        {
            counting_sort(r, h);
            counting_sort(r, 0);
            r = rank_tmp[sa[0]] = 1;
            repx(i, 1, n)
            {
                if (rank[sa[i]] != rank[sa[i - 1]] or
                    get_rank(sa[i] + h) != get_rank(sa[i - 1] + h))
                    ++r;
                rank_tmp[sa[i]] = r;
            }
            rank.swap(rank_tmp);
        }
    }
    void compute_lcp(vector<int> &s)
    {
        lcp.assign(n, 0);
        int k = 0;
        rep(i, n)
        {
            int r = rank[i] - 1;
            if (r == n - 1)
            {
                k = 0;
                continue;
            }
            int j = sa[r + 1];
            while (i + k < n and j + k < n and s[i + k] == s[j + k])
                k++;
            lcp[r] = k;
            if (k)
                k--;
        }
    }
    SuffixArray(vector<int> &s)
    {
        n = s.size();
        rank.resize(n);
        rank_tmp.resize(n);
        sa.resize(n);
        sa_tmp.resize(n);
        compute_sa(s);
        compute_lcp(s);
    }
};

string line;
vi s;

int main()
{
    while (getline(cin, line))
    {
        if (line == "")
            break;

        s.clear();

        for (char c : line)
        {
            if (c != ' ')
                s.push_back(c);
        }

        SuffixArray sa(s);

        int size = 1;
        while (true)
        {
            int maxim = -1;
            int count = 0;
            for (int i : sa.lcp)
            {
                if (i >= size)
                    count++;
                else if (i < size)
                    count = 0;
                maxim = max(maxim, count + 1);
            }

            if (maxim <= 1)
                break;

            cout << maxim << '\n';

            size++;
        }
        cout << '\n';
    }
}