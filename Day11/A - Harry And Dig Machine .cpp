#include<cstdio>
#include<cstring>
#include<cmath>
using namespace std;

const int maxn=50+5;
const int maxm=10;
const int INF=1<<30;

struct vertex
{
	int x,y;
};

int weight[maxm+1][maxm+1],dp[1<<(maxm+1)][maxm+1];
vertex v[maxm+1];

int get_min(int x,int y)
{
	return x<y?x:y;
}

int main()
{
	int n,m,num,t,ans;
	while(scanf("%d %d",&n,&m)!=EOF)
	{
		memset(dp,INF,sizeof(INF));
		num=0;
		for(int i=0;i<n;i++)
			for(int j=0;j<m;j++)
			{
				scanf("%d",&t);
				if((i==0&&j==0)||t>0)
				{
					v[num].x=i;
					v[num].y=j;
					num++;
				}
			}
		for(int i=0;i<num;i++)
		{
			for(int j=0;j<num;j++)
				weight[i][j]=abs(v[i].x-v[j].x)+abs(v[i].y-v[j].y);
		}
		for(int i=0;i<(1<<num);i++)
			for(int j=0;j<num;j++)
				dp[i][j]=INF;
		//memset(dp,INF,sizeof(dp));
//		for(int i=0;i<(1<<num);i++)
//			for(int j=0;j<num;j++)
//				printf("%d\n",dp[i][i]);
		dp[0][0]=0;
		for(int i=0;i<(1<<num);i++)
			for(int j=0;j<num;j++)
				if(dp[i][j]<INF)
					for(int k=0;k<num;k++)
						if((i&1<<k)==0)
							dp[i|1<<k][k]=get_min(dp[i|1<<k][k],dp[i][j]+weight[j][k]);
		ans=INF;
		for(int i=0;i<num;i++)
			ans=get_min(ans,dp[(1<<num)-1][i]+weight[i][0]);
		printf("%d\n",ans);
	}
	return 0;	
} 
