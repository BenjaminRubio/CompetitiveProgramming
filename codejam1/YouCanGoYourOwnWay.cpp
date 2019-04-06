#include <bits/stdc++.h>
using namespace std;

int T, N;
string path1;

int main() {
    cin >> T;
    for (int i = 1; i <= T; i++) {
        string path2;
        cin >> N;
        cin >> path1;
        for (int j = 0; j < path1.size(); j++) {
            if (path1[j] == 'E') {
                path2 += 'S';
            } else {
                path2 += 'E';
            }
        }
        cout << "Case #" << i << ": " << path2 << '\n';
    }
}