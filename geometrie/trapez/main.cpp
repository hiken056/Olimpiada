#include <bits/stdc++.h>

using namespace std;

ifstream fin("trapez.in");
ofstream fout("trapez.out");

const int MAXN = 1005;
int N, ans;

struct point {
   int x;
   double y;
//    bool operator < (point& a) const {
//         if ( x )
//    }
} puncte[MAXN];

double pante[MAXN];


int main () {
    fin >> N;
    int k = 1;
    ans = 0;
    for ( int i = 1; i <= N; ++ i ) {
        fin >> puncte[i].x >> puncte[i].y;
    }
    for ( int i = 1; i < N; ++ i ) {
        for ( int j = i + 1; j <= N; ++ j ) {
            pante[k] = (puncte[j].y - puncte[i].y)/(puncte[j].x - puncte[i].x);
            k ++;
        }
    }
    k --;
    // for ( int i = 1; i <= k; ++ i ) {
        
    //     fout << lines[i].a.x << ", " <<lines[i].a.y << "   " << lines[i].b.x << ", " << lines[i].b.y << "   " << lines[i].slope << '\n';
    // }
    for ( int i = 1; i < k; ++ i ) {
        for ( int j = i + 1; j <= k; ++ j ) {
            if ( pante[i] == pante[j] ) ans ++;
        }
    } 
    fout << ans;
}