#include <bits/stdc++.h>
using namespace std;
char s[100005];
map<long long,long long> mp;
int main()
{
    freopen("eq4.in", "r", stdin);
    freopen("eq4.out", "w", stdout);
    int cer,a,b,n,i;
    long long e,x=0,y=0,z=0,t=0,sur=0,semn,ans=0;
    scanf("%d\n",&cer);
    scanf("%s%d%d%lld",s,&a,&b,&e);
    n=strlen(s);
    i=0;
    while(i<n)
    {
        if(s[i]=='+')
            semn=1;
        else
            semn=-1;
        long long ind=0;
        i++;
        while(isdigit(s[i]))
        {
            ind=ind*10+s[i]-'0';
            i++;
        }
        if(!isdigit(s[i-1]))
            ind=1;
        if(s[i]=='x')
            x+=semn*ind;
        if(s[i]=='y')
            y+=semn*ind;
        if(s[i]=='z')
            z+=semn*ind;
        if(s[i]=='t')
            t+=semn*ind;
        if(s[i]=='+' || s[i]=='-' || s[i]=='\0')
            sur+=semn*ind,i--;
        i++;
    }
    if(cer==1)
    {
        printf("%lld",x+y+z+t+sur);
        return 0;
    }
    /*printf("%lld %lld %lld %lld %lld\n",x,y,z,t,sur);
    vector<long long>v1;
    for(int i1=a;i1<=b;++i1)//x
        for(int i2=a;i2<=b;++i2)//y
            v1.push_back(e-x*i1-y*i2);
    sort(v1.begin(),v1.end());
    for(int i=0;i<v1.size();++i)
        printf("%lld ",v1[i]);
    printf("\n");
    vector<long long>v2;
    for(int i1=a;i1<=b;++i1)//z
        for(int i2=a;i2<=b;++i2)//t
            v2.push_back(z*i1+t*i2+sur);
    sort(v2.begin(),v2.end());
    for(int i=0;i<v2.size();++i)
        printf("%lld ",v2[i]);
    printf("\n");*/
    for(int i1=a;i1<=b;++i1)//x
        for(int i2=a;i2<=b;++i2)//y
            mp[e-x*i1-y*i2]++;
    for(int i1=a;i1<=b;++i1)//z
        for(int i2=a;i2<=b;++i2)//t
            ans+=mp[z*i1+t*i2+sur];
    printf("%lld",ans);
    return 0;
}