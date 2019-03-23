#include <bits/stdc++.h>
using namespace std;

int n;
vector<int> heights;
vector<int> coords(2);
long long int maxArea;

long long int getArea() {
    int i = coords[0];
    int j = coords[1];
    long long int result;
    result = *min_element(heights.begin() + i, heights.begin() + j + 1) * (j - i + 1);
    return result;
}

void calcMaxArea(int index) {
    if (index == 2) {
        long long int h = getArea();
        if (h > maxArea) {
            maxArea = h;
        }
        return;
    }
    for (int i = coords[0]; i < heights.size(); i++) {
        coords[index] = i;
        calcMaxArea(index + 1);
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
        calcMaxArea(0);
        cout << maxArea << '\n';
    }
}