#include <bits/stdc++.h>
using namespace std;

#define rep(i, n) for (int i = 0; i < (int)n; i++)
#define ff first
#define ss second

struct Persona
{
    int id, s, h;
    Persona(int id_, int s_, int h_)
    {
        id = id_;
        s = s_;
        h = h_;
    }
    bool operator<(const Persona &p) const
    {
        return s < p.s;
    }
};

int T, N, Q, id, s, h;

int main()
{
    cin >> T;
    while (T--)
    {
        cin >> N >> Q;

        vector<Persona> data;
        rep(i, N)
        {
            cin >> id >> s >> h;
            data.emplace_back(id, s, h);
        }

        sort(data.begin(), data.end());

        map<int, int> boss, count;
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> q;
        for (Persona p : data)
        {
            h = p.h, id = p.id;

            while (!q.empty() && q.top().ff <= h)
            {
                boss[q.top().ss] = id;
                count[id] += count[q.top().ss] + 1;
                q.pop();
            }

            q.emplace(h, id);
        }

        rep(_, Q)
        {
            cin >> id;
            cout << boss[id] << ' ' << count[id] << '\n';
        }
    }
}