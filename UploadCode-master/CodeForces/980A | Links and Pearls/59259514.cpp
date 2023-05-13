#include <bits/stdc++.h>
 
using namespace std;
int main()
{
    char ch;
    int l,o;
    l=o=0;
    while(1)
    {
        scanf("%c",&ch);
        if(ch=='\n')
            break;
        if(ch=='-')
            l++;
        else
            o++;
    }
    if(o==0 ||o==1 || l==0)
        printf("YES");
    else
        if(o>l)
            printf("NO");
        else
            if(l%o==0)
                printf("YES");
            else
                printf("NO");
    return 0;
}