#include <fstream>
#include <algorithm>
using namespace std;
ifstream fin ("acoperire.in");
ofstream fout ("acoperire.out");
int nr,minst,maxdr,dist,maxim,q,t,n,i,st,dr,mij,k,v[100001];
pair <int,int> p[100001];
double stt,drr;
int f (int val,int ok)
{
    int nr=1;
    if (ok==1)
        p[nr]=make_pair (v[n]-val,v[n]);
    int poz=v[n]-val;
    for (i=n; i>0; i--)
    {
        if (v[i]<poz)
        {
            nr++;
            if (ok==1)
                p[nr]=make_pair (v[i]-val,v[i]);
            poz=v[i]-val;
        }
    }
    return nr;
}
void afis (int n)
{
    if (n<0)
    {
        n=-n;
        fout<<'-';
    }
    if (n%10==0)
        fout<<n/10<<" ";
    else
        fout<<n/10<<'.'<<n%10<<" ";
}
int main()
{
    fin>>n;
    minst=1e8;
    maxdr=-1;
    for (i=1; i<=n; i++)
    {
        fin>>st>>dr;
        st*=10;
        dr*=10;
        dist=max (dist,(dr-st)/2);
        minst=min (minst,st);
        maxdr=max (maxdr,dr);
        mij=(st+dr)/2;
        v[i]=mij;
    }
    sort (v+1,v+n+1);
    maxim=maxdr-minst;
    fin>>q;
    for (t=1; t<=q; t++)
    {
        fin>>k;
        st=dist;
        dr=maxim;
        while (st<=dr)
        {
            mij=(st+dr)/2;
            if (f (mij,0)>k)
                st=mij+1;
            else
                dr=mij-1;
        }
        nr=f (st,1);
        afis (st);
        fout<<"\n"<<nr<<"\n";
        for (i=nr; i>0; i--)
        {
            afis (p[i].first);
            afis (p[i].second);
            fout<<"\n";
        }
    }
    return 0;
}