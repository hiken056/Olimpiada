#include <bits/stdc++.h>
#include <fstream>

using namespace std;

ifstream fin ("joc6.in");
ofstream fout ("joc6.out");

const int MAXN = 155;
int N;
vector <int> S;
int dp[MAXN]; //lungimea max de i nr
int m[MAXN][MAXN];

int lMax ( int v[], int linie ) {
    if ( linie % 2 == 0 ) {
        for ( int i = 1; i <= N; ++ i ) {
            dp[i] = 1;
            for ( int j = 1; j < i; ++ j ) {
                if (m[linie][i] <= m[linie][j] ) {
                    dp[i] = max(dp[i], dp[j] + 1);
                }
            }
        }
    }
    else {
        for ( int i = 1; i <= N; ++ i ) {
            dp[i] = 1;
            for ( int j = 1; j < i; ++ j ) {
                if (m[linie][i] >= m[linie][j] ) {
                    dp[i] = max(dp[i], dp[j] + 1);
                }
            }
        }
    }
    int maxx = dp[1];
    for ( int i = 1; i <= N; ++ i ) {
        maxx = max(maxx, dp[i]);
        dp[i] = 0;
    }
    return maxx;
}

int main () {
    fin >> N;
    S.resize(N + 1);
    for ( int i = 1; i <= N; ++ i ) {
        for ( int j = 1; j <= N; ++ j ) {
            fin >> m[i][j];
        }
    }
    for (int i = 1; i <= N; ++ i ) {
        S[i] = lMax(m[i], i);
    }
    int sp = 0, sip = 0;
    for ( int i = 1; i <= N; ++ i ) {
        (i % 2 == 0 ) ? sp+= S[i] : sip += S[i];
    }
    fout << sip << " " << sp << '\n';
    if ( sip > sp ) fout << "UNU";
    else if ( sp == sip ) fout << "REMIZA";
    else fout << "DOI";
}
