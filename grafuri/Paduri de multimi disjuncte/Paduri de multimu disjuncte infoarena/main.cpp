#include <bits/stdc++.h>

using namespace std;

ifstream fin ("disjoint.in");
ofstream fout ("disjoint.out");

int n, queries;

void readData () {
    fin >> n >> queries;
}

void sortQueries ( ) {  
    int task, x, y;
    while ( queries -- ) {
        fin >> task >> x >> y;
        if ( task == 1 ) {
            solveTask(x, y);
        }
        else {
            if ( solveTask2 (x, y) ) {
                fout << "DA\n";
            }
            else {
                fout << "NN\n";
            }
        }
    }
}

int main () {
    readData();


    fin.close();
    fout.close();
    return 0;
}