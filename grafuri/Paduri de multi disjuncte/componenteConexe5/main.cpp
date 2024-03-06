#include <bits/stdc++.h>

using namespace std;

const int MAXN = 1000;

ifstream fin ("componenteconexe5.in");
ofstream fout ("componenteconexe5.out");

int N, M;
int root[MAXN + 5];
int height[MAXN + 5]; 
int cnt[MAXN + 5];

int getRoot( int nod) {
    if ( root[nod] == nod) return nod;
    return (root[nod] = getRoot(root[nod]));
}

void unite ( int x, int y) {
    int rootX = getRoot(x);
    int rootY = getRoot(y);
    if ( rootX == rootY ) return;
    if ( height[rootX] > height[rootY] ) {
        root[rootY] = rootX;
        cnt[rootX] += cnt[rootY];
    }
    else {
        root[rootX] = rootY;
        cnt[rootY] += cnt[rootX];
        if ( height[rootX] == height[rootY]) {
            height[rootY] ++;
        }
    }

}



int main () {
    fin >> N >> M;
    for ( int i = 1; i <= N; ++ i) {
        root[i] = i;
        cnt[i] = 1;
    }
    int x, y;
    while ( M -- ) {
        fin >> x >> y;
        unite(x, y);
    }
    fin >> M;
    while ( M -- ) {
        fin >> x;
        fout << cnt[getRoot(x)] << '\n';
    }
    return 0;
}