#include <fstream>

using namespace std;

ifstream fin("rmq.in");
ofstream fout("rmq.out");

const int MAXN = 1e5;

/*Se da un vector cu N elemente. Scrieti un program care raspunde la M intrebari
 * de tipul "Care este elementul minim din intervalul [x,y]?"*/
/**/
/*Date de intrare*/
/*Pe prima linie a fisierului rmq.in sunt date numerele N si M. Urmatoarele N
 * linii vor contine cate un numar reprezentand elementele vectorului.
 * Urmatoarele M linii vor contine cate 2 numere reprezentand valorile x si y
 * care definesc intrebarile.*/
/**/
/*Date de iesire*/
/*In fisierul de iesire rmq.out vor fi M linii, fiecare continand cate un numar,
 * pe linia i aflandu-se raspunsul pentru intrebarea i.*/
/**/
int N, M;
int rmq[MAXN + 5][17];
int p2[MAXN + 5]; // cea mai mare putere j pentru care 2^j <= i

int main() {
  fin >> N >> M;
  for (int i = 1; i <= N; ++i) {
    fin >> rmq[i][0];
  }

  p2[1] = 0;
  for (int i = 2; i <= N; ++i) {
    p2[i] = p2[i - 1];
    if (1 << (p2[i] + 1) <= i)
      p2[i]++;
  }

  for (int j = 1; (1 << j) <= N; ++j) {
    for (int i = 1; i <= N - (1 << j) + 1; ++i) {
      rmq[i][j] = min(rmq[i][j - 1], rmq[i + (1 << (j - 1))][j - 1]);
    }
  }

  while (M--) {
    int x, y;
    fin >> x >> y;
    int l = y - x + 1;
    fout << min(rmq[x][p2[l]], rmq[y + 1 - (1 << p2[l])][p2[l]]) << '\n';
  }
  return 0;
}
