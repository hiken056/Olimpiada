#include <bits/stdc++.h>

using namespace std;

ifstream in("bellmanford.in");
ofstream out("bellmanford.out");

#define oo 1e9
#define MAXN 50005

int N, M;
vector<pair<int, int>> G[MAXN];
queue<int> Q;
bool ok = 1;
int viz[MAXN];
bool inQ[MAXN];
int dist[MAXN];

/*Se dă un graf orientat conex cu N noduri şi M muchii cu costuri. Definim un
 * lanţ ca fiind un şir de noduri cu proprietatea că între oricare două
 * consecutive există o muchie. Costul unui lanţ este dat de suma costurilor
 * muchiilor care unesc nodurile ce îl formează. Definim un ciclu ca fiind un
 * lanţ cu proprietatea că primul element al său este egal cu ultimul.*/
/**/
/*Cerinţă*/
/*Să se determine dacă în graful dat există un ciclu de cost negativ. Dacă nu
 * există, să se determine costul minim al unui lanţ de la nodul 1 la fiecare
 * dintre nodurile 2, 3, ... , N-1, N.*/
/**/
/*Date de intrare*/
/*Fişierul de intrare bellmanford.in conţine pe prima linie numerele N şi M cu
 * semnificaţia din enunţ. Pe următoarele M linii se vor afla câte 3 numere x, y
 * şi c cu semnificaţia că există o muchie de cost c de la nodul x la nodul y.*/
/**/
/*Date de ieşire*/
/*În fişierul de ieşire bellmanford.out se va afişa pe prima linie mesajul
 * "Ciclu negativ!" dacă în graf există un astfel de ciclu sau, în caz contrar,
 * N-1 numere separate printr-un spaţiu. Al i-lea număr va reprezenta costul
 * minim al unui lanţ de la nodul 1 la nodul i+1.*/
/**/
int main() {
  in >> N >> M;
  while (M--) {
    int x, y, c;
    in >> x >> y >> c;
    G[x].push_back({y, c});
  }
  for (int i = 1; i <= N; ++i) {
    dist[i] = oo;
  }
  dist[1] = 0;
  Q.push(1);
  inQ[1] = 1;

  while (!Q.empty() && ok == 1) {
    int nod = Q.front();
    Q.pop();
    inQ[nod] = 0;
    viz[nod]++;
    if (viz[nod] >= N) {
      ok = 0;
      break;
    }
    for (auto vecin : G[nod]) {
      if (dist[vecin.first] > dist[nod] + vecin.second) {
        dist[vecin.first] = dist[nod] + vecin.second;
        if (inQ[vecin.first] == 0) {
          Q.push(vecin.first);
          inQ[vecin.first] = 1;
        }
      }
    }
  }

  if (ok == 0)
    out << "Ciclu negativ!";
  else {
    for (int i = 2; i <= N; ++i) {
      out << dist[i] << " ";
    }
  }
  return 0;
}
