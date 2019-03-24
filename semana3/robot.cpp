#include <bits/stdc++.h>
using namespace std;

int N;
string instructions;
vector<string> grid;
pair<int, int> pos;
set<pair<int, int>> path;

void moveRobot(int move, int notMoving, int cicling) {
    int dx {0};
    int dy {0};
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
    if (grid[pos.first + dx][pos.second + dy] == '.') {
        if (find(path.begin(), path.end(), make_pair(pos.first + dx, pos.second + dy)) != path.end()) {

        }
        grid[pos.first][pos.second] = '.';
        grid[pos.first + dx][pos.second + dy] = 'R';
        moveRobot((move + 1) % instructions.size(), 0);
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
                pos.first = i;
                pos.second = j;
            }
        }
    }
}