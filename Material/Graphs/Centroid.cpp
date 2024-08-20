#include "../Template.cpp"

int N, u, v;
vvi G;
vi R, S, P;

int size(int u, int p)
{
	S[u] = 1;
	for (int v : G[u]) if (v != p && !R[v]) S[u] += size(v, u);
	return S[u];
}

int get_centroid(int u, int s, int p, int d)
{
	for (int v : G[u]) if (v != p && !R[v] && S[v] * 2 > s) return get_centroid(v, s, u, d + 1);
	return u;
}

void build(int u, int p)
{
	int c = get_centroid(u, size(u, -1), -1, 1);
	P[c] = p, R[c] = 1;
	for (int v : G[c]) if (!R[v]) build(v, c);
}
