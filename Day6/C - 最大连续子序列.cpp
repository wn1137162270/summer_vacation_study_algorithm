#include<cstdio>
#include<cstring>

const int maxn=100000+10;
const int maxm=1000+10;
const int maxb=10+1;
const int INF=1<<30;

int dp[maxb][maxm],a[maxn],b[maxn],d[maxm],p[maxm];

int get_min(int x,int y)
{
	return x<y?x:y;
}

int main()
{
	int n,m;
	long long ans;
	while(scanf("%d %d",&n,&m)!=EOF)
	{
		ans=0;
		for(int i=0;i<n;i++)
			scanf("%d %d",&a[i],&b[i]);
		for(int i=0;i<m;i++)
			scanf("%d %d",&d[i],&p[i]);
		for(int k=0;k<maxb;k++)
		{
			dp[k][0]=0;
			for(int i=1;i<maxm;i++)
				dp[k][i]=INF;
		}
		for(int k=0;k<maxb;k++)
			for(int i=1;i<maxm;i++)
				for(int j=0;j<m;j++)
					if(p[j]>k)
					{
						if(i>=p[j]-k&&dp[k][i-p[j]+k]+d[j]<dp[k][i])
							dp[k][i]=dp[k][i-p[j]+k]+d[j];
						if(i<p[j]-k&&dp[k][0]+d[j]<dp[k][i])
							dp[k][i]=dp[k][0]+d[j];
					}
		for(int i=0;i<n;i++)
		{
			if(dp[b[i]][a[i]]==INF)
			{
				ans=-1;
				break;
			}
			else
				ans+=dp[b[i]][a[i]];
		}
		printf("%lld\n",ans);
	}
	return 0;
}
