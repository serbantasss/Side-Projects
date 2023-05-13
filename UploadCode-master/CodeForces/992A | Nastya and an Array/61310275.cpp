#include <cstdio>
using namespace std;
int arr[200005];
int main()
{
    int n, x;
    scanf("%d",&n);
    int i=0, cnt=0;
    for(i=1; i<=n; i++)
    {
        scanf("%d",&x);
        arr[x+100000]++;
        if((x)==0);
        else if(arr[x+100000]>1);
        else
            cnt++;
    }
    printf("%d", cnt);
    return 0;
}