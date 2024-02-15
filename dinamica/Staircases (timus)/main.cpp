#include <iostream>

using namespace std;
using ll = long long;
int N;

const int LIMN = 500;

ll dp[LIMN + 5][LIMN + 5]; //nr de moduri prin care pot face staircases cu B blocuri si ultima scara S



int main()
{
    cin >> N;
    for ( int i = 1; i <= N; ++ i) {
        dp[i][i] = 1;
    }
    for ( int s = 2; s <= N; ++ s) {
        for ( int l = 2; l < N; ++ l ) {
            for ( int c = 1; c < l; ++ c ) {
                if ( s- l < 0 ) continue;
                dp[s][l] += dp[s-l][c];
            }
        }
    }
    ll s = 0;
    for ( int i = 2; i < N; ++ i) {
        s += dp[N][i];
    }
    cout << s;
    return 0;
}