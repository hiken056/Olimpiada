#include <bits/stdc++.h>

using namespace std;

ifstream fin("infasuratoare.in");
ofstream fout("infasuratoare.out");

#define x first 
#define y second 

typedef pair<double, double> Point;

int N;
vector <Point> Points;

double calculateDelta ( Point O, Point A, Point B) {
    return (A.x - O.x) * (B.y - O.y) - (A.y - O.y) * (B.x - O.x);
}

vector<Point> ConvexHull( vector<Point> &Points ) {
    int n = Points.size();
    //nu sis destule puncte
    if ( n <= 1 ) return vector<Point>();
    //sortare dupa x, iar dupa daca trbuie dupa y
    sort(Points.begin(), Points.end());
    //hull ul curent pe care il facem cu marime 2 * n pentru a incapea toate
    //hull este pe post si de stiva
    vector <Point> hull(n * 2);
    int k = 0;
    //prima jumatate
    for ( int i = 0; i < n; ++ i ) {
        //k >= 2 pentru a avea destule puncte pentru a calcula delta
        //hull[k-2] penultimul pct din stiva
        //hull[k-1] ultimul pct din stiva
        //Points[i] pct curent 
        while ( k >= 2 && calculateDelta(hull[k -2], hull[k - 1], Points[i]) <= 0) 
            k --;
        hull[k ++] = Points[i];
    }

    //a doua jumatate
    for ( int i = n - 2, t = k + 1; i >= 0 ; -- i ) {
        //k >= t pentru a nu intra in punctele din prima jumatate
        while ( k >= t && calculateDelta(hull[k-2], hull[k-1], Points[i]) <= 0 ) {
            k --;
        }
        hull[k ++] = Points[i];
    }
    //k - 1 pentru ca ultimul element este de odoua ori
    hull.resize(k -1);
    return hull;
}

int main() {
    fin >> N;
    Points.resize(N);
    for ( int i = 0; i < N; ++ i ) {
        fin >> Points[i].x >> Points[i].y;
    }
    vector <Point> Hull = ConvexHull(Points);
    fout << Hull.size() << "\n";
    for ( Point p : Hull ) {
        fout << fixed << setprecision(6) << p.x << " " << p.y << '\n';
    }
}