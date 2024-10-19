#include <bits/stdc++.h>

using namespace std;

ifstream fin ("kfib.in");
ofstream fout ("kfib.out");

//se face cu exponentiere rapida pe matrici
// ( F(n+1) F[n] )
// ( F[n] F[n-1] )
//ridici totu la n-1 si in matrice[1][1] = F[n]; (insane)

#define ll long long 

const int MOD = 666013;
const int MAXN = 1e9 + 5;
ll N, fibo[2][2];

ll logPow ( ll n[2][2], ll p ) {
    if ( p == 0 ) {
        return 1;
    }
    int n2 = logPow(n, p/2);
    if ( p % 2 == 0 ) return (matrixMultiplication(n) % MOD);
    else return (((n2 * n2 % MOD ) * n ) % MOD);
}

void matrixMultiplication (ll n[2][2] ) {
    ll resl[2][2];
    for ( int i = 0; i < 2; ++ i ) {
        for ( int j = 0; j < 2; ++ j ) {
            resl[i][j] = 0;
            for ( int k = 0; k < 2; k ++ ) {
                resl[i][j] += (n[i][k] * n[k][j]) % MOD;
            }
        
        }
    }

    for ( int i = 0; i < 2; ++ i ) {
        for ( int j = 0; j < 2; ++ j ) {
            n[i][j] = resl[i][j];
        }
    }
} 

int main () {
    fin >> N;

}