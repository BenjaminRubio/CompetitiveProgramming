#include <bits/stdc++.h>
using namespace std;

int T, N;

int main()
{
    cin >> T;
    while (T--)
    {
        cin >> N;
        for (int i = 0; i < N; i++)
        {
            for (int j = 0; j < i; j++) cout << '(';
            for (int j = 0; j < (N - i); j++) cout << "()";
            for (int j = 0; j < i; j++) cout << ')';
            cout << '\n';
        }
    }
}