#include <bits/stdc++.h>
using namespace std;

int T, N;
pair<int, int> dolls[20001];
vector<vector<pair<int, int>>> groups;

int minDolls(int index) {
    if (index == -1) {
        return 0;
    }
    pair<int, int> doll = dolls[index];
    bool added = false;
    int n = minDolls(index - 1);
    for (auto it = groups.begin(); it != groups.end(); it++) {
        pair<int, int> groupDoll = (*it)[(*it).size() - 1];
        if (doll.first > groupDoll.first && doll.second > groupDoll.second) {
            (*it).push_back(doll);
            added = true;
            break;
        }
    }
    if (!added) {
        groups.push_back({doll});
    }
    return n + !added;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> T;
    while (T--) {
        cin >> N;
        for (int i = 0; i < N; i++) {
            int w, h;
            cin >> w >> h;
            dolls[i] = {w, h};
        }
        sort(dolls, dolls + N);
        cout << minDolls(N - 1) << '\n';
        groups.clear();
    }
}