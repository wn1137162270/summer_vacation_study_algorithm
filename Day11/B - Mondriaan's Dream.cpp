#include<iostream>
#include<cstring>
using namespace std;

const int maxn=11;

long long dp[maxn+1][1<<maxn];
int n,m;

void dfs(int i,int j,int state,int next)
{
	if(j==m)
	{
		dp[i+1][next]+=dp[i][state];
		return ;
	}
	if((state&1<<j)>0)	
		dfs(i,j+1,state,next);
	else 
	{
		dfs(i,j+1,state,next|(1<<j));
		if(j+1<m&&((state&1<<(j+1))==0))
			dfs(i,j+2,state,next);
	}
}

int main()
{
	cin>>n>>m;
	while(n!=0||m!=0)
	{
		memset(dp,0,sizeof(dp));
		dp[0][0]=1;
		for(int i=0;i<n;i++)
			for(int j=0;j<(1<<m);j++)
				if(dp[i][j])
					dfs(i,0,j,0);
		cout<<dp[n][0]<<endl;
		cin>>n>>m;
	}
	return 0;
}
