#include <iostream>
#include <fstream> 

using namespace std;

ifstream fin ("muffin.in");
ofstream fout ("muffin.out");

int n, m, a[101][101], viz[101], nrcomp;

void dfs(int start) {
    viz[start] = nrcomp;
    for ( int i = 1; i<= n; i ++ ) {
        if ( !viz[i] && a[start][i] ) {
            dfs(i);
        }
    }
}

int main () {
    fin >> n >> m;
    int x, y;
    
    while ( fin >> x >> y ) {
        a[x][y] = a[y][x] = 1;
    }
    
    dfs(1);
    int ok = 1;
    for ( int i = 1; i <= n; i ++ ) {
        if (  !viz[i] ) ok = 0;
    }
    if ( ok == 1 ) fout << "Muffin aproved!";
    else fout << "Muffin te mananca!" ;
    fout << endl << "comp conexe:" << endl;
    for ( int i = 1; i <= n; i ++ ) {
        if ( !viz[i] ) {
            nrcomp ++;
            dfs(i);
        }
    }
    fout << nrcomp << endl;
    for ( int i = 1; i <= nrcomp; i ++ ) {
        for ( int j = 1; j <= n; j ++ ) {
            if ( viz[j]  == i ) fout << j << " ";
        }
        fout << endl;
    }
    return 0;
}