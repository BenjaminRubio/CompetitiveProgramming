#include <bits/stdc++.h>
using namespace std;

int T, N, L, first, second;
vector<int> products;
vector<int> producted;
set<int> primes;
string letters = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
string result;

bool tryOrder() {
    int j = 1;
    while (j < L) {
        if (products[j] % producted[j]) {
            return false;
        }
        producted.push_back(products[j] / producted[j]);
        primes.insert(producted[j + 1]);
        j++;
    }
    return true;
}

int main() {
    cin >> T;
    for (int i = 1; i <= T; i++) {
        cin >> N >> L;
        for (int j = 0; j < L; j++) {
            int prod;
            cin >> prod;
            products.push_back(prod);
        }
        for (int j = 2; j < N + 1; j++) {
            if (products[0] % j == 0) {
                first = j;
                second = products[0] / j;
                producted.push_back(first);
                producted.push_back(second);
                primes.insert(first);
                primes.insert(second);
                break;
            }
        }
        if (!tryOrder()) {
            producted.clear();
            primes.clear();
            producted.push_back(second);
            producted.push_back(first);
            primes.insert(first);
            primes.insert(second);
            tryOrder();
        }
        vector<int> orderedPrimes(primes.size());
        copy(primes.begin(), primes.end(), orderedPrimes.begin());
        for (int j = 0; j <= L; j++) {
            result += letters[find(orderedPrimes.begin(), orderedPrimes.end(), 
                                   producted[j]) - orderedPrimes.begin()];
        }
        cout << "Case #" << i << ": " << result << '\n';
        producted.clear();
        products.clear();
        primes.clear();
        result.clear();
    }
}