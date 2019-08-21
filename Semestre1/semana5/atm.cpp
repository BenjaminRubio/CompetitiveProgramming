#include <bits/stdc++.h>
using namespace std;

int n, k, q;
vector<int> bills;

int possible(int nmid, int amount) {
    for (auto it1 = bills.begin(); it1 != bills.end(); it1++) {
        int rest = amount;
        for (int j = 1; j <= min(nmid, amount / *it1); j++) {
            rest -= *it1;
            for (auto it2 = it1; it2 != bills.end(); it2++) {
                if (!(rest % *it2) && rest / *it2 <= nmid - j) {
                    return rest / *it2 + j;
                }
            }
        }
    }
    return 0;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> k;
    for (int i = 0; i < n; i++) {
        int bill;
        cin >> bill;
        bills.push_back(bill);
    }
    cin >> q;
    for (int i = 0; i < q; i++) {
        int amount;
        cin >> amount;
        int nmin = 1;
        int nmax = k + 1;
        while (nmin < nmax) {
            int nmid = (nmin + nmax) / 2;
            int pos = possible(nmid, amount);
            if (pos) {
                nmax = pos;
            } else {
                nmin = nmid + 1;
            }
        }
        if (nmax < k + 1) {
            cout << nmax << '\n';
        } else {
            cout << -1 << '\n';
        }
    }
}