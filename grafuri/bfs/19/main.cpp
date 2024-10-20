    #include <fstream>
    #include <vector>
    #include <queue>
using namespace std;

ifstream fin ("BFS.in");
ofstream fout ("BFS.out");

const int MAXN = 100;
int N, M, X;
vector <int> G[MAXN + 5];
bool viz[MAXN + 5];
queue <int> coada;

void bfs( int root ) {
    coada.push(root);
    while ( !coada.empty() ) {
        int node = coada.front();
        coada.pop();
        if ( viz[node] ) continue;
        viz[node] = 1;
        fout << node << " ";
        for ( const auto& vecin: G[node]) {
            if ( !viz[vecin] ) {
                coada.push(vecin);
            }
        }
    } 
}

int main ( ) {
    fin >> N >> M >> X;
    int x, y;
    for ( int i = 1; i <= M; ++ i) {
        fin >> x >> y;
        G[x].emplace_back(y);
        G[y].emplace_back(x);
    } 
    for ( int i = 1; i <= N; ++ i) {
        sort(G[i].begin(), G[i].end());
    }
    bfs(X);
    return 0;
}