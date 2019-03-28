#include <bits/stdc++.h>
using namespace std;

int N;
string instructions;
vector<string> grid;
pair<int, int> initPos;
vector<pair<pair<int, int>, int>> memory;

int getCycleSize(pair<int, int> pos, int move) {
    set<pair<pair<int, int>, char>> s;
    auto it = find(memory.begin(), memory.end(), make_pair(pos, move));
    int result = memory.end() - it;
    for (int i = 2; i < memory.end() - it; i++) {
        if ((memory.end() - it) % i == 0) {
            bool works = true;
            for (int j = 1; j < i; j++) {
                for (int k = 0; k < i; k++) {
                    if ((*(it + k)).first != (*(it + i * j + k)).first || 
                        instructions[(*(it + k)).second] != instructions[(*(it + i * j + k)).second]) {
                        works = false;
                    }
                }
            }
            if (works) {
                result = i;
            }
        }
    }
    return result;
}

void moveRobot(pair<int, int> pos, int move, int notMoving) {
    if (notMoving == instructions.size()) {
        cout << 1;
        return;
    }
    pair<int, int> newPos = pos;
    if (instructions[move] == '<') {
        newPos.second--;
    }
    if (instructions[move] == '^') {
        newPos.first--;
    }
    if (instructions[move] == '>') {
        newPos.second++;
    }
    if (instructions[move] == 'v') {
        newPos.first++;
    }
    if (grid[newPos.first][newPos.second] == '.') {
        if (find(memory.begin(), memory.end(), make_pair(pos, move)) != memory.end()) {
            long int result {getCycleSize(pos, move)};
            cout << result;
            return;
        }
        memory.push_back(make_pair(pos, move));
        grid[pos.first][pos.second] = '.';
        grid[newPos.first][newPos.second] = 'R';
        moveRobot(newPos, (move + 1) % instructions.size(), 0);
    } else {
        moveRobot(pos, (move + 1) % instructions.size(), notMoving + 1);
    }
}

int main() {
    cin >> N >> instructions;
    for (int i = 0; i < N; i++) {
        string line;
        cin >> line;
        grid.push_back(line);
    }
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (grid[i][j] == 'R') {
                initPos.first = i;
                initPos.second = j;
            }
        }
    }
    moveRobot(initPos, 0, 0);
}