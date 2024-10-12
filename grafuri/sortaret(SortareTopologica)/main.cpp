#include <bits/stdc++.h>

using namespace std;

ifstream fin ("sortaret.in");
ofstream fout ("sortaret.out");

//sortare topologica

const int MAXN =5e4 + 5;
vector <int> G[MAXN];
int rez[MAXN];
bool viz[MAXN];
int n, m, dr;

void dfs( int nod ) {
    viz[nod] = 1;
    for ( auto it : G[nod] ) {
        if ( !viz[it] ) {
            dfs(it);
        }
    }
    rez[dr++] = nod;
}

int main () {
    int x, y;
    fin >> n >> m;
    while ( m -- ) {
        fin >> x >> y;
        G[x].push_back(y); 
    }   
    for ( int i = 1; i <= n; ++ i ) {
        if ( viz[i] == 0 ) {
            dfs(i);
        }
    }
    for ( int i = dr-1; i >= 0; --i ) {
        fout << rez[i] << " ";
    }
    return 0;
}