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
ll N, fibo[3][3];

ll logPow ( ll n, ll p ) {
    if ( p == 0 ) {
        return 1;
    }
    int n2 = logPow(n, p/2);
    if ( p % 2 == 0 ) return (n2 * n2 % MOD);
    else return (((n2 * n2 % MOD ) * n ) % MOD);
}

int main () {
    fin >> N;

}