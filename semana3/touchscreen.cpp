#include <bits/stdc++.h>
using namespace std;

int nTests;
string word;
string sugestedWord;
int nWords;
string keyboard[3] = {"qwertyuiop", "asdfghjkl", "zxcvbnm"};
map<int, set<string>> results;
pair<int, int> coord1;
pair<int, int> coord2;

pair<int, int> getCoords(char letter) {
    pair<int, int> coord;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < keyboard[i].size(); j++) {
            if (keyboard[i][j] == letter) {
                coord.first = i;
                coord.second = j;
                return coord;
            }
        }
    }
}

int main() {
    cin >> nTests;
    while (nTests--) {
        cin >> word >> nWords;
        while (nWords--) {
            cin >> sugestedWord;
            int distance {0};
            for (int i = 0; i < word.size(); i++) {
                coord1 = getCoords(word[i]);
                coord2 = getCoords(sugestedWord[i]);
                distance += abs(coord1.first - coord2.first) + abs(coord1.second - coord2.second);
            }
            set<string> s;
            results.emplace(distance, s);
            results[distance].insert(sugestedWord);
        }
        for (auto it1 = results.begin(); it1 != results.end(); it1++) {
            int n = (*it1).first;
            set<string> s = (*it1).second;
            for (auto it2 = s.begin(); it2 != s.end(); it2++) {
                cout << *it2 << ' ' << n << '\n';
            }
        }
        results = {};
    }
}