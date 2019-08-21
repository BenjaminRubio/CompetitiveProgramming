#include <bits/stdc++.h>
using namespace std;

string line;
vector<vector<int>> braces;
stack<int> posibleBracePair;
int nBraces {0};
vector<string> answers;
map<string, bool> printed;

void getBracesPositions() {
    for(int i = 0; i < line.size(); i++) {
        if(line[i] == '(') {
            posibleBracePair.push(i);
        }
        if(line[i] == ')') {
            vector<int> newVector;
            newVector.push_back(posibleBracePair.top());
            posibleBracePair.pop();
            newVector.push_back(i);
            braces.push_back(newVector);
            nBraces += 1;
        }
    }
}

void printCombinations(int mask) {
    if (mask == (1 << nBraces)) {
        return;
    }
    string newLine = "";
    set<int> toErase;
    for (int i = 0, b = (1 << (nBraces - 1)); b > 0; i++, b >>= 1) {
        if (b & mask) {
            toErase.insert(braces[i][0]);
            toErase.insert(braces[i][1]);
        }
    }
    //https://stackoverflow.com/questions/12863256/how-to-iterate-stdset
    set<int>::iterator erasing = toErase.begin();
    for (int i = 0; i < line.size(); i++) {
        if (i != *erasing) {
            newLine += line[i];
        } else {
            erasing++;
        }
    }
    printed.emplace(newLine, false);
    if (!printed[newLine]) {
        answers.push_back(newLine);
        printed[newLine] = true;
    }
    printCombinations(mask + 1);
}

int main() {
    cin >> line;
    getBracesPositions();
    printCombinations(1);
    sort(answers.begin(), answers.end());
    for (auto &ans : answers) {
        cout << ans <<'\n';
    }
}