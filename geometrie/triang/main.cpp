#include <bits/stdc++.h>

using namespace std;

ifstream fin ("triang.in");
ofstream fout ("triang.out");

const double dif = 1e-3;

int N, rez;
struct punct {
    double x;
    double y;
    //prima data compar dupa x, iar daca dif este neglijabila compar dupa y
    bool operator < (const punct& a) const{
        if ( abs(x - a.x) > dif ) 
            return x < a.x;
        if ( abs(y - a.y) > dif ) 
            return y > a.y;
        return 0;
    }
} puncte[1505];
set <punct> s;

punct rotatie ( punct a, punct b ) {
    //sin si cos de 60
    double cos = 1.0 / 2;
    double sin = sqrt(3) / 2;
    punct c;
    //rotatia unui punct fata de alt punct
    c.x = a.x + ( b.x - a.x ) * cos - ( b.y - a.y) * sin;
    c.y = a.y + ( b.x - a.x ) * sin + ( b.y - a.y) * cos;
    return c;
}

int main() {
    fin >> N;
    for ( int i = 1; i <= N; ++ i ) {
        fin >> puncte[i].x >> puncte[i].y;
        //verificam daca gasim punctul pe care il rotim
        for ( int j = 1; j  < N; ++ j ) {
            if ( s.find(rotatie(puncte[i], puncte[j])) != s.end() ) {
                rez ++;
            }
        }
        s.insert(puncte[i]);
    }
    fout << rez;
}