#include <bits/stdc++.h>
using namespace std;

int v;
string line, w, sign;
map<string, int> value;
map<int, string> inv_value;

int main()
{
    while (getline(cin, line))
    {
        stringstream ss(line);

        ss >> w;
        if (w == "def")
        {
            ss >> w >> v;
            if (value.count(w)) inv_value.erase(value[w]);
            value[w] = v, inv_value[v] = w;
        }
        else if (w == "calc")
        {
            int ans = 0, m = 1, unk = 0;

            while (true)
            {
                ss >> w >> sign;
                if (!value.count(w)) { unk = 1; break; }

                ans += m * value[w];
                if (sign == "+") m = 1;
                if (sign == "-") m = -1;
                if (sign == "=") break;
            }

            string answ;
            if (unk || !inv_value.count(ans)) answ = "unknown";
            else answ = inv_value[ans];

            cout << line.substr(5, line.size() - 5) << ' ' << answ << '\n';
        }
        else value.clear(), inv_value.clear();
    }
}