#include <bits/stdc++.h>
using namespace std;

int nTest {0};
string BASE = " 123456789abcdefghijklmnopqrstuvwxyz0";
string word1;
string word2;
string word3;
string equalSign;
char operation;
vector<string> words;
vector<int> numbers;
bool worked; 
bool printed = false;

int charToNumber(char ch) {
    int result = ch - '0';
    if (result > 9) {
        result -= 39;
    }
    return result;
}

int expressionToNumber(string word, int sum, int basePower, int base) {
    if (word.size() == 0) {
        worked = true;
        return sum;
    }
    int n = charToNumber(word[word.size() - 1]);
    if (base == 1) {
        if (n != 1) {
            worked = false;
            return 0;
        }
    } else if (n >= base) {
        worked = false;
        return 0;
    }
    return expressionToNumber(word.substr(0, word.size() - 1), sum + n * basePower, basePower * base, base);
}

void checkBases(int currentBase) {
    if (currentBase == 37) {
        if (!printed) {
            cout << "invalid";
        }
        cout << '\n';
        printed = false;
        return;
    }
    for (auto const &word : words) {
        numbers.push_back(expressionToNumber(word, 0, 1, currentBase));
        if (!worked) {
            numbers = {};
            break;
        }
    }
    if (worked) {
        if (operation == '+') {
            if ((numbers[0] + numbers[1]) == numbers[2]) {
                printed = true;
                cout << BASE[currentBase];
            }
        }
        if (operation == '*') {
            if ((numbers[0] * numbers[1]) == numbers[2]) {
                printed = true;
                cout << BASE[currentBase];
            }
        }
        if (operation == '-') {
            if ((numbers[0] - numbers[1]) == numbers[2]) {
                printed = true;
                cout << BASE[currentBase];
            }
        }
        if (operation == '/') {
            if (((numbers[0] / numbers[1]) == numbers[2]) && ((numbers[0] % numbers[1]) == 0)) {
                printed = true;
                cout << BASE[currentBase];
            }
        }
    }
    numbers = {};
    checkBases(currentBase + 1);
}

int main() {
    cin >> nTest;
    while (nTest--) {
        cin >> word1 >> operation >> word2 >> equalSign >> word3;
        words.push_back(word1);
        words.push_back(word2);
        words.push_back(word3);
        checkBases(1);
        words = {};
        numbers = {};
    }
}