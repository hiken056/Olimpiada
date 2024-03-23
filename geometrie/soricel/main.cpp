#include <bits/stdc++.h>

using namespace std;

int B, h, n, T;
long double delta, d;
//fout << fixed<< setprecision(6)
ifstream fin ("soricei.in");
ofstream fout ("soricei.out");

int calculateDelta(int B) {
    return (sqrt(4.0 * B * B * h * h *(n-1)));
} 

void solve () {
    fin >> B >> h >> n;
    for ( int i = 1; i < n; ++ i ) {
        delta  = calculateDelta(B);
        fout << delta << " ";
        long double d1 =  (2.0 * B * h + delta ) / 2 * B;
        long double d2 =  (2.0 * B * h - delta ) / 2 * B;
            fout << fixed << setprecision(6) << d2 << " ";
            B = d2;
        
            fout << fixed << setprecision(6) << d1 << " ";
            B =  d1; 
    }
}

int main () {
    fin >> T;
    while ( T -- ) {
        solve();
    }    
    return 0;
}