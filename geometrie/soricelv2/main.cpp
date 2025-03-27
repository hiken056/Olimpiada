#include <bits/stdc++.h> 

using namespace std;

ifstream fin("soricei.in");
ofstream fout("soricei.out");

int T;
float  N, B, H;

void solve() {
    fin >> B >> H >> N;
    //facand taieturi, aria mai mica ii A/N
    //raportul arilor este i/N cand le parcurgi
    //atunci raportul laturilor este sqrt(i/N) 
    //daca raportul la laturile triunghiurilor asemenea este k, atunci la arii este k^2, la volume k^3 
    for ( int i = N - 1; i >= 1; -- i) {
        //inaltimea triunghiului mai mic este H * raportul
        //distanta este H - h
        fout << fixed << setprecision(6) << H - ( H * (sqrt(i/N))) << " "; 
    }
    fout << '\n';
}

int main() {
    fin >> T;
    while ( T --)  {
        solve();
    }
    return 0;
}