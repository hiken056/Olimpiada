#include <bits/stdc++.h>

using namespace std;

ifstream fin ("graf.in");
ofstream fout ("graf.out");

//se face cu bfs distanta cea mai scurta de la capete la nodul i
//daca pathX[i] + pathY[i] == pathX[Y] atunci apartine lantului
//pentru a fi in toate lanturile, trebuie sa apartina si sa fie singur pe nivelul sau 
//(daca luam graf ca un arbore sau dupa cum se parcurge bfs ul)
//daca ii singur pe nivel, apartine in graf si suma drumurilor la capete = drumul atunci satisface cerinta 

const int MAXN = 7505;

int N, M, X, Y;
int pathX[MAXN];
int pathY[MAXN];
int vfLvl[MAXN];
bool isInPath[MAXN];
vector <int> G[MAXN];
queue <int> Q;

void bfs (int root, int path[] ) {
    Q.push(root);
    path[root] = 0;
    while ( !Q.empty() ) {
        int node = Q.front();
        Q.pop();
        for ( auto vecin : G[node] ) {
            if ( path[vecin] == -1 ){
                path[vecin] = path[node] + 1;
                Q.push(vecin);
            }
        }
    }
}

int main () {
    fin >> N >> M >> X >> Y;
    while ( M -- ) {
        int x, y;
        fin >> x >> y;
        G[x].push_back(y);
        G[y].push_back(x);
    }
    for ( int i = 1; i <= N; ++ i ) {
        pathX[i] = -1;
        pathY[i] = -1;
    }
    bfs( X, pathX );
    bfs(Y, pathY);

    for (int i = 1; i <= N; ++ i) {
        if ( pathX[i] + pathY[i] == pathX[Y]) {
            vfLvl[pathX[i]] ++;
            isInPath[i] = 1;
        }
    }

    int countNodes = 0;
    for ( int i = 1; i <= N; ++ i) {
        if ( vfLvl[pathX[i]] == 1 && isInPath[i] == 1 ) {
            countNodes ++;
        }
    }
    fout << countNodes << '\n';
    for ( int i = 1; i <= N; ++ i ) {
        if ( vfLvl[pathX[i]] == 1 && isInPath[i] == 1 ) {
            fout << i << " ";
        }
    }
    return 0;
}