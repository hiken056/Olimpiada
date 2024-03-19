#include <bits/stdc++.h>

#pragma optimize GCC ("Ofast")
#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")

///#include <tryhardmode>
///#include <GODMODE::ON>

using namespace std;

ifstream fin ("nestemate.in");
ofstream fout ("nestemate.out");

const int NMAX=1e6+5;
const int INF=2e9;

vector<int>v[NMAX];
int dist[NMAX];
bool viz[NMAX];

struct elem{
    int x;
    int y;
    int z;
}stone[NMAX];
int n;

void bfs(int a,int b)
{
    int i;
    queue<int>q;
    dist[a]=0;
    viz[a]=true;
    q.push(a);
    while(!q.empty())
    {
        int p=q.front();
        q.pop();
        for(auto i:v[p])
        {
            if(!viz[i])
            {
                dist[i]=dist[p]+1;
                viz[i]=true;
                q.push(i);
            }
        }
    }
    if(dist[b]==INF)
        fout<<-1<<"\n";
    else
        fout<<dist[b]/2<<"\n";
}

void solve()
{
    map<int,int>mp;
    int i,j,a,b,saiz=0;
    fin>>n>>a>>b;
    for(i=1;i<=n;i++)
    {
        int x,y,z;
        fin>>stone[i].x>>stone[i].y>>stone[i].z;
        mp[stone[i].x]++;
        mp[stone[i].y]++;
        mp[stone[i].z]++;
        for(auto j:mp)
        {
            v[i].push_back(j.first+n);
            v[j.first+n].push_back(i);
            saiz=max(saiz,j.first+n);
        }
        mp.clear();
    }
    for(i=1;i<=saiz;i++)
    {
        viz[i]=false;
        dist[i]=INF;
    }
    bfs(a,b);
    for(i=1;i<=saiz;i++)
    {
        viz[i]=false;
        dist[i]=INF;
        v[i].clear();
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    fin.tie(NULL);
    fout.tie(NULL);

    int t;
    fin>>t;
    while(t--)
    {
        solve();
    }
    return 0;
}