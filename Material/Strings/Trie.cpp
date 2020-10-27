#include <bits/stdc++.h>
using namespace std;

#define rep(i, n) for (int i = 0; i < (int)n; i++)

struct Trie
{
	int N[(int)1e6][26] = {0}, S[(int)1e6] = {0}, c = 0;
	Trie() {}
	void add(string x, int a)
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