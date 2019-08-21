#include <bits/stdc++.h>
using namespace std;

int N, M;
int sum {0};
vector<int> vessels;
vector<int> containers;

bool isPossible(int maxCapacity) {
    int i = 0;
    int j = 0;
    while (i < M && j < N) {
        int newCap = containers[i] + vessels[j];
        if (newCap > maxCapacity) {
            i++;
        } else {
            containers[i] = newCap;
            j++;
        }
    }
    for (int i = 0; i < M; i++) {
            containers[i] = 0;
        }
    if (i == M && j < N) {
        return false;
    }
    return true;
}

int binarySearch() {
    int first = 0;
    int last = sum;
    while (first < last) {
        int mid = first + (last - first) / 2;
        if (isPossible(mid)) {
            last = mid;
        } else {
            first = mid + 1;
        }
    }
    if (isPossible(first)) {
        return first;
    } else {
        return -1;
    }   
}

int main() {
    while (cin >> N) {
        cin >> M;
        for (int i = 0; i < N; i++) {
            int num;
            cin >> num;
            sum += num;
            vessels.push_back(num);
        }
        for (int i = 0; i < M; i++) {
            containers.push_back(0);
        }
        cout << binarySearch() << '\n';
        vessels.clear();
        containers.clear();
    }
}