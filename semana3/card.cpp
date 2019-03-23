#include <bits/stdc++.h>
using namespace std;

int nTests;
string card;
vector<string> cards;
vector<string> result(5);
char SUITS[4] = {'C', 'D', 'H', 'S'};
char VALUES[13] = {'A', '2', '3', '4', '5', '6', '7', '8', '9', '1', 'J', 'Q', 'K'};

pair<int, int> position(string c) {
    if (c.size() == 10) {
        c = c[0] + c[2];
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
    set<pair<int, int>> s;
    for (int i = 2; i < 5; i++) {
        s.insert(position(result[i]));
    }
    int i = 1;
    bool first = true;
    vector<int> orders;
    for (auto it = s.begin(); it != s.end(); it++) {
        for (int j = 2; j < 5; j++) {
            if (position(result[j]).first == it->first && position(result[j]).second == it->second) {
                if (first) {
                    resultPair.second += j - 1;
                    first = false;
                    break;
                } else {
                    orders.push_back(i);
                    break;
                }
            }
        }
        i++;
    }
    if (orders[0] > orders[1]) {
        resultPair.second += 3;
    }
    resultPair.second %= 13;
    return (resultPair == firstPair);
}

bool assist(int mask, int index) {
    if (index == 5) {
        return checkOrder();
    }
    for (int i = 0, b = 1; i < 5; i++, b <<= 1) {
        if (!(b & mask)) {
            result[i] = cards[i];
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