#include <cstdio>
using namespace std;
 
int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        long long int p,f,cnts,cntw,s,w,maxx=0;
        scanf("%lld%lld%lld%lld%lld%lld",&p,&f,&cnts,&cntw,&s,&w);
        for(long long int is=0,iw=0,ipl=0; is<=cnts; ++is)
            if(is*s<=p)
            {
                if((p-is*s)/w<=cntw)
                    iw=(p-is*s)/w;
                else
                    iw=cntw;
                if(s<w)
                {
                    if(s*(cnts-is)>=f)
                        ipl=f/s;
                    else
                        if((f-s*(cnts-is))/w<=cntw-iw)
                            ipl=(f-s*(cnts-is))/w+cnts-is;
                        else
                            ipl=cntw-iw+cnts-is;
                }
                else
                {
                    if(w*(cntw-iw)>=f)
                        ipl=f/w;
                    else
                        if((f-w*(cntw-iw))/s<=cnts-is)
                            ipl=(f-w*(cntw-iw))/s+cntw-iw;
                        else
                            ipl=cnts-is+cntw-iw;
                }
                if(maxx<is+iw+ipl)
                    maxx=is+iw+ipl;
            }
            printf("%lld\n",maxx);
    }
    return 0;
}