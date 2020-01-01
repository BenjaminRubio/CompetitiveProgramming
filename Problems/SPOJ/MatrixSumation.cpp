#include <bits/stdc++.h>
using namespace std;

template <class T>
class FenwickTree2D
{
    vector<vector<T>> t;
    int n, m;

public:
    FenwickTree2D() {}

    FenwickTree2D(int n, int m)
    {
        t.assign(n, vector<T>(m, 0));
        this->n = n;
        this->m = m;
    }

    void add(int r, int c, T value)
    {
        for (int i = r; i < n; i |= i + 1)
            for (int j = c; j < m; j |= j + 1)
                t[i][j] += value;
    }

    T sum(int r, int c)
    {
        T res = 0;
        for (int i = r; i >= 0; i = (i & (i + 1)) - 1)
            for (int j = c; j >= 0; j = (j & (j + 1)) - 1)
                res += t[i][j];
        return res;
    }

    T sum(int r1, int c1, int r2, int c2)
    {
        return sum(r2, c2) - sum(r1 - 1, c2) - sum(r2, c1 - 1) + sum(r1 - 1, c1 - 1);
    }

    T get(int r, int c)
    {
        return sum(r, c, r, c);
    }

    void set(int r, int c, T value)
    {
        add(r, c, -get(r, c) + value);
    }
};

int T, N, r1, r2, c1, c2, x;
string action;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> T;
    while (T--)
    {
        cin >> N;
        FenwickTree2D<int> ft(N, N);

        while (true)
        {
            cin >> action;

            if (action == "SET")
            {
                cin >> r1 >> c1 >> x;
                ft.set(r1, c1, x);
            }
            if (action == "SUM")
            {
                cin >> r1 >> c1 >> r2 >> c2;
                cout << ft.sum(r1, c1, r2, c2) << '\n';
            }
            if (action == "END")
                break;
        }
    }
}