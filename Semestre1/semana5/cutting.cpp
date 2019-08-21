#include <bits/stdc++.h>
using namespace std;

int N, K;
map<int, int> repetitions;

bool verify(int times) {
    int counter = 0;
    for (auto it = repetitions.begin(); it != repetitions.end(); it++) {
        counter += it->second / times;
        if (counter >= K) {
            return true;
        }
    }
    return false;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> N >> K;
    for (int i = 0; i < N; i++) {
        int num;
        cin >> num;
        repetitions.emplace(num, 0);
        repetitions[num] += 1;
    }
    int tmin = 1;
    int tmax = N / K;
    while (tmin < tmax) {
        int tmid = (tmin + tmax) / 2 + 1;
        if (verify(tmid)) {
            tmin = tmid;
        } else {
            tmax = tmid - 1;
        }
    }
    int counter = 0;
    for (auto it = repetitions.begin(); it != repetitions.end(); it++) {
        for (int i = 0; i < it->second / tmin; i++) {
            counter++;
            cout << it->first << ' ';
            if (counter == K) {
                return 0;
            }
        }
    }
}