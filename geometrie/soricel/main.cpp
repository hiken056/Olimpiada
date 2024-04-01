#include <bits/stdc++.h>

using namespace std;

int T;
double B, H, n;
double b[105], a, h[105];
//fout << fixed<< setprecision(6)
ifstream fin ("soricei.in");
ofstream fout ("soricei.out");

int calculateDelta(int i) {
    return (sqrt(i*H*2*a/(B*n)));
} 

void solve () {
    fin >> B >> H >> n;
    a = B*H/2;
    for ( int i = 1; i <= n; ++ i ) {
        b[i] = i * B * B;
        b[i] /= n;
        b[i] = sqrt(b[i]);
    }
    for ( int i = n - 1; i >= 1; -- i ) {
        h[i] = H - sqrt(i*H*2*a/(B*n));
        fout<<fixed<<setprecision(6)<<h[i]<<" ";
    }
}

int main () {
    fin >> T;
    while ( T -- ) {
        solve();
    }    
    return 0;
}