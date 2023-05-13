#include<cstdio>
#include<cctype>
#include<cstring>
#include<string>
using namespace std;
char s1[1005],s2[1005];
bool b1[1005],b2[1005];
int main()
{
    int n1,n2,i;
    gets(s1);
    n1=strlen(s1);
    gets(s2);
    n2=strlen(s2);
    if(n1!=n2)
    {
        printf("No");
        return 0;
    }
    for(i=0;i<n1;++i)
        if(s1[i]=='a'||s1[i]=='e'||s1[i]=='i'||s1[i]=='o'||s1[i]=='u')
            b1[i]=1;
        else
            b1[i]=0;
    for(i=0;i<n2;++i)
        if(s2[i]=='a'||s2[i]=='e'||s2[i]=='i'||s2[i]=='o'||s2[i]=='u')
            b2[i]=1;
        else
            b2[i]=0;
    for(i=0;i<n1;++i)
        if(b1[i]!=b2[i])
    {
        printf("No");
        return 0;
    }
    printf("Yes");
    return 0;
}