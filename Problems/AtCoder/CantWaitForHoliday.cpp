#include <bits/stdc++.h>
using namespace std;

string day;
map<string, int> mapping = {{"MON", 6}, {"TUE", 5}, {"WED", 4}, {"THU", 3}, {"FRI", 2}, {"SAT", 1}, {"SUN", 7}};

int main()
{
    cin >> day;
    cout << mapping[day] << '\n';
}