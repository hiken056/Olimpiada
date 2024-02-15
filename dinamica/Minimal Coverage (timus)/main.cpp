#include <bits/stdc++.h>

using namespace std;

const int MAXN = 5000;
int M;
vector <pair<int, int>>V;
vector <int> Sol;

int best[MAXN + 5];
int dp[MAXN + 5]; //nr de moduri prin care pot face perechi cu i capat/inceput


int main () {

    cin >> M;
    int a=1, b=1;
    while ( a !=  0 || b != 0 ) {
        cin >> a >> b;
        if ( (a != 0 || b != 0) && a >= 0 && b <= M )
            V.emplace_back(a, b);
    }
    sort(V.begin(), V.end());

    for ( const auto &it: V ) {
        tie(a, b) = it;
        if ( a == 0 ) {
            dp[b] = 1;
            best[b] = 0;
        }
        else if ( dp[a] ) {
            if(!dp[b])
                dp[b] = dp[a] + 1, 
                best[b] = a;
            else{
                if ( dp[a] + 1 <= dp[b])
                    best[b] = a;
                dp[b] = min(dp[b], dp[a] + 1);
            }
                
        }
    }
    if ( dp[M] == 0 ) {
        cout << "No solution";
        return 0;
    }
    cout << dp[M] << '\n';

    int x = M;
    while ( x != 0 ) {
        Sol.push_back(x);
        x = best[x];
    }   

    Sol.push_back(0);
    reverse(Sol.begin(), Sol.end());
    for ( int i = 1; i < Sol.size(); ++ i )
    {
        cout << Sol[i-1] << Sol[i] << "\n";
    }
    return  0;


}