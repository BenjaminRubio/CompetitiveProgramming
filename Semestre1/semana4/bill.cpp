#include <bits/stdc++.h>
using namespace std;

int A, B;
vector<int> ranges = {100, 9900, 990000, INT_MAX};
vector<int> prices = {2, 3, 5, 7};

int billToConsume(int bill) {
    int consume {0};
    for (int i = 0; i < 4; i++) {
        if (bill < ranges[i] * prices[i]) {
            consume += (bill / prices[i]) % ranges[i];
            break;
        } else {
            consume += ranges[i];
            bill -= ranges[i] * prices[i];
        }
    }
    return consume;
}

int consumeToBill(int consume) {
    int bill {0};
    for (int i = 0; i < 4; i++) {
        if (consume < ranges[i]) {
            bill += consume * prices[i];
            break;
        } else {
            bill += ranges[i] * prices[i];
            consume -= ranges[i];
        }
    }
    return bill;
}

int binarySearch() {
    int first = 0;
    int last = A;
    while (first < last) {
        int mid = (first + last) / 2;
        int consume1 = billToConsume(mid);
        int consume2 = billToConsume(A) - consume1;
        if (consumeToBill(consume2) - consumeToBill(consume1) <= B) {
            last = mid;
        } else {
            first = mid + 1;
        }
    }
    return first;
}

int main() {
    while (true) {
        cin >> A >> B;
        if (A == 0) {
            break;
        }
        cout << binarySearch() << '\n';
    }
}