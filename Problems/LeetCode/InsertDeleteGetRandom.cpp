#include <bits/stdc++.h>
using namespace std;

class RandomizedSet
{
    unordered_map<int, bool> m;
public:
    RandomizedSet() {}

    bool insert(int val)
    {
        if (m[val]) return 0;
        else m[val] = 1;
        return 1;
    }

    bool remove(int val)
    {
        if (!m[val]) return 0;
        else m[val] = 0;
        return 1;
    }

    int getRandom()
    {
        auto it = m.begin();
        advance(it, rand() % m.size());
        while (!it->second)
        {
            it = m.begin();
            advance(it, rand() % m.size());
        }
        return it->first;
    }
};
