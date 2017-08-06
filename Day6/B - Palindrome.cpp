#include<cstdio>
#include<cstring>

const int maxn=5000+10;

int dp[maxn][maxn];

int get_max(int x,int y)
{
	return x>y?x:y;
}

int get_min(int x,int y)
{
	return x<y?x:y;
}

int main()
{
	int n,len,max=0,ans;
	char s[maxn],c[maxn];
	scanf("%d",&n);
	scanf("%s",s);
	len=strlen(s);
	for(int i=0;i<len;i++)
		c[len-1-i]=s[i];
	c[len]=0;
	memset(dp,0,sizeof(dp));
	for(int i=1;i<=len;i++)
		for(int j=1;j<=len;j++)
		{
			dp[i][j]=get_max(dp[i-1][j],dp[i][j-1]);
			if(s[i-1]==c[j-1])
				dp[i][j]=get_max(dp[i-1][j-1]+1,dp[i][j]);
		}
	for(int i=0;i<=len;i++)
		max=get_max(max,dp[i][len-i]);
	ans=len-2*max;
	max=0;
	for(int i=0;i<=len;i++)
		if(len-i-1>=0)
			max=get_max(max,dp[i][len-i-1]);
	ans=get_min(ans,len-1-2*max);
	printf("%d\n",ans);
	return 0;	
} 
