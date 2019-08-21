#include <bits/stdc++.h>
using namespace std;

int k {0};
int n {0};
int number {0};
map<int, int> numbersMap;
vector<int> numbersVector;
int result[12][2] {0};
bool printed = false;

void printSums(int sum, int len, int index) {
    if (sum == k) {
        printed = true;
        for (int i = 0; i < len - 1; i++) {
            for (int j = 0; j < result[i][1]; j++) {
                cout << result[i][0] << '+';
            }
        }
        for (int j = 0; j < result[len - 1][1] - 1; j++) {
            cout << result[len - 1][0] << '+';
        }
        cout << result[len - 1][0] << '\n';
        return;
    } else if (index == numbersVector.size()) {
        return;
    } else if (sum > k) {
        return;
    }
    for (int j = numbersMap[numbersVector[index]]; j > 0; j--) {
        result[len][0] = numbersVector[index];
        result[len][1] = j;
        printSums(sum + j * numbersVector[index], len + 1, index + 1);
    }
    printSums(sum, len, index + 1);
}

int main() {
    while (true) {
        cin >> k;
        cin >> n;
        if (n == 0) {
            break;
        }
        for (int i = 0; i < n; i++) {
            cin >> number;
            numbersMap.emplace(number, 0);
            numbersMap[number] += 1;
            if (numbersMap[number] == 1) {
                numbersVector.push_back(number);
            }
        }
        cout << "Sums of " << k << ":\n";
        printSums(0, 0, 0);
        if (!printed) {
            cout << "NONE\n";
        }
        numbersMap = {};
        numbersVector = {};
        printed = false;
    }
}