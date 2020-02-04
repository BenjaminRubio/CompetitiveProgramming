#include <bits/stdc++.h>
using namespace std;

#define rep(i, n) for (int i = 0; i < (int)n; i++)
#define repx(i, a, b) for (int i = (int)a; i < (int)b; i++)

int T, N, P;
string line, name, num;
vector<string> names, numbers;
vector<vector<vector<int>>> pos;
vector<int> curr;

bool check1(int p)
{
    int s = 0;
    int l = 0;
    rep(i, N)
    {
        if (curr[i] - l > 6) return false;
        s += stoi(numbers[p].substr(l, curr[i] - l));
        l = curr[i];
    }
    if (curr[N] - l > 6) return false;
    if (s == stoi(numbers[p].substr(l, curr[N] - l)))
        return true;
    return false;
}

void generate_pos(int p, int i, int n)
{
    if (n > N + 1) return;
    if (i == numbers[p].size())
    {
        if (n == N + 1 and check1(p)) pos[p].push_back(curr);
        return;
    }

    repx(j, i, max(i + 1, int(numbers[p][i] != '0') * (int)numbers[p].size()))
    {
        curr.push_back(j + 1);
        generate_pos(p, j + 1, n + 1);
        curr.pop_back();
    }
}

bool check2()
{
    vector<int> l(P + 1, 0);
    rep(i, N + 1)
    {
        int s = 0;
        rep(j, P)
        {
            s += stoi(numbers[j].substr(l[j], pos[j][curr[j]][i] - l[j]));
            l[j] = pos[j][curr[j]][i];
        }
        if (s != stoi(numbers[P].substr(l[P], pos[P][curr[P]][i] - l[P])))
            return false;
        l[P] = pos[P][curr[P]][i];
    }
    return true;
}

bool final(int p)
{
    if (p == P + 1)
    {
        if (check2())
        {
            rep(i, N) cout << 'P' << i + 1 << ' ';
            cout << "Totals\n";

            rep(i, P + 1)
            {
                cout << names[i] << ' ';
                int l = 0;
                rep(j, N)
                {
                    cout << numbers[i].substr(l, pos[i][curr[i]][j] - l) << ' ';
                    l = pos[i][curr[i]][j];
                }
                cout << numbers[i].substr(l, pos[i][curr[i]][N] - l) << '\n';
            }
            return true;
        }
        return false;
    }

    rep(i, pos[p].size())
    {
        curr.push_back(i);
        if (final(p + 1)) return true;
        curr.pop_back();
    }
    return false;
}

int main()
{
    cin >> T;
    while (T--)
    {
        names.clear();
        numbers.clear();

        cin >> line;
        N = ((int)line.size() - 6) / 2;

        while (true)
        {
            cin >> line;

            name = num = "";
            for (char c : line)
            {
                if (c < 'A') num += c;
                else name += c;
            }

            names.push_back(name);
            numbers.push_back(num);

            if (name == "TP") break;
        }

        P = names.size() - 1;

        pos.assign(P + 1, {});
        rep(i, P + 1) generate_pos(i, 0, 0);

        final(0);
        curr.clear();
    }
}