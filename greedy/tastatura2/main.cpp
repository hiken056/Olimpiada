#include <bits/stdc++.h>

using namespace std;

const int MAXN = 20000;

ifstream fin ( "tastatura2.in");
ofstream fout ("tastatura2.out");

string s, t;

int vfs[256], vft[256];

int sol;

int solve(string s, string t, int sol = 0) {
    for ( const char& i : s ) {
        vft[i] ++;
    }
    for ( const char& i : t ) {
        vfs[i] ++;
    }
    for ( int i = 1; i <= 256; ++ i ) {
        if ( vfs[i] != vft[i] ) sol++;
    }
    return sol;
}

int main () {
    getline(fin, s);
    getline(fin, t);
    while ( s != "*" ) {
        solve(s, t);
        fout << sol << '\n';
        getline(fin, s);
        getline(fin, t);
    }
    return 0;
}
