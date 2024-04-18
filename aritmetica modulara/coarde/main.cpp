#include <bits/stdc++.h>

using namespace std;

ifstream fin ("coarde.in");
ofstream fout ("coarde.out");

const int MODULO = 9999991;

int num;

int log_pow(int n, int p) {
    if ( p == 0 ) return 1;
    int n2 = log_pow(n, p/2);
    if ( p % 2 == 0 ) {
        return (1ll * n2 * n2) % MODULO;
    }
    else {
        return ((((1ll * n2 * n2) % MODULO) * n) % MODULO);
    }
}

int catalan(int n) {
    long long n2fac = 1;
    long long nfac = 1;
    long long n_1fac = 1;
    for ( int i = 1; i <= n*2 ; ++ i ) {
        n2fac = ( 1ll * n2fac * i ) % MODULO;
        if ( i == n ) {
            nfac = n2fac;
        }
        if ( i == n + 1) {
            n_1fac = n2fac; 
        }
    }
    nfac = log_pow(nfac, MODULO - 2);
    n_1fac = log_pow(n_1fac, MODULO - 2);
    return ((((1ll * n2fac * nfac) % MODULO ) * n_1fac ) % MODULO);
}

int main () {
    fin >> num;
    fout << catalan(num);
    return 0;
}