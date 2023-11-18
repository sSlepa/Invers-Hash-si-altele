#include<vector>
#include<cstring>
#include<stdio.h>
#define INF 10001
 
using namespace std;
 
vector<int> graph[INF];
int n,m,e;
int used[INF];//nodurile folosite intr-o iteratie
int match1[INF],match2[INF];//cuplajele realizate - in ambele sensuri
 
 
int match(int ind)
{
    if(used[ind])return 0;//daca a mai fost folosit in interatia curenta, ne intoarcem
    used[ind]=1;//il marcam ca fiind folosit
 
    for(vector<int>::iterator it=graph[ind].begin();it!=graph[ind].end();it++)
        if(match2[*it]==0)//incercam mai intai sa-l cuplam cu un nod adiacent liber
        {
            match1[ind]=*it;
            match2[*it]=ind;
            return 1;//daca reusim, ne intoarcem
        }
 
    for(vector<int>::iterator it=graph[ind].begin();it!=graph[ind].end();it++)
        if(match(match2[*it]))//inceram a doua oara sa eliberam un nod adiacent ocupat
        {
            match1[ind]=*it;
            match2[*it]=ind;
            return 1;//daca reusim sa eliberam un loc, il cuplam cu nodul curent
        }
 
    return 0;//daca nu reusim sa-l cuplam
}
 
int main()
{
    freopen("cuplaj.in","r",stdin);
    freopen("cuplaj.out","w",stdout);
 
    scanf("%d %d %d\n",&n,&m,&e);
 
    for(int i=0;i<e;++i)//citim graful
    {
        int x,y;
        scanf("%d %d\n",&x,&y);
        graph[x].push_back(y);
    }
 
    int wasChanged=1;
    while(wasChanged)//cat timp s-a facut o cuplare in iteratia anterioara => este posibil sa mai putem cupla ceva
    {
        wasChanged=0;
        memset(used,0,sizeof(used));//resetam used
 
        for(int i=1;i<=n;++i)
            if(!match1[i]) wasChanged+=match(i);//daca nodul curent nu e cuplat, incercam sa-l cuplam
    }
 
    int matches=0;
    for(int i=1;i<=n;i++)
        if(match1[i])matches++;//numaram cuplajele
 
    printf("%d\n",matches);
 
    for(int i=1;i<=n;i++)
            if(match1[i])printf("%d %d\n",i,match1[i]);//scriem cuplajele
}
