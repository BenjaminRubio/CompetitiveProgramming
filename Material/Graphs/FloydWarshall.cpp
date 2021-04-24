
const int INF = 1e9;

int n;
vector<vi> D;

//D is an adjacency matrix at the beginning
void floydWarshall ()
{
    rep(k, n) rep(i, n) rep(j, n) if (D[i][k] < INF && D[k][j] < INF)
        D[i][j] = min(D[i][j], D[i][k] + D[k][j]);

    // opcional, si hay ciclos negativos
    rep(k, n) rep(i, n) rep(j, n)
        if (D[i][k] < INF && D[k][j] < INF && D[k][k] < 0) D[i][j] = -INF;
}
