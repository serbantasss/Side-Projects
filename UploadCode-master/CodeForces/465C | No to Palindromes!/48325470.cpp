#include <cstdio>
 
using namespace std;
int v[1005];
char s[1005];
int main()
{
    int n, p;
    scanf("%d%d\n%s",&n,&p,&s);
    for(int i=n-1;i>=0;--i)
    {
        for(int j=0;j<=p-1;++j)
        {
            char c = j + 'a';
            if(c > s[i])
            {
                if(i - 1 >= 0 && c == s[i - 1])
                    continue;
                if(i - 2 >= 0 && c == s[i - 2])
                    continue;
                s[i] = c;
                for(int k=i+1;k<=n-1;++k)
                {
                    for(int jj=0;jj<=p-1;++jj)
                    {
                        char cc = jj + 'a';
                        if(cc == s[k - 1])
                            continue;
                        if(cc == s[k - 2])
                            continue;
                        s[k] = cc;
                        break;
                    }
                }
                printf("%s\n",s);
                return 0;
            }
        }
    }
    printf("NO");
    return 0;
}