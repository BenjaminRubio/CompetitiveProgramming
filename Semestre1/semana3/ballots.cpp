#include <bits/stdc++.h>
using namespace std;

int N, B;
vector<int> population;
int highPop {0};

bool isPossible(int m) {
    int ballots {0};
    for (int i = 0; i < population.size(); i++) {
        ballots += (population[i] / m);
        if (population[i] % m) {
            ballots += 1;
        }
    }
    if (ballots > B) {
        return false;
    }
    return true;
}

int distribute() {
    int low = 0;
    int high = highPop;
    int midPoint;
    while(low < high) {
        midPoint = low + (high - low) / 2;
        if (isPossible(midPoint)) {
            high = midPoint;
        } else {
            low = midPoint + 1;
        }
    }
    return low;
}

int main() {
    while (true) {
        cin >> N >> B;
        if (N == -1) {
            break;
        }
        for (int i = 0; i < N; i++) {
            int pop;
            cin >> pop;
            population.push_back(pop);
            if (pop > highPop) {
                highPop = pop;
            }
        }
        cout << distribute() << '\n';
        population = {};
    }
}