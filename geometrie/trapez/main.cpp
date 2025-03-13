#include <bits/stdc++.h>

using namespace std;

ifstream fin("trapez.in");
ofstream fout("trapez.out");

const int MAXN = 1e3 + 5;
int N, ans;
int xx;
double yy;

struct line
{
    int x1, x2;
    double y1, y2;
    double slope;
}lines[MAXN];

int main () {
    fin >> N;
    int k = 1;
    ans = 0;
    while ( fin >> xx >> yy ) {
        
    }
    for ( int i = 1; i < N; ++ i ) {
        for ( int j = i + 1; j <= N; ++ j ) {
            point a = puncte[i];
            point b = puncte[j];
            lines[k].a = a;
            lines[k].b = b;
            lines[k].slope = (b.y - a.y)/(b.x - a.x);
            k ++;
        }
    }
    k --;
    // for ( int i = 1; i <= k; ++ i ) {
        
    //     fout << lines[i].a.x << ", " <<lines[i].a.y << "   " << lines[i].b.x << ", " << lines[i].b.y << "   " << lines[i].slope << '\n';
    // }
    for ( int i = 1; i < k; ++ i ) {
        for ( int j = i + 1; j <= k; ++ j ) {
            if ( lines[i].slope == lines[j].slope ) ans ++;
        }
    }
    fout << ans;
}
