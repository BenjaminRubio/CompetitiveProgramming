#include <bits/stdc++.h>
using namespace std;

#define rep(i, n) for (int i = 0; i < (int)n; i++)

int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};

int N, M;
vector<string> G;
vector<vector<bool>> V;
string line;

void dfs(int x, int y, map<char, set<char>> &S)
{
    V[x][y] = 1;
    rep(k, 4)
    {
        int x_ = x + dx[k], y_ = y + dy[k];
        if (x_ >= 0 && x_ < N && y_ >= 0 && y_ < M && !V[x_][y_] && S[G[x][y]].count(G[x_][y_])) dfs(x_, y_, S);
    }
}

int main()
{
    int tt = 0;
    while (getline(cin, line))
    {
        G.clear();
        G.push_back(line);

        M = line.size();
        while (getline(cin, line))
        {
            if (line == "") break;
            G.push_back(line);
        }
        N = G.size();

        int I = 0, B = 0, b = 0; map<char, set<char>> S;
        V.assign(N, vector<bool>(M, 0)); S = {{'X', {'#', 'X'}}, {'#', {'#', 'X'}}};
        rep(i, N) rep(j, M) if (!V[i][j] && S.count(G[i][j])) { dfs(i, j, S); I++; }
        V.assign(N, vector<bool>(M, 0)); S = {{'B', {'B'}}};
        rep(i, N) rep(j, M) if (!V[i][j] && S.count(G[i][j])) { dfs(i, j, S); B++; }
        V.assign(N, vector<bool>(M, 0)); S ={{'X', {'#', 'X', 'B'}}, {'#', {'#', 'X'}}, {'B', {'B', 'X'}}};
        rep(i, N) rep(j, M) if (!V[i][j] && S.count(G[i][j])) { dfs(i, j, S); b++; }

        cout << "Map " << ++tt << '\n';
        cout << "islands: " << I << '\n';
        cout << "bridges: " << B << '\n';
        cout << "buses needed: " << b << '\n';
        cout << '\n';
    }
}