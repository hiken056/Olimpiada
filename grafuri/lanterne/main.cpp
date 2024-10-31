#include <bits/stdc++.h>

using namespace std;

ifstream in ("lanterna.in");
ofstream out ("lanterna.out");

#define MAXN 55
#define oo 1e7

int N, M, K;
bool baza[MAXN];
int timp[MAXN];
int lant;
int path[MAXN];

vector < pair < pair < int, int > , int > > G[MAXN];
set < pair < int, int > > S;

int main () {
    in >> N >> K;   
    for ( int i = 1; i <= N; ++ i ) {
        in >> baza[i];
    }
    in >> M;
    while ( M -- ) {
        int x, y, t, w;
        in >> x >> y >> t >> w;
        G[x].push_back({{y, t}, w});
        G[y].push_back({{x, t}, w});
    }
    for ( int i = 2; i <= N; ++ i ) {
        timp[i] = oo;
    }
    path[1] = -1;
    S.insert({0, 1});
    while ( !S.empty() ) {
        int nod = S.begin()->second;
        S.erase(S.begin());
        for (auto vecin : G[nod] ) {
            if ( timp[vecin.first.first] > timp[nod] + vecin.first.second ) {
                S.erase({timp[vecin.first.first], vecin.first.first});
                timp[vecin.first.first] = timp[nod] + vecin.first.second;
                S.insert({timp[vecin.first.first], vecin.first.first});
                path[vecin.first.first] = nod; 
            }
        }
    }

    vector <int> fullpath;

    for ( int nod = N; nod != -1; nod = path[nod] ) {
        fullpath.push_back(nod);
    }
    reverse(fullpath.begin(), fullpath.end());

    int sum = 0;
    int max = 0;

    int maxSum = 0;

    for (int i = 0; i < fullpath.size(); ++i) {
        int v = fullpath[i];
        if (baza[v] == 1 || v == 1) {
            for (int j = i + 1; j < fullpath.size(); ++j) {
                int u = fullpath[j];
                if (baza[u] == 1 || u == N) {
                    int sum = 0;
                    for (int k = i; k < j; ++k) {
                        int cur = fullpath[k];
                        int next = fullpath[k + 1];
                        for (auto vecin : G[cur]) {
                            if (vecin.first.first == next) {
                                sum += vecin.second; 
                                break;
                            }
                        }
                    }
                    if ( maxSum < sum ) maxSum = sum;
                    i ++;
                }
            }
        }
    }
    out << timp[N] << " " << maxSum;
    return 0;
}
