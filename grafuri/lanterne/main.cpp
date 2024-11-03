#include <iostream>
#include <vector>
#include <queue>
#define inf 1000000001
using namespace std;

//codul lui ignat

bool station[55];
int k, n, m, x, y, c, w, mindist;
int dist[55][1005];
queue < pair < pair < int , int > , int > > q;
struct Road{
    int nd, t, w;
    Road(int nd, int t, int w) {
        this->w = w; this->nd = nd; this->t = t;
    }
};

vector < Road > v[55];

void read() {
    cin >> n >> k; 
    for (int i=1;i<=n;i++) {
        cin >> station[i];
    }
    cin >> m;
    for (int i=1;i<=m;i++) {
        cin >> x >> y >> c >> w;
        v[x].push_back(Road(y, c, w));
        v[y].push_back(Road(x, c, w));
    }
}

void reset() {
    for (int i=1;i<=n;i++) {
        for (int j=0;j<=k;j++) {
            dist[i][j] = inf;
        }
    }
}

int dijkstra(int watts) {
    reset();
    dist[1][watts] = 0;
    q.push({{0, watts}, 1});
    while (!q.empty()) {
        int watts_left = q.front().first.second;
        int dist_node = q.front().first.first;
        int node = q.front().second;
        q.pop();
        if (dist[node][watts_left] < dist_node) continue;
        for (auto ed: v[node]) {
            if (ed.w > watts_left) continue;
            int next_watts = (station[ed.nd] ? watts : watts_left-ed.w);
            if (dist[ed.nd][next_watts] > dist[node][watts_left] + ed.t) {
                dist[ed.nd][next_watts] = dist[node][watts_left] + ed.t;
                q.push({{dist[ed.nd][next_watts], next_watts}, ed.nd});
            }
        }
    }
    int mindist = inf;
    for (int j=0;j<=k;j++) {
        mindist = min(mindist, dist[n][j]);
    }
    return mindist;
}

void solve() {
    int st = 1, dr = k;
    mindist = dijkstra(k);
    while (st != dr) {
        int mij = (st + dr) / 2;
        if (dijkstra(mij) == mindist) {
            dr = mij;
        }
        else st = mij + 1;
    }
    cout << mindist << " " << st;
}

int main() {
    freopen("lanterna.in", "r", stdin);
    freopen("lanterna.out", "w", stdout);
    read();
    solve();
    return 0;
}