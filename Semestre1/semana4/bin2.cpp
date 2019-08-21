#include <bits/stdc++.h>
using namespace std;

int N, Q;
vector<int> vec;

int binarySearch(int num) {
    vec.push_back(INT_MAX);
    int first = 0;
    int last = N;
    while (first < last) {
        int mid = first + (last - first) / 2;
        if (vec[mid] > num) {
            last = mid;
        } else {
            first = mid + 1;
        }
    }
    if (vec[first - 1] == num && first > 0) {
        return first - 1;
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