#include <bits/stdc++.h>
using namespace std;

int nTests;
string card;
vector<string> cards;
vector<string> result(5);
char SUITS[4] = {'C', 'D', 'H', 'S'};
char VALUES[13] = {'A', '2', '3', '4', '5', '6', '7', '8', '9', '1', 'J', 'Q', 'K'};

pair<int, int> position(string c) {
    if (c.size() == 3) {
        c.erase(1, 1);
    }
    pair<int, int> r;
    for (int j = 0; j < 13; j++) {
        if (VALUES[j] == c[0]) {
            r.first = j;
            break;
        }
    }
    for (int i = 0; i < 4; i++) {
        if (SUITS[i] == c[1]) {
            r.second = i;
            break;
        }
    }
    return r;
}

bool checkOrder() {
    pair<int, int> firstPair = position(result[0]);
    pair<int, int> resultPair = position(result[1]);
    map<pair<int, int>, int> s;
    for (int i = 2; i < 5; i++) {
        s[position(result[i])] = i - 1;
    }
    int i = 1;
    vector<int> orders;
    for (auto it = s.begin(); it != s.end(); it++) {
        orders.push_back(it->second);
    }
    resultPair.first += orders[0];
    if (orders[1] > orders[2]) {
        resultPair.first += 3;
    }
    resultPair.first %= 13;
    return (resultPair.first == firstPair.first && resultPair.second == firstPair.second);
}

bool assist(int mask, int index) {
    if (index == 5) {
        return checkOrder();
    }
    for (int i = 0, b = 1; i < 5; i++, b <<= 1) {
        if (!(b & mask)) {
            result[index] = cards[i];
            if (assist(mask | b, index + 1)) {
                return true;
            }
        }
    }
    return false;
}

int main() {
    cin >> nTests;
    while (nTests--){
        for (int i = 0; i < 5; i++) {
            cin >> card;
            cards.push_back(card);
        }
        assist(0, 0);
        for (int i = 0; i < 5; i++) {
            cout << result[i] << ' ';
        };
        cout << '\n';
        cards = {};
    }
}