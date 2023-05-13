#include <bits/stdc++.h>
using namespace std;
const int nmax=100005;
struct cojo
{
    int ind,val;
};
int v[nmax],D[nmax],S[nmax],d[nmax],s[nmax];
long long ansv[nmax];
cojo inalt[nmax];
vector<int> pp;
set<int>pp2;
bool cmp(cojo a,cojo b)
{
    return a.val>b.val;
}
int main()
{
    freopen("turnuri4.in", "r", stdin);
    freopen("turnuri4.out", "w", stdout);
    int n,i;
    long long maxim=0;
    scanf("%d",&n);
    for(i=1;i<=n;++i)
    {
        scanf("%d",&v[i]);
        inalt[i].ind=i;
        inalt[i].val=v[i];
    }
    sort(inalt+1,inalt+n+1,cmp);
    pp.push_back(0);
    pp.push_back(n+1);
    pp2.insert(0);
    pp2.insert(n+1);
    for(i=1;i<=n;++i)
    {
        ///caut ind al elem
        //1
        /*int st=0,dr=pp.size()-1,ans=-1;
        while(st<=dr)
        {
            int mid=st+(dr-st)/2;
            if(pp[mid]<=inalt[i].ind)
                ans=mid,st=mid+1;
            else
                dr=mid-1;
        }*/
        //2
        set<int>::iterator it1=pp2.lower_bound(inalt[i].ind);
        set<int>::iterator it2=pp2.lower_bound(inalt[i].ind);
        it1--;
//        printf("%d=>%d\n",inalt[i].ind,inalt[i].ind-pp[ans]-1+pp[ans+1]-inalt[i].ind);
//        printf("%d=>%d\n",inalt[i].ind,*it2-*it1-1);
        ///fac vectoru
        //1
        /*maxim+=pp[ans+1]-pp[ans]-1;
        S[inalt[i].ind]=pp[ans];
        D[inalt[i].ind]=pp[ans+1];
        if(ans-1>=0)
            s[inalt[i].ind]=pp[ans-1];
        else
            s[inalt[i].ind]=0;
        if(ans<=pp.size()-2)
            d[inalt[i].ind]=pp[ans+2];
        else
            d[inalt[i].ind]=n+1;
//        if(pp[ans]!=0)
//            ansv[pp[ans]]++;
//        if(pp[ans]!=n+1)
//            ansv[pp[ans+1]]++;
//        ansv[inalt[i].ind]-=pp[ans+1]-pp[ans]-2;
        pp.insert(pp.begin()+ans+1,inalt[i].ind);//belimiai de insert in O(n)*/
        //2
        pp2.insert(inalt[i].ind);
        maxim+=*it2-*it1-1;
        S[inalt[i].ind]=*it1;
        D[inalt[i].ind]=*it2;
        if(*it1>0)
        {
            it1--;
            s[inalt[i].ind]=*it1;
        }
        else
            s[inalt[i].ind]=0;
        if(*it2<n+1)
        {
            it2++;
            d[inalt[i].ind]=*it2;
        }
        else
            d[inalt[i].ind]=n+1;
    }
//    printf("total %lld\n\n",maxim);
    for(i=1;i<=n;++i)
    {
        if(D[i]!=n+1)
            ansv[D[i]]+=d[i]-D[i];
        if(S[i]!=0)
            ansv[S[i]]+=S[i]-s[i];
    }
    for(i=1;i<=n;++i)
        printf("%lld\n",ansv[i]+maxim-D[i]+S[i]+2);
    return 0;
}