#include <bits/stdc++.h>
using namespace std;

int T, nRow, nCol;
string line;
vector<string> lines;
vector<vector<int>> matrix;

int toInt(string numString) {
    int size = numString.size();
    int num {0};
    int p = 1;
    for (int i = 1; i <= size; i++) {
        num += (numString[size - i] - '0') * p;
        p *= 10;
    }
    return num;
}

void decode(int index) {

}

int main() {
    nRow = 0;
    cin >> T;
    while (T--) {
        cin >> line;
        nCol = (line.size() - 6) / 2;
    }
    while (true) {
        nRow++;
        cin >> line;
        lines.push_back(line);
        if (line[0] == 'T' and line[1] == 'P') {
            break;
        }
    }
    //
}