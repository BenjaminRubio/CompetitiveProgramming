#include <bits/stdc++.h>
using namespace std;

#define rep(i, n) for (int i = 0; i < (int)n; i++)

struct Trie
{
    int N[10000000][26] = {0}, S[10000000] = {0}, c = 0;
    Trie() {}
    void add(string x, int a = 1)
    {
        int p = 0; S[p] += a;
        for (char l : x)
        {
            int t = l - 'a';
            if (!N[p][t]) N[p][t] = ++c;
            S[p = N[p][t]] += a;
        }
    }
};

struct TrieXOR
{
    int N[10000000][2] = {0}, S[10000000] = {0}, c = 0;
    TrieXOR() {}
    void add(int x, int a = 1)
    {
        int p = 0; S[p] += a;
        rep(i, 31)
        {
            int t = (x >> (30 - i)) & 1;
            if (!N[p][t]) N[p][t] = ++c;
            S[p = N[p][t]] += a;
        }
    }
    int get(int x)
    {
        if (!S[0]) return -1;
        int p = 0; rep(i, 31)
        {
            int t = ((x >> (30 - i)) & 1) ^ 1;
            if (!N[p][t] || !S[N[p][t]]) t ^= 1;
            p = N[p][t]; if (t) x ^= (1 << (30 - i));
        }
        return x;
    }
};
