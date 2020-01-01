#include <bits/stdc++.h>
using namespace std;

int N;
string email_in, email;
set<string> s;

int main()
{
    cin >> N;

    while (N--)
    {
        cin >> email_in;

        email = "";
        bool plus = false;
        bool arroba = false;
        for (char c : email_in)
        {
            if (!plus && !arroba && c != '.' && c != '+' && c != '@')
                email += c;
            if (!plus && !arroba && c == '+')
                plus = true;
            if (c == '@')
                arroba = true;
            if (arroba)
                email += c;
        }

        s.insert(email);
    }

    cout << s.size() << '\n';
}