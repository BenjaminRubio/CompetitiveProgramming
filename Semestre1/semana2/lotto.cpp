#include <bits/stdc++.h>
using namespace std;

int k;
int numbers[13] {0};
int permutation[6] {0};

void printPermutation() {
    for (int i = 0; i < 5; i++) {
        cout << permutation[i] << ' ';
    }
    cout << permutation[5] << '\n';
}

void permuteLotto(int mask, int len, int last) {

    if (len == 6) {
        printPermutation();
        return;
    }

    for (int i = 0, b = 1; i < k; i++, b <<= 1)
    {
        int number = numbers[i];
        if ((mask & b) == 0 & last < number) {
            permutation[len] = numbers[i];
            permuteLotto(mask | b, len + 1, number);
        }
    }
}

int main() {

    // for input/output
    ios::sync_with_stdio(false);
    cin.tie(0);
    //-----------------

    bool first = true;

    while(true){

        cin >> k;

        if (k == 0) {
            break;
        }

        if (!first) {
            cout << '\n';
        }
        first = false;

        for (int i = 0; i < k; i++) {
            cin >> numbers[i];
        }

        permuteLotto(0, 0, -1);
    }
}