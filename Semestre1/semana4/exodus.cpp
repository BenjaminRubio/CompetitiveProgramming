#include <bits/stdc++.h>
using namespace std;

int N, K;
int roomsMask;

bool isPossible(int d) {
    //for (b = 1)
}

int binarySearch() {
    int first = 0;
    int last = K;
    while (first < last) {
        int mid = (first + last) / 2;
        if (isPossible(mid)) {
            last = mid;
        } else {
            first = mid + 1;
        }
    }
    return first;
}

int main() {
    cin >> N >> K;
    cin >> roomsMask;
    cout << binarySearch();
}