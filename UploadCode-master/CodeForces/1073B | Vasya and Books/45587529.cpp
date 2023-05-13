#include <cstdio>
#include <stack>
#include <vector>
#include <algorithm>
using namespace std;
bool f[200005];
stack<int>st;
vector<int>v;
int main()
{
    int n,i,j,k;
    scanf("%d",&n);
    for(i=1; i<=n; ++i)
    {
        scanf("%d",&k);
        v.push_back(k);
        f[k]=1;
    }
    for(i=n-1; i>=0; --i)
    {
        st.push(v[i]);
    }
    for(i=1; i<=n; ++i)
    {
        scanf("%d",&k);
        if(f[k]==0)
        {
            printf("0 ");
            continue;
        }
        if(!st.empty())
        {
            if(f[k]==0)
                printf("0 ");
            else
            {
                int cnt=0;
                while(st.top()!=k)
                {
                    f[st.top()]=0,cnt++;
                    st.pop();
                }
                f[k]=0;
                st.pop();
                printf("%d ",cnt+1);
            }
        }
    }
    return 0;
}