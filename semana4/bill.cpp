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

bool isPossible() {
    
}

int binarySearch() {
    int first = 0;
    int last = A;
    while (first < last) {
        int mid = first + (last - first) / 2;
        //if 
    }   
}

int main() {
    while (true) {
        cout << consumeToBill(10123) << '\n';
        cout << billToConsume(consumeToBill(10123)) << '\n';
        cin >> A >> B;
        if (A == 0) {
            break;
        }
        cout << binarySearch() << '\n';
    }
}