#include <bits/stdc++.h>
using namespace std;

string headline, word;
int pos[27][10001];

int main() {
    cin >> headline >> word;
    for (int i = 0; i < 27; i++) {
        int next = headline.size();
        for (int j = headline.size() - 1; j >= 0; j--) {
            if (headline[j] == char(i + 'a')) {
                next = j;
            }
            pos[i][j] = next;
        }
    }
    int j = 0;
    int result = 1;
    for (int i = 0; i < word.size(); i++) {
        if (j == headline.size()) {
            result++;
            j = 0;
        }
        if (pos[word[i] - 'a'][j] == headline.size()){
            result++;
            j = pos[word[i] - 'a'][0] + 1;
            if (j == headline.size() + 1) {
                result = -1;
                break;
            }
        } else {
            j = pos[word[i] - 'a'][j] + 1;
        }
    }
    cout << result;
}