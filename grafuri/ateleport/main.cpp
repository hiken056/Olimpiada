#include <bits/stdc++.h>
#define INF 0x3f3f3f3f

using namespace std;

ifstream fin("ateleport.in");
ofstream fout("ateleport.out");

class heap {
    public:
        int u, d, t_used, e_used;

        bool operator < (const heap &A) const {
            return d > A.d;
        }
};

const int NMAX = 1e4 + 1;
const int KMAX = 11;
int N, M, P, L, K, dp[NMAX][KMAX][KMAX], ans = INF;
vector<pair<int,int>> G[NMAX];
priority_queue<heap> pq;

void read() {
    fin >> N >> M >> P >> L >> K;
    for(int i = 0; i < M; ++i) {
        int u, v, w;
        fin >> u >> v >> w;
        G[u].emplace_back(v, w);
        G[v].emplace_back(u, w);
    }
}

void Dijkstra() {
    for(int i = 1; i <= N; ++i)
        for(int j = 0; j <= K; ++j)
            for(int k = 0; k <= L; ++k)
                dp[i][j][k] = INF;
    pq.push({1, 0, 0, 0});
    dp[1][0][0] = 0;
    while(!pq.empty()) {
        int u = pq.top().u,
            d = pq.top().d,
            t_used = pq.top().t_used,
            e_used = pq.top().e_used;
        pq.pop();
        if(dp[u][t_used][e_used] != d)
            continue;
        for(const auto &v : G[u]) {
            if(e_used && e_used < L)
                if(dp[v.first][t_used][e_used + 1] > d) {
                    dp[v.first][t_used][e_used + 1] = d;
                    pq.push({v.first, dp[v.first][t_used][e_used + 1], t_used, e_used + 1});
                }
            if(dp[v.first][t_used][0] > d + v.second) {
                dp[v.first][t_used][0] = d + v.second;
                pq.push({v.first, dp[v.first][t_used][0], t_used, 0});
            }
            if(t_used < K)
                if(dp[v.first][t_used + 1][1] > d + P) {
                    dp[v.first][t_used + 1][1] = d + P;
                    pq.push({v.first, dp[v.first][t_used + 1][1], t_used + 1, 1});
                }
        }
    }
}

void min_self(int &a, int b) {
    a = min(a, b);
}

void print() {
    for(int k = 0; k <= K; ++k)
        for(int t = 0; t <= L; ++t)
            min_self(ans, dp[N][k][t]);
    fout << ans << '\n';
}

int main() {
    read();
    Dijkstra();
    print();
}
