#include <bits/stdc++.h>
using namespace std;

ifstream in("festivaluri.in");
ofstream out("festivaluri.out");

#define oo 1e5
#define MAXN 105

int N, M, P, Z, F;
vector<pair<int, int>> G[MAXN];
set<pair<int, int>> S;
vector<int> dist;
vector<int> fest;

int main() {
    in >> N >> M >> P >> Z >> F;
    dist.resize(N + 1, oo);   
    fest.resize(F);          

    while (M--) {
        int x, y, c;
        in >> x >> y >> c;
        G[x].push_back({y, c});
    }

    for (int i = 0; i < F; ++i) {
        in >> fest[i];
    }

    dist[Z] = 0;
    S.insert({0, Z});
    while (!S.empty()) {
        int nod = S.begin()->second;
        S.erase(S.begin());
        for (auto vecin : G[nod]) {
            if (dist[vecin.first] > dist[nod] + vecin.second) {
                S.erase({dist[vecin.first], vecin.first});
                dist[vecin.first] = dist[nod] + vecin.second;
                S.insert({dist[vecin.first], vecin.first});
            }
        }
    }

    // Sortează festivalurile după distanțele calculate către fiecare locație de festival
    vector<int> cost_fest;
    for (int f : fest) {
        if (dist[f] != oo) {  // Doar dacă festivalul este accesibil
            cost_fest.push_back(dist[f]);
        }
    }
    sort(cost_fest.begin(), cost_fest.end());

    // Calculează numărul maxim de festivaluri la care Tudor poate participa
    int cnt = 0;
    for (int cost : cost_fest) {
        if (P >= cost) {
            P -= cost;
            cnt++;
        } else {
            break;
        }
    }

    out << cnt;
    return 0;
}
