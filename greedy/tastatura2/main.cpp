#include <bits/stdc++.h>

using namespace std;

ifstream fin ( "tastatura2.in");
ofstream fout ("tastatura2.out");

string s, t;

int vfs[256], vft[256];

int solve(string s, string t, int sol = 0) {
    for ( const char& i : s ) {
        vft[i] ++;
    }
    for ( const char& i : t ) {
        vfs[i] ++;
    }
    for ( int i = 0; i < 256; ++ i ) {
        if ( vfs[i] != vft[i] ) sol++;
    }
    return sol;
}

int main () {
    getline(fin, s);
    getline(fin, t);
    while ( s != "*" ) {
        fout << solve(s, t) << '\n';
        getline(fin, s);
        getline(fin, t);
        for ( int i = 0; i < 256; ++ i) {
            vfs[i] = 0;
            vft[i] = 0;
        }
    }
    return 0;
}
