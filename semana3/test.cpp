#include <bits/stdc++.h>
using namespace std;

int n, k;
int score;
int fifthScore {0};
int nextRound {0};

int main() {
    cin >> n >> k;
    for (int i = 0; i < n; i++) {
        cin >> score;
        if (i == k - 1) {
            fifthScore = score;
        }
        if (score >= fifthScore and score) {
            nextRound++;
        }
    }
    cout << nextRound;
}