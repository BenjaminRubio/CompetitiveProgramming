#include <bits/stdc++.h>
using namespace std;

int N, M, K;
int mem[10][9][1024] {0};
int memo[10][9][1024] {0};

int ways(){
    for (int i = N; i >= 0; i--) {
        memset(mem, 0, sizeof mem);
        for (int j = M - 1; j >= 0; j--) {
            for (int k = 0; k <= K; k++) {
                for (int m = 0; m < (1 << M); m++) {
                    if (k == 0) {
                        mem[j][k][m] = 1;
                        continue;
                    }
                    if (i == N) {
                        mem[j][k][m] = 0;
                        continue;
                    }
                    int partial;
                    int m_ = m_ = m & (((1 << M) - 1) ^ (1 << j));
                    if (j == M - 1) {
                        m_ = (m_ | (m_ >> 1) | ((m_ << 1) & ((1 << M) - 1)));
                        partial = memo[0][k][m_];
                    } else {
                        partial = mem[j + 1][k][m_];
                    }
                    if (!(m & (1 << j))) {
                        m_ = m | (1 << j);
                        if (j < M - 1) m_ |= (1 << (j + 1));
                        if (j == M - 1) {
                            m_ = (m_ | (m_ >> 1) | ((m_ << 1) & ((1 << M) - 1)));
                            partial += memo[0][k - 1][m_];
                        } else {
                            partial += mem[j + 1][k - 1][m_];
                        }
                    }
                    mem[j][k][m] = partial % 1000007;
                }
            }
        }
        copy(&mem[0][0][0], &mem[0][0][0] + 10 * 9 * 1024, &memo[0][0][0]);
    }
    return memo[0][K][0];
}

int main() {
    cin >> N >> M >> K;
    cout << ways();
}