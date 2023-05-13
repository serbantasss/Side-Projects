#include <cstdio>
#include <cstring>
char  sp[1001];
char ans[1001]; 
void Tonumber(int length)
{
 int i = 0;long long a = 0,b = 0;int temp = 1;
  while(sp[i]>='A'&&sp[i]<='Z')
 {
  a*=26;
  a+=(sp[i]-'A'+1);
  i++;
 }
 while(i<length)
 {
  b*=10;b+=(sp[i]-'0');
  i++;
 }
 printf("R"); 
 printf("%lld",b);
 printf("C");
 printf("%lld\n",a);
// memset(ans,0,sizeof(ans));
}
void Toexcle(int length)
{
 int i = 1;int a = 0,b = 0;
 while(sp[i]!='C')
 {
  if(i==length)
  {Tonumber(length);return ;
  }
  a*=10;a+=(sp[i]-'0');
  i++;
  
 }
 while(1)
 {
 i++;
 if(i>=length) break;
 b*=10;b+=(sp[i]-'0');
 } 
 int j = 0;int k1,k2;
 while(1)
 {
  k1 = b % 26;
  if(k1)
  ans[j]=(b%26)+'A'-1;
  else ans[j] = 'Z';
  b/=26;
  if(ans[j]=='Z')b--;
  if(!b)break;j++;
 } 
 k2 = strlen(ans);
 while(k2--)printf("%c",ans[k2]); 
 printf("%d\n",a);
 memset(ans,0,strlen(ans));
}
int main()
{
 int n,m;
 scanf("%d",&n);
 while(n--)
 {
  scanf("%s",&sp);
  m = strlen(sp);
  if(sp[0]=='R'&&sp[1]<'A')Toexcle(m);
        else Tonumber(m);
        memset(sp,0,m);
 }
 return 0; 
} 