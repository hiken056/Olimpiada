#include <bits/stdc++.h>

using namespace std;

ifstream fin ("lgput.in");
ofstream fout ("lgput.out");

#define ll long long

const int MOD = 1999999973;
ll N, P;

ll logPow ( ll n, ll p ) {
    if ( p == 0 ) return 1;
    ll n2 = logPow(n, p/2);
    if ( p < 0 ) {
        
    }
    if ( p % 2 == 0 ) {
        return (n2 * n2 % MOD); 
    }
    else return (((n2 * n2 % MOD) * n) % MOD );
}

int main () {

    fin >> N >> P;
    fout << logPow(N, P);
    return 0;
}