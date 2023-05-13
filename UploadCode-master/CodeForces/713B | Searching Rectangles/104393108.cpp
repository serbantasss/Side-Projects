#include <bits/stdc++.h>
using namespace std;
int n,x[4],ans[4];
bool chk(int ans[], int x[])
{
    return ans[0] >= x[0] && ans[1] >= x[1] && ans[2] <= x[2] && ans[3] <= x[3];
}
bool in()
{
    int res;
    printf("?");
    for(int i=0;i<4;++i)
        printf(" %d", x[i]);
    printf("\n");
    fflush(stdout);
    scanf("%d", &res);
    if (chk(ans, x))
        res--;
    return res;
}
void get()
{
    x[0] = x[1] = 1;
    x[2] = x[3] = n;
    for(int i=0;i<4;++i)
    {
        int l = 1,r=n;
        if (i > 1)
            l = x[i - 2];
        while (l < r)
        {
            int m = (l + r + (i < 2)) / 2;
            x[i] = m;
            if (in())
            {
                if (i < 2)
                    l = m;
                else
                    r = m;
            }
            else
            {
                if (i < 2)
                    r = m - 1;
                else
                    l = m + 1;
            }
        }
        x[i] = l;
    }
}
int main()
{
    scanf("%d", &n);
    get();
    for(int i=0;i<4;++i)
        ans[i] = x[i];
    get();
    printf("!");
    for(int i=0;i<4;++i)
        printf(" %d", ans[i]);
    for(int i=0;i<4;++i)
        printf(" %d", x[i]);
    printf("\n");
    fflush(stdout);
    return 0;
}