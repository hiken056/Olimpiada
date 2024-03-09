#include <bits/stdc++.h>

using namespace std;


ifstream fin ("ctc.in");
ofstream fout ("ctc.out");

const int MAXN = 1e5;

int N, M;
vector <int> G[MAXN + 1];
vector <int> lowlink;
vector <int> idx;
int GIDX;
stack <int> stiva;
vector <bool> check;
vector <bool> viz;

 
void tarjan( int nod, int IDX ) {
    x
}


int main () {
    fin >> N >> M;
    lowlink.resize(N+1);
    idx.resize(N+1);
    check.resize(N+1, false);
    viz.resize(N+1, false) ;
    int x,y;
    while ( M -- ) {
        fin >> x >> y;
        G[x].push_back(y);
    }
    return 0;
}