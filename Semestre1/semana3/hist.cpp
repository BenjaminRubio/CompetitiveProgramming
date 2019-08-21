#include <bits/stdc++.h>
using namespace std;

int n;
vector<long long int> hist;
vector<long long int> currentHeight;
long long int maxArea;

void calcMaxArea() {
    int i = 0;
    hist.push_back(0);
    while (i < hist.size()) {
        if(currentHeight.empty() || hist[i] > hist[currentHeight.back()])
        {
            currentHeight.push_back(i);
            i++;
        }
        else
        {
            long long int t = currentHeight.back();
            currentHeight.pop_back();
            if (maxArea < hist[t] * (currentHeight.empty() ? i : i - currentHeight.back() - 1))
                maxArea = hist[t] * (currentHeight.empty() ? i : i - currentHeight.back() - 1);
        }
    }
}

int main() {
    while (true) {
        cin >> n;
        if (!n) {
            break;
        }
        for (int i  = 0; i < n; i++) {
            long long int h;
            cin >> h;
            hist.push_back(h);
        }
        calcMaxArea();
        cout << maxArea << '\n';
        hist.clear();
        currentHeight.clear();
        maxArea = 0;
    }
}