#include <bits/stdc++.h>
using namespace std;
int TR[100005][26],cnt[100005],viz[100005],KEY,n,m,len,ok;
char s[305];
void intrie(int nod, int poz, char cd)
{
	if (!viz[nod] && cd=='A')
        cnt[nod]++;
	viz[nod]=1;
	if (poz==len)
        return;
	if (!ok && TR[nod][s[poz]-'a']==0)
        return;
	if(TR[nod][s[poz]-'a']==0)
        TR[nod][s[poz]-'a']=++KEY;
    intrie(TR[nod][s[poz]-'a'],poz+1,cd);
}
int main()
{
	freopen("sub.in", "r", stdin);
	freopen("sub.out", "w", stdout);
	scanf("%d\n", &n);
	KEY=1;
	for (int i=1;i<=n;++i)
	{
		scanf("%s\n",s);
		len=strlen(s);
		if(i==1)
            ok=1;
        else
            ok=0;
		memset(viz,0,sizeof(viz));
		for(int j=0;j<len;++j)
			intrie(1,j,'A');
	}
	scanf("%d\n",&m);
	memset(viz,0,sizeof(viz));
	ok=0;
	for (int i=1;i<=m;++i)
    {
		scanf("%s\n",s);
		len=strlen(s);
		for(int j=0;j<len;++j)
			intrie(1,j,'B');
	}
	int ans=0;
	for(int i=1;i<=KEY;i++)
		if(cnt[i]==n && !viz[i])
            ans++;
	printf("%d",ans);
	return 0;

}