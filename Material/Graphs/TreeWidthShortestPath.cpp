#include "../Template.cpp"

int N;
vvi B, T;
vvp G;

const int MAXN = 50010;
const int MAXL = 16; // Fijarse en valor
const int MAXK = 3; // (treewidth) + 1
const ll INF = 1e18;

struct TWSP
{
	ll UP[MAXL][MAXK][MAXN], DW[MAXL][MAXK][MAXN];
	ll I[MAXN][MAXK][MAXK], X[MAXN][MAXK][MAXK][2];
	int D[MAXN], P[MAXN], V[MAXN], S[MAXN], M[MAXN];
    int B_[MAXN], R[MAXN][MAXK], C[MAXL][MAXN], PT[MAXN];
    vi ord;

    TWSP()
    {
        memset(R, 0, sizeof R);
		memset(B_, -1, sizeof B_);
		rep(i, N) sort(all(B[i]));
        rep(i, N) rep(j, sz(B[i])) if (B_[B[i][j]] == -1) B_[B[i][j]] = i, R[i][j] = 1;

        vector<pair<pii, ll>> E;
        rep(u, N) for (auto &e : G[u]) E.eb(mp(u, e.ff), e.ss);

		sort(all(E));
        rep(i, N) rep(j, sz(B[i])) rep(k, sz(B[i])) if (j != k)
        {
            auto l = lower_bound(all(E), mp(mp(B[i][j], B[i][k]), -1ll));
            if (l != E.end() && (*l).ff == mp(B[i][j], B[i][k])) I[i][j][k] = l->ss;
            else I[i][j][k] = INF;
		}

        memset(D, 0, sizeof D);
		memset(V, 0, sizeof V);
		memset(P, -1, sizeof P);
        rep(i, MAXL) rep(j, MAXK) rep(k, N) UP[i][j][k] = DW[i][j][k] = INF;

        queue<int> Q; Q.push(0);
		while (!Q.empty())
        {
			int u = Q.front(), c = center(u); Q.pop();
			if (P[u] != -1) P[c] = P[u], D[c] = D[u];

			C[D[c]][c] = c;
			ord.clear();
			dfs(c, -1, D[c]);

			reverse(all(ord));
			for (int v : ord)
            {
                int sv = sz(B[v]);
                for (int w : T[v]) if (!V[w] && PT[w] == v)
                {
                    rep(a, sz(B[w])) rep(b, a)
                    {
                        rep(p, sv) if (B[w][a] == B[v][p])
                        {
                            rep(q, p) if (B[w][b] == B[v][q])
                            {
                                I[v][p][q] = min(I[v][p][q], I[w][a][b]);
                                I[v][q][p] = min(I[v][q][p], I[w][b][a]);
                            }
                        }
                    }
				}
                rep(i, sv) rep(j, sv) rep(k, sv)
                    I[v][j][k] = min(I[v][j][k], I[v][j][i] + I[v][i][k]);
			}

            reverse(all(ord));
			for (int v : ord) rep(i, MAXK) rep(j, MAXK) X[v][i][j][0] = X[v][i][j][1] = INF;

			int sc = sz(B[c]);
			rep(i, sc) X[c][i][i][0] = X[c][i][i][1] = 0;

			for (int v : ord)
            {
                rep(j, sc) rep(k, sz(B[v])) rep(l, sz(B[v]))
                {
                    X[v][j][l][0] = min(X[v][j][l][0], X[v][j][k][0] + I[v][k][l]);
                    X[v][j][l][1] = min(X[v][j][l][1], X[v][j][k][1] + I[v][l][k]);
				}
				for (int w : T[v]) if (!V[w] && PT[w] == v) rep(a, sz(B[v]))
                {
                    int b = find(all(B[w]), B[v][a]) - B[w].begin();
                    if (b < sz(B[w])) rep(c, sc)
                    {
                        X[w][c][b][0] = min(X[w][c][b][0], X[v][c][a][0]);
                        X[w][c][b][1] = min(X[w][c][b][1], X[v][c][a][1]);
                    }
                }
			}
			for (int p : ord) rep(q, sz(B[p])) if (R[p][q])
            {
                int v = B[p][q];
                rep(r, sc)
                {
                    UP[D[c]][r][v] = min(UP[D[c]][r][v], X[p][r][q][0]);
                    DW[D[c]][r][v] = min(DW[D[c]][r][v], X[p][r][q][1]);
                }
			}

			V[c] = 1;
			for (int v : T[c]) if(!V[v])
            {
                Q.push(v);
                P[v] = c, D[v] = D[c] + 1;
                rep(a, sz(B[v])) rep(b, a)
                {
                    rep(p, sc) if (B[v][a] == B[c][p])
                    {
                        rep(q, p) if (B[v][b] == B[c][q])
                        {
                            I[v][a][b] = min(I[v][a][b], I[c][p][q]);
                            I[v][b][a] = min(I[v][b][a], I[c][q][p]);
                        }
                    }
                }
			}
        }
    }

    int center(int u)
    {
		ord.clear();
        int n = dfs(u, -1), mn = 1e9, c;
		for (int v : ord)
        {
            int w = max(n - S[v], M[v]);
			if (w < mn) c = v, mn = w;
		}
		return c;
	}
 
	int dfs(int u, int p)
    {
		ord.pb(u); S[u] = 1, M[u] = 0;
		for (int v : T[u]) if (v != p && !V[v])
        {
            int s = dfs(v, u);
            S[u] += s, M[u] = max(M[u], s);
		}
        return S[u];
	}

	void dfs(int u, int p, int l)
    {
		ord.pb(u); PT[u] = p;
		for (int v : T[u]) if (!V[v] && v != p)
        {
            C[l][v] = C[l][u];
            dfs(v, u, l);
        }
	}

    ll query(int u, int v)
    {
		int a = B_[u], b = B_[v];
		int l = min(D[a], D[b]);
		while (C[l][a] != C[l][b]) l--;

		int c = C[l][a]; ll d = INF;
        rep(i, sz(B[c])) d = min(d, DW[l][i][u] + UP[l][i][v]);
		return d;
	}
};
