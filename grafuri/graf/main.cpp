#include <bits/stdc++.h>

using namespace std;

ifstream fin ( "graf.in");
ofstream fout ( "graf.out" );

const int MAXN = 7505;
int N, M, X, Y;
vector <int> G[MAXN];
queue <int> Q;
int rez1[MAXN];
int rez2[MAXN];
int tata1[MAXN];
int tata2[MAXN];
int path[MAXN];

void bfs ( int root, int rez[], int tata[]) {
    Q.emplace(root);
    rez[root] = 0;
    while ( !Q.empty() ) {
        int node =  Q.front();
        Q.pop();
        for ( auto vecin : G[node] ) {
            if ( rez[vecin] == -1 ) {
                Q.emplace(vecin);
                rez[vecin] = rez[node] + 1;
                tata[vecin] = node;
            }
        }
    }
}

void reconstructPath ( int x, int y, int tata[] ) {
   int cont = 0;
   for ( int i = y; i != 0; -- i ) {
        path[cont ++] = i;
   }
   for ( int i = 1; i <= N; ++ i) {
        cout << path[i] << " ";
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
        rez1[i] = -1;
        rez2[i] = -1;
    }
    bfs(X, rez1, tata1);
    bfs(Y, rez2, tata2);
    for ( int i = 1; i <= N; ++ i ) {
        fout << rez1[i] <<  " ";
    }
    fout << '\n';
    for ( int i = 1; i <= N; ++ i ) {
        fout << rez2[i] <<  " ";
    }

    reconstructPath(X, Y, tata1);
    return 0;
}

