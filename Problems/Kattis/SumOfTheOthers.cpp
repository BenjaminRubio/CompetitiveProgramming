#include <bits/stdc++.h>
using namespace std;

string line;

int main()
{
    while (getline(cin, line))
    {
        stringstream ss;
        ss << line;

        int sum = 0, aux;
        while (ss >> aux) sum += aux;
        cout << sum / 2 << '\n';
    }
}