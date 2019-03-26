#include <bits/stdc++.h>
using namespace std;

int N;
string instructions;
vector<string> grid;
pair<int, int> pos;
map<pair<int, int>, set<int>> path;
vector<pair<pair<int, int>, int>> memory;

void moveRobot(int move) {
    int dx {0};
    int dy {0};
    set<int> emptySet;
    path.emplace(pos, emptySet);
    if (path[pos].find(move) != path[pos].end()) {
        long int result {memory.end() - find(memory.begin(), memory.end(), make_pair(pos, move))};
        if (!result) {
            cout << 1;
        } else {
            cout << result;
        }
        return;
    }
    path[pos].insert(move);
    if (instructions[move] == '<') {
        dx--;
    }
    if (instructions[move] == '^') {
        dy--;
    }
    if (instructions[move] == '>') {
        dx++;
    }
    if (instructions[move] == 'v') {
        dy++;
    }
    if (grid[pos.first + dy][pos.second + dx] == '.') {
        memory.push_back(make_pair(pos, move));
        grid[pos.first][pos.second] = '.';
        grid[pos.first + dy][pos.second + dx] = 'R';
        pos.first += dy;
        pos.second += dx;
    }
    moveRobot((move + 1) % instructions.size());
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
                pos.first = i;
                pos.second = j;
            }
        }
    }
    moveRobot(0);
}