#include <bits/stdc++.h>
using namespace std;

int n;
string num;
int sum;
int par;
int zeros;

int main()
{
    cin >> n;

    while (n--)
    {
        cin >> num;

        sum = 0;
        zeros = 0;
        par = 0;
        for (char c : num)
        {
            sum += c - '0';
            if (c == '0')
                zeros++;
            else if ((c - '0') % 2 == 0)
                par++;
        }
        if (zeros > 1)
            par++;

        if (zeros && par && sum % 3 == 0)
            cout << "red\n";
        else
            cout << "cyan\n";
    }
}