#include <bits/stdc++.h>
using namespace std;

int n, k;
vector<int> difficulties;

int main() {
    cin >> n >> k;
    for (int i = 0; i < n; i++) {
        int num;
        cin >> num;
        difficulties.push_back(num);
    }
    sort(difficulties.begin(), difficulties.end());
    int count = 0;
    int i = 0;
    while (i < n) {
        if (difficulties[i] > 2 * k) {
            count++;
            k *= 2;
        } else {
            if (difficulties[i] > k) {
                k = difficulties[i];
            }
            i++;
        }
    }
    cout << count;
}