#include<cstring>
#include<iostream>
//#define min(a,b) a<b?a:b
#define INF 1000000007
using namespace std;
long long a,b;
long long mi;
long long min(long long a,long long b)
{
    return a<b?a:b;
}
int main()
{
    while(cin>>a>>b){
        if(a==0){
            cout<<"-"<<b*b<<endl;
            for(int i=0;i<b;i++) cout<<"x";
            cout<<endl;
        }
        else if(b<=1){
            cout<<a*a-b*b<<endl;
            for(int i=0;i<a;i++) cout<<"o";
            for(int i=0;i<b;i++) cout<<"x";
            cout<<endl;
        }
        else{
            long long ans=-(a+b)*(a+b);
            long long o,x;
            mi=min(a,b);
            for(long long i=1;i<=mi;i++){
                long long a1=(i-1)+(a-(i-1))*(a-(i-1));
                for(long long j=i-1;j<=i+1;j++){
                    if(j>0&&j<=b){
                        long long b1=(b/j)*(b/j)*(j-b%j)+(b/j+1)*(b/j+1)*(b%j);
                        long long s=a1-b1;
                        if(ans<s){
                            ans=s;
                            o=i,x=j;
                        }
                    }
                }
            }
            cout<<ans<<endl;
            if(o>=x){
                for(long long i=1;i<=o;i++){
                    long long len1,len2;
                    if(i==1) len1=a-(o-1);
                    else len1=1;
                    if(i<=b%x) len2=b/x+1;
                    else len2=b/x;
                    for(long long j=0;j<len1;j++) cout<<"o";
                    if(i<=x) for(long long j=0;j<len2;j++) cout<<"x";
                }
                cout<<endl;
            }
            else{
                for(long long i=1;i<=x;i++){
                    long long len1,len2;
                    if(i<=b%x) len2=b/x+1;
                    else len2=b/x;
                    if(i==1) len1=a-(o-1);
                    else len1=1;
                    for(long long j=0;j<len2;j++) cout<<"x";
                    if(i<=o) for(long long j=0;j<len1;j++) cout<<"o";
                }
                cout<<endl;
            }
        }
    }
}