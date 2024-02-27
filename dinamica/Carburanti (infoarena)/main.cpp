#include <bits/stdc++.h>

using namespace std;

ifstream fin("carburanti.in");
ofstream fout("carburanti.out");

int R[105];
int dp[20005];
int N, C, T;
int maxx = INT_MIN;
int nr_recipiente[20005];

void solve()
{
    fin >> N >> C;
    memset(dp, 0, sizeof(dp));
    for ( int i = 1; i <= C; ++ i ) {
        nr_recipiente[i] = INT_MAX;
    } 
    nr_recipiente[0] = 0;
    maxx = INT_MIN;
    dp[0] = 1;
    for (int i = 1; i <= N; ++i)
    {
        fin >> R[i];
    }
    for (int i = 1; i <= N; ++i)
    {
        for (int j = C; j >= R[i]; j --)
        {
            if ( dp[ j- R[i]] == 1 ) {
                dp[j] = 1;
                nr_recipiente[j] = min(nr_recipiente[j], nr_recipiente[j-R[i]] + 1);
                maxx = max(maxx, j);
            }
        }
    }
    fout << maxx << ',' << nr_recipiente[maxx] << '\n';
}

int main()
{
    fin >> T;
    while (T--)
    {
        solve();
    }
    return 0;
}