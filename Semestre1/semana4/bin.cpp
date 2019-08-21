#include <bits/stdc++.h>
using namespace std;

int N, Q;
vector<int> vec;

int binarySearch(int num) {
    int first = 0;
    int last = N - 1;
    while (first < last) {
        int mid = first + (last - first) / 2;
        if (vec[mid] >= num) {
            last = mid;
        } else {
            first = mid + 1;
        }
    }
    if (vec[first] == num) {
        return first;
    } else {
        return -1;
    }   
}

int main() {
    cin >> N >> Q;
    for (int i = 0; i < N; i++) {
        int num;
        cin >> num;
        vec.push_back(num);
    }
    for (int i = 0; i < Q; i++) {
        int num;
        cin >> num;
        cout << binarySearch(num) << '\n';
    }
}