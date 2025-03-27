#include <bits/stdc++.h>

using namespace std;

long double N, R;

const double pi = acos(-1.0);

int main() {
    cin >> N >> R;
    //unghiul dintre 2 petale
    long double alpha = 2 * pi / N;
    //din teorema sinusului in triunghiul format de centrele a 2 petale si centru mare
    //precizie de 12 zecimale
    cout << fixed << setprecision(12) << ( R * sin(alpha) / (2 * sin((pi-alpha) / 2.0) - sin(alpha))) << '\n';
    return 0;
}