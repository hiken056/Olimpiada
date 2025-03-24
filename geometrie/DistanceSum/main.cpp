#include <bits/stdc++.h>

using namespace std;

ifstream fin("distancesum.in");
ofstream fout("distancesum.out");

const int MAXN = 1e5 + 5;

struct Point{
    int x, y;
}puncte[MAXN];

int N, M;
int x, y;

void solve() {
    fin >> x >> y;
    long long sum = 0;
    for ( int i = 1; i <= N; ++ i ) {
        sum += max(abs(x - puncte[i].x), abs(y - puncte[i].y));
    }
    fout << sum << endl;
}

int main() {
    fin >> N >> M;
    for ( int i = 1; i <= N; ++ i ) {
        fin >> puncte[i].x >> puncte[i].y;
    }
    while ( M -- ) {
        solve();
    }
}