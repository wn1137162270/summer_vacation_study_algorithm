#include<cstdio>
#include<cmath>
#include<cstring>
#include<iomanip>
using namespace std;

const int maxn=1000+10;
const double INF=1e9+10;

double sf[maxn][maxn],w[maxn][maxn],dist[maxn];
int vis[maxn],fa[maxn];

int main()
{
	int n,q,x,start,end,f;
	double safe,min,ans;
	while(scanf("%d",&n)!=EOF)
	{
		for(int i=0;i<n;i++)
			for(int j=0;j<n;j++)
			{
				scanf("%lf",&sf[i][j]);
				if(sf[i][j]!=0)
					w[i][j]=-log10(sf[i][j]);
				else
					w[i][j]=INF;
			}
		scanf("%d",&q);
		for(int i=0;i<q;i++)
		{
			scanf("%d %d",&start,&end);
			ans=1;
			start--;
			end--;
			memset(vis,0,sizeof(vis));
			for(int j=0;j<n;j++)
			{
				dist[j]=INF;
				fa[j]=start;
			}
			dist[start]=0;
			for(int j=0;j<n;j++)
			{
				min=INF;
				for(int k=0;k<n;k++)
					if(!vis[k]&&dist[k]<min)
						min=dist[x=k];
				vis[x]=1;
				for(int k=0;k<n;k++)
					if(dist[x]+w[x][k]<dist[k])
					{
						dist[k]=dist[x]+w[x][k];
						fa[k]=x;
					}
			}
			if(dist[end]>=INF)
				printf("What a pity!\n");
			else
			{
				x=end;
				while(x!=start)
				{
					f=fa[x];
					ans*=sf[x][f];
					x=f;
				}
				printf("%.3lf\n",ans);
			}
		}
	}
	return 0;	
} 
