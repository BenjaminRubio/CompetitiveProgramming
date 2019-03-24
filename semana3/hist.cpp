#include <bits/stdc++.h>
using namespace std;

int n;
vector<int> heights;
long long int maxArea;

void calcMaxArea() {
    long long int area;
    for (int i = 0; i < heights.size(); i++) {
        int minH = heights[i];
        for (int j = i; j < heights.size(); j++) {
            if (heights[j] < minH) {
                minH = heights[j];
            }
            area = minH * (j - i + 1);
            if (area > maxArea) {
                maxArea = area;
            }
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
            int h;
            cin >> h;
            heights.push_back(h);
        }
        calcMaxArea();
        cout << maxArea << '\n';
    }
}