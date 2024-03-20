#include <bits/stdc++.h>

using namespace std;

int B, h, n, T;
int delta, d;

ifstream fin ("soricei.in");
ofstream fout ("soricei.out");

int calculateDelta(int B) {
    return ((4 * B * B) (n-h*h) / 2);
} 

void solve () {
    fin >> B >> h >> n;
    for ( int i = 1; i < n; ++ i ) {
        delta  = calculateDelta(B);
    }
}

int main () {
    fin >> T;
    while ( T -- ) {
        solve();
    }    
    return 0;
}