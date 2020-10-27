#include <bits/stdc++.h>
using namespace std;

int LIS(vector<int> &v)
{
	vector<int> L; int S = 0;
	for(int x : v)
    {
		int i = upper_bound(L.begin(), L.end(), x) - L.begin();
		if(i == S) L.push_back(x), S++;
		else L[i] = x;
	}
	return S;
}