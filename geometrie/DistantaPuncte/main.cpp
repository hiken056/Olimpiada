#include <bits/stdc++.h>

using namespace std;

ifstream fin("distantapuncte.in");
ofstream fout("distantapuncte.out");

int x11, y11, x22, y22;

double distantaLaPatrat(int x1, int y1, int x2, int y2) {
    return (pow(x2 - x1, 2) + pow(y2 - y1, 2));
}

int main() {
    fin >> x11 >> y11 >> x22 >> y22;
    fout << distantaLaPatrat(x11, y11, x22, y22);
    return 0;
}