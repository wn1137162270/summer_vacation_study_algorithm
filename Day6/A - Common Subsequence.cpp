#include<cstdio>
#include<cstring>

const int maxn=2000+10;

int dp[maxn][maxn]; 

int get_max(int x,int y)
{
	return x>y?x:y;
}

int main()
{
	int len1,len2;
	char c1[maxn],c2[maxn];
	while(scanf("%s %s",c1,c2)!=EOF)
	{
		len1=strlen(c1);
		len2=strlen(c2);
		memset(dp,0,sizeof(dp));
		for(int i=1;i<=len1;i++)
			for(int j=1;j<=len2;j++)
			{
				dp[i][j]=get_max(dp[i-1][j],dp[i][j-1]);
				if(c1[i-1]==c2[j-1])
					dp[i][j]=get_max(dp[i-1][j-1]+1,dp[i][j]);
			}
		printf("%d\n",dp[len1][len2]);
	}
	return 0;
}
