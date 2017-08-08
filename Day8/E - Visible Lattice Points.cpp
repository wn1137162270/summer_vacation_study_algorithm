#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;

const int maxn=1000+10;
bool vis[maxn][maxn];

int main()
{
	int c,n,num[maxn];
	scanf("%d",&c);
	memset(num,0,sizeof(num));
	memset(vis,false,sizeof(vis));
	vis[0][1]=true;
	for(int i=1;i<maxn;i++)
		vis[1][i]=true;
	for(int i=2;i<maxn;i++)
		for(int j=i;j<maxn;j++)
		{
			if(__gcd(i,j)==1)
				vis[i][j]=true;
		}
	for(int i=0;i<maxn;i++)
	{
		if(i>0)
			num[i]=num[i-1];
		for(int j=0;j<i;j++)
		{
			if(vis[j][i])
				num[i]+=2;		
		}
		if(i==1)
			num[i]++;
	}
	for(int i=0;i<c;i++)
	{
		scanf("%d",&n);
		printf("%d %d %d\n",i+1,n,num[n]);
	}
	return 0;	
} 
