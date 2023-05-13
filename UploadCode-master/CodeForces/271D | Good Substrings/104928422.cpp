#include <bits/stdc++.h>
using namespace std;
int sp[1505],f[30],ans;
char s[1505];
// TRIE
#define CHAR_SIZE 30
class Trie
{
public:
    bool isLeaf;
    Trie* character[CHAR_SIZE];
    
    // Constructor
    Trie()
    {
        this->isLeaf = false;
        
        for (int i = 0; i < CHAR_SIZE; i++)
        this->character[i] = nullptr;
    }
    void insert(std::string);
    bool search(std::string);
};
void Trie::insert(std::string key)
{
    // start from root node
    Trie* curr = this;
    for (int i = 0; i < key.length(); i++)
    {
        // create a new node if path doesn't exists
        if (curr->character[key[i]-'a'] == nullptr)
            curr->character[key[i]-'a'] = new Trie(),ans++;
        
        // go to next node
        curr = curr->character[key[i]-'a'];
        curr->isLeaf = true;
    }
    
    // mark current node as leaf
    curr->isLeaf = true;
}
int main()
{
    int n,k;
    Trie* tr= new Trie();
    gets(s);
    n=strlen(s);
    for(int i=1;i<=26;i++)
    scanf("%1d",&f[i]);
    scanf("%d",&k);
    for(int i=1;i<=n;++i)
    if(f[s[i-1]-'a'+1]==0)
        sp[i]=sp[i-1]+1;
    else
        sp[i]=sp[i-1];
    for(int i=1;i<=n;++i)
    {
        string ss;
        for(int j=i;j<=n;++j)
        {
            if(sp[j]-sp[i-1]>k)
                break;
            else
                ss+=s[j-1];
        }
        tr->insert(ss);
    }
    printf("%d",ans);
    return 0;
}