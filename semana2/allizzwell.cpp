#include <bits/stdc++.h>
using namespace std;

int nTest {0};
int nRows {0};
int nCols {0};
string line;
vector<string> matrix;
vector<int> masks;
string ALLIZZWELL = "ALLIZZWELL";

bool izzallwell(int index, int lastRow, int lastCol, bool first) {
    if (index == 10) {
        return true;
    }
    for (int i = 0; i < nRows; i++) {
        for (int j = 0; j < nCols; j++) {
            if (((max(abs(i - lastRow), abs(j - lastCol)) == 1) && ((masks[i] & (1 << j)) == 0)) || first) {
                if (matrix[i][j] == ALLIZZWELL[index]) {
                    masks[i] ^= (1 << j);
                    if (izzallwell(index + 1, i, j, false)) {
                        return true;
                    }
                    masks[i] ^= (1 << j);
                }
            }
        }
    }
    return false;
}

int main() {
    cin >> nTest;
    while (nTest--) {
        cin >> nRows >> nCols;
        for (int i = 0; i < nRows; i++) {
            cin >> line;
            matrix.push_back(line);
            masks.push_back(0);
        }
        if (izzallwell(0, 0, 0, true)) {
            cout << "YES\n";
        } else {
            cout << "NO\n";
        }
        matrix = {};
        masks = {};
    }
}