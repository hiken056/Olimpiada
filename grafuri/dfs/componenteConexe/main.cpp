#include <bits/stdc++.h>

using namespace std;
const int MAXN = 100;

ifstream fin ("componenteconexe.in");
ofstream fout ("componenteconexe.out");

int N;
vector <int> G[MAXN + 5];
bool viz[MAXN + 5];
vector <vector <int>>container;
int GIDX;

void dfs( int node, int IDX) {
    viz[node] = 1;
    container[IDX].emplace_back(node);
    for ( const auto& vecin: G[node]) {
        if (!viz[vecin]) {
            dfs(vecin, IDX);
        } 
    }
} 

int main () {
    fin >> N;
    int x, y;
    while ( !fin.eof() ) {
        fin >> x >> y;
        G[x].emplace_back(y);
        G[y].emplace_back(x);
    }
    for ( int i = 1; i <= N; ++ i) {
        if (!viz[i]) {
            container.emplace_back(vector <int>());
            dfs(i, GIDX);
            GIDX++; 
        }
    }

    fout << GIDX << '\n';
    for ( auto& comp: container) {
        sort(comp.begin(), comp.end());
        for ( const auto& elem: comp) {
            fout << elem << " ";
        }
        fout << '\n';
    }
    return 0;
}