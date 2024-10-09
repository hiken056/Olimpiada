#include <bits/stdc++.h>

using namespace std;

ifstream fin("date.in");
ofstream fout ("date.out");
int main() {
    int n, bit = 0, m = 0;
    cin >> n;
    cout << "merge\n";
    int countBits[100005];
    countBits[0] = 0;
    countBits[1] = 1;
    //ideea este ca daca nr este par ==> nr de biti o sa fie nr de biti la n/2
    //daca nr este impar ==> nr de biti o sa fie nr de biti la n/2 + 1
    for ( int i = 2; i <= n; ++ i ) {
        if ( i % 2  == 0 ) countBits[i] = countBits[i/2];
        else countBits[i] = countBits[i/2] + 1;
    }
    for ( int i = 0; i <= n; ++ i ) {
        cout << countBits[i] << " ";
    }
    return 0;
}