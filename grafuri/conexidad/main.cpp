#include <bits/stdc++.h>

using namespace std;

ifstream fin ("conexidad.in");
ofstream fout ("conexidad.out");

#define MAXN 105

int N, M, nrCC;
vector <int> G[MAXN], CC[MAXN], isolated, remains;
bool viz[MAXN];
vector < pair < int, int > > edges;
int maxExtra;

void dfs ( int root ) {
    viz[root] = 1;
    CC[nrCC].push_back(root);
    for ( auto vecin : G[root] ) {
        if ( !viz[vecin] ) {
            dfs(vecin);
        }
    }
}

int main () {
    fin >> N >> M;
    while ( M -- ) {
        int x, y;
        fin >> x >> y;
        G[x].push_back(y);
        G[y].push_back(x);  
    }

    for ( int i = 1; i <= N; ++ i ) {
        if ( !viz[i] ) {
            if ( G[i].empty() ) {
                isolated.push_back(i);
                viz[i] = 1;
            }
            else {
                nrCC ++;
                dfs(i);
            }
        }
    }

    //reset viz
    fill(viz + 1, viz + N + 1, 0);
    //adauga muchie intre componentele conexe 
    for ( int i = 1; i < nrCC; ++ i ) {
        int n1 = CC[i][CC[i].size() - 1];
        int n2 = CC[i+1][0];
        viz[n1] = viz[n2] = 1;
        edges.push_back({n1, n2});
    }

    // cauta in toata matricea de comp conex si nodurile izolate le baga in remains
    for ( int i = 1; i <= nrCC; ++ i ) {
        for ( auto p : CC[i] ) {
            if ( !viz[p] ) {
                remains.push_back(p);
            }
        }
    }
    
    //daca is mai putine noduri izolate decat norudi ramase pentru legatura, atunci se poot forma legaturi
    //astefl incat max sa ramana 1
    if ( isolated.size() <= remains.size() ) {
        for ( int i = 0; i < isolated.size() ; ++ i ) {
            int n1 = isolated[i];
            int n2 = remains[i];
            edges.push_back({n1, n2});
        }
        maxExtra = 1;
    }

    //altfel le leaga cat de mult se poate pe cele singure
    //apoi le leaga si de ele cu mai multe noduri in comp conexa
    else {
        for ( int i = 0; i < isolated.size() - 1; ++ i ) {
            int n1 = isolated[i];
            int n2 = isolated[i+1];
            edges.push_back({n1, n2});
        }
        //daca au ramas noduri izolate sau daca mai is noduri care nu s au legat atunci max este 2
        maxExtra = 1 + ( isolated.size() != 2 || remains.size() != 0 );
        if ( remains.size() != 0 ) {
            edges.push_back({isolated[0], remains[0]});
        }
    }

    fout << maxExtra << '\n';
    fout << edges.size() << '\n';
    for ( auto e : edges ) {
        fout << e.first << " " << e.second << '\n';
    }
    
    return 0;
}
