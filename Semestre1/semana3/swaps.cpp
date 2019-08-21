#include <bits/stdc++.h>
using namespace std;

int N;
vector<int> numbers;
vector<int> orderedNumbers;
int counter {0};

void countSwaps(bool swapped) {
    // cout << "[ ";
    // for (int i = 0; i < numbers.size(); i++) {
    //     cout << numbers[i] << ' ';
    // }
    // cout << "]\n";
    if (numbers == orderedNumbers) {
        if (!swapped) {
            return;
        }
        counter++;
        return;
    }
    for (int i = 0; i < numbers.size() - 1; i++) {
        if (numbers[i + 1] < numbers[i]) {
            int num = numbers[i];
            numbers[i] = numbers[i + 1];
            numbers[i + 1] = num;
            countSwaps(true);
            numbers[i + 1] = numbers[i];
            numbers[i] = num;
        }
    }
}

int main() {
    int j = 1;
    while (true) {
        cin >> N;
        if (!N) {
            break;
        }
        for (int i = 0; i < N; i++) {
            int num;
            cin >> num;
            numbers.push_back(num);
            orderedNumbers.push_back(num);
        }
        sort(orderedNumbers.begin(), orderedNumbers.end());
        countSwaps(false);
        cout << "There are " << counter << " swap maps for input data set " << j << ".\n";
        counter = 0;
        numbers.clear();
        orderedNumbers.clear();
        j++;
    }
}