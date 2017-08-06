#include<cstdio>
#include<cstring>
using namespace std;

const int maxn=100000+10;
const int maxm=11;

int pan[maxn][maxm],dp[maxn][maxm];

int get_max(int x,int y)
{
	return x>y?x:y;
}

int main()
{
	int n,loc,time,mt,ans;
	scanf("%d",&n);
	while(n)
	{
		mt=0;
		ans=0;
		memset(pan,0,sizeof(pan));
		memset(dp,0,sizeof(dp));
		for(int i=0;i<n;i++)
		{
			scanf("%d %d",&loc,&time);
			mt=get_max(mt,time);
			pan[time][loc]++;
		}
		for(int i=1;i<=mt;i++)
		{
			if(i==1)
			{
				dp[i][4]=pan[i][4];
				dp[i][5]=pan[i][5];
				dp[i][6]=pan[i][6];
			}
			else
			{
				for(int j=0;j<maxm;j++)
				{
					dp[i][j]=dp[i-1][j];
					if(j!=0)
						dp[i][j]=get_max(dp[i][j],dp[i-1][j-1]);
					if(j!=maxm-1)
						dp[i][j]=get_max(dp[i][j],dp[i-1][j+1]);
					dp[i][j]+=pan[i][j];
					//printf("%d ",dp[i][j]);
				}
			}
			//printf("\n");
		}
		for(int j=0;j<maxm;j++)
			ans=get_max(ans,dp[mt][j]);
		printf("%d\n",ans);
		scanf("%d",&n);	
	} 
	return 0;
}
