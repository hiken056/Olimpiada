#include <bits/stdc++.h>

using namespace std;

const int MAXN = 505;
int N;
int dist[MAXN][MAXN];
long long sum;
stack < long long > rez;
bool ap[MAXN];
int nodes[MAXN];

int main () {
    cin >> N;
    for ( int i = 1; i <= N; ++ i ) {
        for ( int j = 1; j <= N; ++ j ) {
            cin >> dist[i][j]; 
        }
    }
    for ( int i = 1; i <= N; ++ i ) {
        cin >> nodes[i];
    }

    for ( int k = N; k >= 1; -- k ) {
        sum = 0;
        ap[nodes[k]] = 1;
        for ( int i = 1; i <= N; ++ i ) {
            for ( int j = 1; j <= N; ++ j ) {
                if ( i == j ) continue;
                dist[i][j] = min ( dist[i][j], dist[i][nodes[k]] + dist[nodes[k]][j]);
                if ( ap[i] && ap[j] ) sum += dist[i][j];
            }
        }
        rez.push(sum);
    }
    while ( !rez.empty() ) {
        cout << rez.top() << " ";
        rez.pop(); 
    }
    return 0;
}